
#define _CRT_SECURE_NO_WARNINGS // supress localtime warning

#include "Utils.h"
#include "DateTime.h"

#include <fstream>
#include <ctime>
#include <sstream>

void get_current_time(int& mo, int& d, int& yr, int& hr, int& min, int& sec)
{
	time_t t = std::time(0);
	tm* now = localtime(&t);

	mo = now->tm_mon + 1;
	d = now->tm_mday;
	yr = now->tm_year + 1900;

	hr = now->tm_hour;
	min = now->tm_min;
	sec = now->tm_sec;
}

DateTime get_current_time()
{
	int month;
	int day;
	int year;
	int hour;
	int minute;
	int second;
	get_current_time(month, day, year, hour, minute, second);
	return DateTime(hour, minute, second, day, month, year);
}