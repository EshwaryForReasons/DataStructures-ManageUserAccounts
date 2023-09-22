
#pragma once

#include "Menu.h"

const string USERS_DATA = "users_data.csv";

enum LOGIN_MENU_OPTION {
	LOGIN_MENU_LOGIN = '1',
	LOGIN_MENU_CREATE = '2',
	LOGIN_MENU_RESET = '3',
	LOGIN_MENU_EXIT = 'x'
};

class LoginMenu : public Menu
{
public:

	LoginMenu();

	bool authenticate();
	bool create();
	bool remove();
	bool reset();
	bool doLogin();
	bool doLogout();

private:

	fstream inFile;
	User login;
	vector<User> list;
	void initUserData();
};

