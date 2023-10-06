
#include "LoginMenu.h"
#include "Utils.h"

#include <sstream>
#include <thread>

const string USERS_DATA = "users_data.csv";

LoginMenu::LoginMenu()
	: Menu("Login Menu")
{
	add_option("Login");
	add_option("Logout");
	add_option("Create Account");
	add_option("Remove Account");
	add_option("Reset Password");
	add_option("Exit");

	init_user_data();
}

void LoginMenu::init_user_data()
{
	user_list.clear();

	ifstream in_file(USERS_DATA);

	// Placeholder variables for data in the file
	string id;
	string username;
	string password;
	string read_login_date_time;
	string read_logout_date_time;
	string line = "";

	//Construct a User and put it in the user_list for every user in the file
	while (getline(in_file, line))
	{
		stringstream ss(line);
		getline(ss, id, ',');
		getline(ss, username, ',');
		getline(ss, password, ',');
		getline(ss, read_login_date_time, ',');
		getline(ss, read_logout_date_time, ',');

		User login(stoi(id), username, password, DateTime(read_login_date_time), DateTime(read_logout_date_time));
		user_list.push_back(login);
	}

	in_file.close();
}

void LoginMenu::update_user_data_file(const User& update_user, bool b_append)
{
	fstream file(USERS_DATA, b_append ? ios::app : ios::out);

	if (b_append)
		file << update_user.get_user_id() << "," << update_user.get_username() << "," << update_user.get_password() << "," << update_user.get_login_date_time().to_string() << "," << update_user.get_logout_date_time().to_string() << "\n";
	else
	{
		//For all users write to file in format userid,username,password,login_date_time,logout_date_time; for user being logged out, use current time as logout_date_time
		for (const User& _user : user_list)
		{
			if (_user == update_user)
				file << update_user.get_user_id() << "," << update_user.get_username() << "," << update_user.get_password() << "," << update_user.get_login_date_time().to_string() << "," << update_user.get_logout_date_time().to_string() << "\n";
			else
				file << _user.get_user_id() << "," << _user.get_username() << "," << _user.get_password() << "," << _user.get_login_date_time().to_string() << "," << _user.get_logout_date_time().to_string() << "\n";
		}
	}

	file.close();

	//Update user_list after modifying the file
	init_user_data();
}

bool LoginMenu::authenticate()
{
	bool valid = false;

	//Iterates through all users and sees if any match the current username and password
	for (User _user : user_list)
	{
		//Check if username and password both match
		if ((user.get_username() == _user.get_username()) && (user.get_password() == _user.get_password()))
		{
			//If username and password match then update other user info as well
			user.set_logged_in(true);
			user.set_user_id(_user.get_user_id());
			user.set_login_date_time(get_current_time());
			//Technically represents previous logout date time as user is currently logged in
			user.set_logout_date_time(_user.get_logout_date_time());

			valid = true;
			break;
		}
	}

	return valid;
}

bool LoginMenu::login()
{
	cout << "***** Login *****" << endl;

	if (user.get_logged_in())
	{
		cout << "A user is already logged in! Please log out logged in user to continue!" << endl;
		return false;
	}

	int attempt = 0;

	//Loop allows user three attempts at inputting a correct username and password
	while (attempt++ < 3)
	{
		string username;
		string password;

		cout << "Username: ";
		cin >> username;
		cout << "Password: ";
		cin >> password;
		cout << endl;

		//Temporarily sets username and password; will be sent to authenticate
		user.set_username(username);
		user.set_password(password);

		if (authenticate())
		{
			//Update user in file
			update_user_data_file(user);
			return true;
		}
		else
		{
			//If username and password were incorrect then clear username and password in user as cleanup
			user.set_username("");
			user.set_password("");

			cout << "Login failed! Try again." << endl;
		}
	}

	return false;
}

bool LoginMenu::logout()
{
	//Ensure user is logged in
	if(!user.get_logged_in())
		return false;

	//Retrieve current time from system to update logout time
	user.set_logout_date_time(get_current_time());
	update_user_data_file(user);

	//Clear all data
	user.set_logged_in(false);
	user.set_user_id(0);
	user.set_username("");
	user.set_password("");
	user.set_login_date_time(DateTime());
	user.set_logout_date_time(DateTime());	

	return true;
}

bool LoginMenu::create_account()
{
	cout << "***** Create Account *****" << endl;

	string username;
	string password;

	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;

	//Get largest user id
	int largest_user_id = 0;
	for (const User& _user : user_list)
	{
		if(_user.get_user_id() > largest_user_id)
			largest_user_id = _user.get_user_id();
	}

	update_user_data_file(User(largest_user_id + 1, username, password, DateTime(), DateTime()), true);

	return true;
}

bool LoginMenu::remove_account()
{
	if (!user.get_logged_in())
	{
		cout << "No user logged in to remove!" << endl;
		return false;
	}

	//Remove user from the user_list
	user_list.erase(find(user_list.begin(), user_list.end(), user));
	//Update file to match user_list; user paramater is just to fill the space, passing in User() would construct a new object so I pass in the old user as an optimization
	update_user_data_file(user);

	//Logout the current user now that we have removed them
	logout();

	return true;
}

bool LoginMenu::reset_password()
{
	int attempt = 0;

	cout << "***** Reset Password *****" << endl;

	if (!user.get_logged_in())
	{
		cout << "No user logged in to reset password for!" << endl;
		return false;
	}

	//Loop allows user three attempts at inputting the same password twice; we require a password and a confirmation password before changing it
	while (attempt++ < 3)
	{
		string new_password;
		string confirm_new_password;

		cout << "New Password: ";
		cin >> new_password;
		cout << "Confirm New Password: ";
		cin >> confirm_new_password;
		cout << endl;

		if (new_password == confirm_new_password)
		{
			user.set_password(new_password);
			update_user_data_file(user);
			return true;
		}
		else
			cout << "Passwords do not match! Try again." << endl;
	}

	return true;
}

void LoginMenu::display_data() const
{
	if (user.get_logged_in())
	{
		cout << "\n";
		cout << "Current User: " << user.get_username() << endl;
		cout << "Login Time: " << user.get_login_date_time().to_string() << endl;
	}
}

const User& LoginMenu::get_user() const
{
	return user;
}
