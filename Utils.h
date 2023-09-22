
#pragma once

#include <fstream>
#include <string>

using namespace std;

void open_file(fstream& _in_file, string _file_name);

//Returns the system time
void get_current_time(int& mo, int& d, int& yr, int& hr, int& min, int& sec);