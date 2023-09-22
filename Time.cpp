
#include "Time.h"

Time::Time(int _hour, int _minute, int _second)
{
	hour = _hour;
	minute = _minute;
	second = _second;
}

void Time::set_hour(int new_hour)
{
	hour = new_hour;
}

void Time::set_minute(int new_minute)
{
	minute = new_minute;
}

void Time::set_second(int new_second)
{
	second = new_second;
}

int Time::get_hour() const
{
	return hour;
}

int Time::get_minute() const
{
	return minute;
}

int Time::get_second() const
{
	return second;
}
