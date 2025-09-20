#include "Book.h"
#include "Person.h"
#include "Library.h"
#include "Funcs.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "-- LIBRARY --" << endl << endl;
	int menuNumber = 2;
	Library myLib;
	Book book1("Notes Of A Crocodole", "Qie Miaojin", true);
	Book book2("Geungsi", "Sean Lam", true);
	Book book3("Soul Mountain", "Gao Xingjian", true);
	Book book4("The Jade King", "Huo Da", true);
	Book book5("We Do Not Part", "Han Kang", true);
	myLib.AddBookToTheLibrary(book1);
	myLib.AddBookToTheLibrary(book2);
	myLib.AddBookToTheLibrary(book3);
	myLib.AddBookToTheLibrary(book4);
	myLib.AddBookToTheLibrary(book5);

	while (true)
	{
		cout << "- LIBRARY MENU -" << endl;
		cout << "1. Show all books " << endl;
		cout << "2. Add a book" << endl;
		cout << "3. Select a book" << endl;
		cout << "0. Exit" << endl << endl;

		int menuChoice = MenuChoice(menuNumber);

		switch (menuChoice) {
		case SHOW_ALL_BOOKS:
			cout << "- BOOKS' CATALOG -" << endl;
			myLib.ShowAllBooks();
			break;
		case ADD_BOOK:
			cout << "- BOOK ADDITION -" << endl;
			AddNewBook(myLib);
			cout << endl << endl;
			break;
		case SELECT_BOOK:
			cout << " - BOOK SELECTION -" << endl;
		case EXIT:
			cout << "Exiting program. Goodbye!" << endl;
			return 0;
		}
	}
}