
#include "LoginMenu.h"

LoginMenu::LoginMenu()
	: Menu("Login Menu") {
	addOption("1) Login");
	addOption("2) Create Account");
	addOption("3) Remove Account");
	addOption("4) Reset Password");
	addOption("x) Exit");
	initUserData();
}
void LoginMenu::initUserData() {
	fstream inFile;
	openFile(inFile, USERS_DATA);
	// Placeholder variables for data in the file
	string id;
	string username;
	string password;
	string loginDateTime;
	string logoutDateTime;
	string line = "";
	while (getline(inFile, line)) {
		stringstream ss(line);
		getline(ss, id, ',');
		getline(ss, username, ',');
		getline(ss, password, ',');
		getline(ss, loginDateTime, ',');
		getline(ss, logoutDateTime, ',');
		User login;
		login.setId(stoi(id)); // convert from
		strong integer
			login.setUsername(username);
		login.setPassword(password);
		login.setLoginDateTime(loginDateTime); // DateTime
		login.setLogoutDateTime(logoutDateTime); // DateTime
		list.push_back(login);
	}
	inFile.close();
}
bool LoginMenu::authenticate() {
	bool valid = false;
	for (int i = 0; i < (int)list.size(); i++) {
		if (login.getUsername() == list.at(i).getUsername() &&
			login.getPassword() == list.at(i).getPassword()) {
			int mo = 0, d = 0, yr = 0, hr = 0, min = 0, sec = 0;
			getCurrentTime(mo, d, yr, hr, min, sec);
			// TODO set loginDateTime
			valid = true;
			break;
		}
	}
	return valid;
}
bool LoginMenu::doLogin() {
	int attempt = 0;
	do {
		string username, password;
		cout << "Username: ";
		cin >> username;
		cout << "Password: ";
		cin >> password;
		login.setUsername(username);
		login.setPassword(password);
		cout << endl;
		if (authenticate()) {
			return true;
		}
	} while (++attempt < 3);
	return false;
}
bool LoginMenu::create() {
	cout << "Todo create" << endl;
	return true;
}
bool LoginMenu::remove() {
	cout << "Todo Remove" << endl;
	return true;
}
bool LoginMenu::reset() {
	cout << "Todo Reset" << endl;
	return true;
}
bool LoginMenu::doLogout() {
	cout << "Todo Logout" << endl;
	int mo = 0, d = 0, yr = 0, hr = 0, min = 0, sec = 0;
	getCurrentTime(mo, d, yr, hr, min, sec);
	// TODO set logoutDateTime
	return true;
}