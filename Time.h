
#pragma once

#include <string>

using namespace std;

class Time
{
public:

	Time() = default;
	Time(int _hour, int _minute, int _second)
		: hour(_hour)
		, minute(_minute)
		, second(_second)
	{}
	~Time() = default;

	void set_hour(int new_hour);
	void set_minute(int new_minute);
	void set_second(int new_second);

	int get_hour() const;
	int get_minute() const;
	int get_second() const;

	virtual const string to_string() const;

private:

	int hour;
	int minute;
	int second;
};