
#pragma once

#include "Menu.h"
#include "User.h"

#include <fstream>

enum LOGIN_MENU_OPTION : uint8_t
{
	LOGIN_NONE,
	LOGIN_MENU_LOGIN,
	LOGIN_MENU_LOGOUT,
	LOGIN_MENU_CREATE,
	LOGIN_MENU_REMOVE,
	LOGIN_MENU_RESET,
	LOGIN_MENU_EXIT
};

class LoginMenu : public Menu
{
public:

	LoginMenu();

	//Validates username and password based on user_list
	bool authenticate();

	//Login using a valid user in user_list
	bool login();
	//Logout currently logged in user
	bool logout();
	//Prompts user to create a user
	bool create_account();
	//Removes the logged in user
	bool remove_account();
	//Resets password for logged in user
	bool reset_password();

	const User& get_user() const;

protected:

	virtual void display_data() const override;

private:

	//Represents current user
	User user;
	//Represents dataset of all users in database; read from users_data file
	vector<User> user_list;

	//Called when menu is constructed to initialize user_list from users_data file
	void init_user_data();

	//Called to update users_data file. The passed in user will be updated in the file, the rest will be reconstructed in place
	void update_user_data_file(const User& update_user, bool b_append = false);
};

