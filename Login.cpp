
#include "Login.h"

Login::Login(int _user_id, string _username, string _password, DateTime _login_date_time, DateTime _logout_date_time)
{
	user_id = _user_id;
	username = _username;
	password = _password;

	login_date_time = _login_date_time;
	logout_date_time = _logout_date_time;
}

void Login::set_user_id(int new_user_id)
{
	user_id = new_user_id;
}

void Login::set_username(string new_username)
{
	username = new_username;
}

void Login::set_password(string new_password)
{
	password = new_password;
}

void Login::set_login_date_time(DateTime new_login_date_time)
{
	login_date_time = new_login_date_time;
}

void Login::set_logout_date_time(DateTime new_logout_date_time)
{
	logout_date_time = new_logout_date_time;
}

int Login::get_user_id()
{
	return user_id;
}

std::string Login::get_username()
{
	return username;
}

std::string Login::get_password()
{
	return password;
}

DateTime Login::get_login_date_time()
{
	return login_date_time;
}

DateTime Login::get_logout_date_time()
{
	return logout_date_time;
}

bool Login::operator>(const Login& other) const
{
	return (login_date_time.get_year() > other.login_date_time.get_year()) 
		&& (login_date_time.get_month() > other.login_date_time.get_month())
		&& (login_date_time.get_day() > other.login_date_time.get_day())
		&& (login_date_time.get_hour() > other.login_date_time.get_hour())
		&& (login_date_time.get_minute() > other.login_date_time.get_minute())
		&& (login_date_time.get_second() > other.login_date_time.get_second());
}

bool Login::operator<(const Login& other) const
{
	return (login_date_time.get_year() < other.login_date_time.get_year())
		&& (login_date_time.get_month() < other.login_date_time.get_month())
		&& (login_date_time.get_day() < other.login_date_time.get_day())
		&& (login_date_time.get_hour() < other.login_date_time.get_hour())
		&& (login_date_time.get_minute() < other.login_date_time.get_minute())
		&& (login_date_time.get_second() < other.login_date_time.get_second());
}

bool Login::operator<=(const Login& other) const
{
	return (login_date_time.get_year() <= other.login_date_time.get_year())
		&& (login_date_time.get_month() <= other.login_date_time.get_month())
		&& (login_date_time.get_day() <= other.login_date_time.get_day())
		&& (login_date_time.get_hour() <= other.login_date_time.get_hour())
		&& (login_date_time.get_minute() <= other.login_date_time.get_minute())
		&& (login_date_time.get_second() <= other.login_date_time.get_second());
}

bool Login::operator>=(const Login& other) const
{
	return (login_date_time.get_year() >= other.login_date_time.get_year())
		&& (login_date_time.get_month() >= other.login_date_time.get_month())
		&& (login_date_time.get_day() >= other.login_date_time.get_day())
		&& (login_date_time.get_hour() >= other.login_date_time.get_hour())
		&& (login_date_time.get_minute() >= other.login_date_time.get_minute())
		&& (login_date_time.get_second() >= other.login_date_time.get_second());
}

bool Login::operator!=(const Login& other) const
{
	return user_id != other.user_id;
}

bool Login::operator==(const Login& other) const
{
	return user_id == other.user_id;
}
