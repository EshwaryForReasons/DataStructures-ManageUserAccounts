/******************************
*
* Program Name: Lab 2 Manage User Accounts
* Author: Eshwary Mishra
* Date: 23 September 2023
* Description: This program manages user account provided by a file. It can update the file as account information changes.
*
*******************************/
#include "LoginMenu.h"

#include <thread>

using namespace std::chrono_literals;

int main()
{
	LoginMenu menu;

	bool b_exit = false;
	
	while (!b_exit)
	{
		system("cls");
		int selected_option = menu.display_menu();
		system("cls");

		if (selected_option == LOGIN_MENU_LOGIN)
		{
			if (menu.login())
				cout << "Logged in user " << menu.get_user().get_username() << " successfully!" << endl;
			else
				cout << "Login user failed!" << endl;
		}
		else if (selected_option == LOGIN_MENU_LOGOUT)
		{
			//Store username to display success or failure to user after information is cleared
			const string username = menu.get_user().get_username();

			if (menu.logout())
				cout << "Logged out user " << username << " successfully!" << endl;
			else
				cout << "Logged out user " << username << " failed!" << endl;
		}
		else if (selected_option == LOGIN_MENU_CREATE)
		{
			if (menu.create_account())
				cout << "User created successfully! You must log in manually." << endl;
		}
		else if (selected_option == LOGIN_MENU_REMOVE)
		{
			//Store username to display success or failure to user after information is cleared
			const string username = menu.get_user().get_username();

			if (menu.remove_account())
				cout << "User " << username << " removed successfully! The user has been logged out automatically." << endl;
		}
		else if (selected_option == LOGIN_MENU_RESET)
		{
			if (menu.reset_password())
				cout << "Password for user " << menu.get_user().get_username() << " reset successfully!" << endl;
		}
		else if (selected_option == LOGIN_MENU_EXIT)
		{
			//Logout any currently logged in user prior to exit
			menu.logout();

			cout << "Goodbye!" << endl;
			b_exit = true;
		}

		this_thread::sleep_for(3s);
	}

	return 0;
}