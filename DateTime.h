
#pragma once

#include "Time.h"

class DateTime : public Time
{
public:

	DateTime() = default;
	DateTime(int _day, int _month, int _year);
	~DateTime() = default;

	void set_day(int new_day);
	void set_month(int new_month);
	void set_year(int new_year);

	int get_day() const;
	int get_month() const;
	int get_year() const;

private:

	int day;
	int month;
	int year;
};

