
#include "Menu.h"

Menu::Menu(string _name)
{
	name = _name;
}
/**
* Add menu open name
*/
void Menu::add_option(string option)
{
	options.push_back(option);
}
/**
* Dipslay option nam
*/
void Menu::display() const
{
	cout << "***** " << name << " *****" << endl;
	for (int i = 0; i < (int)options.size(); i++)
	{
		cout << options[i] << endl;
	}
	cout << "\nEnter choice: ";
}
/**
* Display ordered index and option name
*/
void Menu::display_prefix_index() const
{
	cout << "***** " << name << " *****" << endl;
	for (int i = 0; i < (int)options.size(); i++)
	{
		cout << i + 1 << ") " << options[i] << endl;
	}
	cout << "\nEnter choice: ";
}
/**
* Display option menu, option name; and ask users to select a choice by index
*/
int Menu::display_menu_index() const
{
	char ch;
	int input = 0;
	do
	{
		display_prefix_index();
		cin >> ch;
		input = static_cast<int>(ch) - 48;
	} while (input < 1 || input >(int)options.size());
	return input;
}
/**
* Display option menu, option name; and ask users to select a choice
*/
int Menu::display_menu() const
{
	int input = 0;
	do {
		display();
		cin >> input;
	} while (input < 1 || input >(int)options.size());
	return input;
}
/**
* Display option menu, option name; and ask users to select a choice
*/
char Menu::display_menu_option() const
{
	char input;
	display();
	cin >> input;
	return input;
}