
#include "User.h"

void User::set_user_id(int new_user_id)
{
	user_id = new_user_id;
}

void User::set_username(string new_username)
{
	username = new_username;
}

void User::set_password(string new_password)
{
	password = new_password;
}

void User::set_login_date_time(DateTime new_login_date_time)
{
	login_date_time = new_login_date_time;
}

void User::set_logout_date_time(DateTime new_logout_date_time)
{
	logout_date_time = new_logout_date_time;
}

void User::set_logged_in(bool b_new_logged_in)
{
	b_logged_in = b_new_logged_in;
}

const int User::get_user_id() const
{
	return user_id;
}

const string User::get_username() const
{
	return username;
}

const string User::get_password() const
{
	return password;
}

const DateTime User::get_login_date_time() const
{
	return login_date_time;
}

const DateTime User::get_logout_date_time() const
{
	return logout_date_time;
}

bool User::get_logged_in() const
{
	return b_logged_in;
}

bool User::operator>(const User& other) const
{
	return (login_date_time.get_year() > other.login_date_time.get_year())
		&& (login_date_time.get_month() > other.login_date_time.get_month())
		&& (login_date_time.get_day() > other.login_date_time.get_day())
		&& (login_date_time.get_hour() > other.login_date_time.get_hour())
		&& (login_date_time.get_minute() > other.login_date_time.get_minute())
		&& (login_date_time.get_second() > other.login_date_time.get_second());
}

bool User::operator<(const User& other) const
{
	return (login_date_time.get_year() < other.login_date_time.get_year())
		&& (login_date_time.get_month() < other.login_date_time.get_month())
		&& (login_date_time.get_day() < other.login_date_time.get_day())
		&& (login_date_time.get_hour() < other.login_date_time.get_hour())
		&& (login_date_time.get_minute() < other.login_date_time.get_minute())
		&& (login_date_time.get_second() < other.login_date_time.get_second());
}

bool User::operator<=(const User& other) const
{
	return (login_date_time.get_year() <= other.login_date_time.get_year())
		&& (login_date_time.get_month() <= other.login_date_time.get_month())
		&& (login_date_time.get_day() <= other.login_date_time.get_day())
		&& (login_date_time.get_hour() <= other.login_date_time.get_hour())
		&& (login_date_time.get_minute() <= other.login_date_time.get_minute())
		&& (login_date_time.get_second() <= other.login_date_time.get_second());
}

bool User::operator>=(const User& other) const
{
	return (login_date_time.get_year() >= other.login_date_time.get_year())
		&& (login_date_time.get_month() >= other.login_date_time.get_month())
		&& (login_date_time.get_day() >= other.login_date_time.get_day())
		&& (login_date_time.get_hour() >= other.login_date_time.get_hour())
		&& (login_date_time.get_minute() >= other.login_date_time.get_minute())
		&& (login_date_time.get_second() >= other.login_date_time.get_second());
}

bool User::operator!=(const User& other) const
{
	return user_id != other.user_id;
}

bool User::operator==(const User& other) const
{
	return user_id == other.user_id;
}
