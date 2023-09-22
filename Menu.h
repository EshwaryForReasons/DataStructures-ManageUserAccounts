
#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Menu
{
public:

	Menu() {};
	Menu(string _name);
	~Menu() = default;

	void set_name(string new_name)
	{
		name = new_name;
	}
	
	void add_option(string option);

	int display_menu() const;
	int display_menu_index() const;
	char display_menu_option() const;

	bool has_option() const
	{
		return options.size() > 0;
	};

private:

	void display() const;
	void display_prefix_index() const;

	string name;
	vector<string> options;
};

