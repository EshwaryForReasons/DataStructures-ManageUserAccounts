
#pragma once

#include "DateTime.h"

#include <iostream>

using namespace std;

class Login
{
public:

	Login() = default;
	Login(int _user_id, string _username, string _password, DateTime _login_date_time, DateTime _logout_date_time);
	~Login() = default;

	void set_user_id(int new_user_id);
	void set_username(string new_username);
	void set_password(string new_password);

	void set_login_date_time(DateTime new_login_date_time);
	void set_logout_date_time(DateTime new_logout_date_time);

	int get_user_id();
	string get_username();
	string get_password();

	DateTime get_login_date_time();
	DateTime get_logout_date_time();

	bool operator==(const Login&) const;
	bool operator!=(const Login&) const;
	bool operator>(const Login&) const;
	bool operator<(const Login&) const;
	bool operator>=(const Login&) const;
	bool operator<=(const Login&) const;

private:

	int user_id;
	string username;
	string password;

	DateTime login_date_time;
	DateTime logout_date_time;
};
