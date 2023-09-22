
#include "DateTime.h"

DateTime::DateTime(int _day, int _month, int _year)
{
	day = _day;
	month = _month;
	year = _year;
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
