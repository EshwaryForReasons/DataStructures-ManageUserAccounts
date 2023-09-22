
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
	
	void addOption(string option);

	int doMenu() const;
	int doMenuIndex() const;
	char doMenuOption() const;

	bool hasOption() const
	{
		return options.size() > 0;
	};

private:

	void display() const;
	void displayPrefixIndex() const;

	string name;
	vector<string> options;
};

