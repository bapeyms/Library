#include "Book.h"
#include "Person.h"
#include "Library.h"
#include <iostream>
using namespace std;

enum Menu
{
	SHOW_ALL_BOOKS = 1,
	ADD_BOOK = 2,
	EXIT = 0
};
int MenuChoice(int menuNumber)
{
	int menuChoice;
	cout << "Enter the menu number to perform a desired action" << endl;
	cout << "Number: ";
	cin >> menuChoice;
	cin.ignore(1000, '\n');
	while (menuChoice < 1 || menuChoice > menuNumber)
	{
		cout << "Enter a number from 0 to " << menuNumber << "!" << endl;
		cout << "Number: ";
		cin >> menuChoice;
		cin.ignore(1000, '\n');
	}
	return menuChoice;
}

int main()
{
	cout << "- LIBRARY -" << endl;
	int menuNumber = 2;

	int numberOfBooks = 7;
	

	while (true)
	{
		cout << "- LIBRARY MENU -" << endl;
		cout << "1. Show all books " << endl;
		cout << "2. Add a book" << endl;

		int menuChoice = MenuChoice(menuNumber);
		switch (menuChoice) {
		case SHOW_ALL_BOOKS:

		}
	}
	
}