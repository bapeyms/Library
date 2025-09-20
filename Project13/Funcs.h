#pragma once
#include "Book.h"
#include "Person.h"
#include "Library.h"
#include <iostream>
using namespace std;

enum Menu
{
	SHOW_ALL_BOOKS = 1,
	ADD_BOOK = 2,
	SELECT_BOOK = 3,
	EXIT = 0
};

int MenuChoice(int menuNumber)
{
	int menuChoice;
	cout << "Enter the menu number to perform a desired action" << endl;
	cout << "Number: ";
	cin >> menuChoice;
	cin.ignore(1000, '\n');
	while (menuChoice < 0 || menuChoice > menuNumber)
	{
		cout << "Enter a number from 0 to " << menuNumber << "!" << endl;
		cout << "Number: ";
		cin >> menuChoice;
		cin.ignore(1000, '\n');
	}
	cout << endl;
	return menuChoice;
}

void AddNewBook(Library& library)
{
	const int N = 256;
	char title[N];
	char author[N];
	bool status;

	cout << "Enter title: ";
	cin.getline(title, N);

	cout << "Enter author: ";
	cin.getline(author, N);

	cout << "Status (1 - in stock, 0 - issued to reader): ";
	cin >> status;
	cin.ignore(1000, '\n');
	Book newBook(title, author, status);
	library.AddBookToTheLibrary(newBook);
	cout << "New book is successfully entered!" << endl;
}