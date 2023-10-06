
#include "Time.h"

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

const string Time::to_string() const
{
	return std::to_string(hour) + ":" + std::to_string(minute) + ":" + std::to_string(second);
}
