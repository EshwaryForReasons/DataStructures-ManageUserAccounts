
#pragma once

#include "DateTime.h"

#include <iostream>

using namespace std;

class User
{
public:

	User() = default;
	User(int _user_id, string _username, string _password, DateTime _login_date_time, DateTime _logout_date_time)
		: user_id(_user_id)
		, username(_username)
		, password(_password)
		, login_date_time(_login_date_time)
		, logout_date_time(_logout_date_time)
	{}
	~User() = default;

	void set_user_id(int new_user_id);
	void set_username(string new_username);
	void set_password(string new_password);

	void set_login_date_time(DateTime new_login_date_time);
	void set_logout_date_time(DateTime new_logout_date_time);

	void set_logged_in(bool b_new_logged_in);

	const int get_user_id() const;
	const string get_username() const;
	const string get_password() const;

	const DateTime get_login_date_time() const;
	const DateTime get_logout_date_time() const;

	bool get_logged_in() const;

	bool operator==(const User&) const;
	bool operator!=(const User&) const;
	bool operator>(const User&) const;
	bool operator<(const User&) const;
	bool operator>=(const User&) const;
	bool operator<=(const User&) const;

private:

	int user_id;
	string username;
	string password;

	DateTime login_date_time;
	DateTime logout_date_time;

	bool b_logged_in;
};
