
#include "DateTime.h"

#include <sstream>

DateTime::DateTime(const string& string_date_time)
{
	string _month;
	string _day;
	string _year;
	string _hour;
	string _minute;
	string _second;

	stringstream ss(string_date_time);
	getline(ss, _month, '/');
	getline(ss, _day, '/');
	getline(ss, _year, ' ');
	getline(ss, _hour, ':');
	getline(ss, _minute, ':');
	getline(ss, _second, ' ');

	set_hour(stoi(_hour));
	set_minute(stoi(_minute));
	set_second(stoi(_second));
	day = stoi(_day);
	month = stoi(_month);
	year = stoi(_year);
}

void DateTime::set_day(int new_day)
{
	day = new_day;
}

void DateTime::set_month(int new_month)
{
	month = new_month;
}

void DateTime::set_year(int new_year)
{
	year = new_year;
}

int DateTime::get_day() const
{
	return day;
}

int DateTime::get_month() const
{
	return month;
}

int DateTime::get_year() const
{
	return year;
}

const std::string DateTime::to_string() const
{
	return std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year) + " " + Time::to_string();
}
