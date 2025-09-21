#include "Book.h"
#include "Person.h"
#include "Library.h"
#include "Funcs.h"
#include <iostream>
using namespace std;

enum Menu
{
	SHOW_ALL_BOOKS = 1,
	ADD_BOOK = 2,
	ADD_PERSON = 3,
	ISSUE_BOOK = 4,
	RETURN_BOOK = 5,
	FIND_BY_TITLE = 6,
	FIND_BY_AUTHOR = 7,
	FIND_MOST_FREQUENT = 8,
	EXIT = 0
};

int main()
{
	cout << "-- LIBRARY --" << endl << endl;
	int menuNumber = 8;
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

	myLib.AddPersonToTheLibrary(Person("Lyora Whitestone", 101, 0));
	myLib.AddPersonToTheLibrary(Person("Kaiden Blackwood", 102, 0));

	while (true)
	{
		cout << "- LIBRARY MENU -" << endl;
		cout << "1. Show all books " << endl;
		cout << "2. Add a book" << endl;
		cout << "3. Add a person" << endl;
		cout << "4. Issue a book" << endl;
		cout << "5. Return a book" << endl;
		cout << "6. Find a book by the title" << endl;
		cout << "7. Find a book by the author" << endl;
		cout << "8. Find most frequent reader" << endl;
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
		case ADD_PERSON:
			cout << "- PERSON ADDITION -" << endl;
			AddNewPerson(myLib);
			break;
		case ISSUE_BOOK:
			cout << " - BOOK ISSUE -" << endl;
			IssueBookMenu(myLib);
			break;
		case RETURN_BOOK:
			cout << " - BOOK RETURN -" << endl;
			ReturnBookMenu(myLib);
			break;
		case FIND_BY_TITLE:
			cout << " - FIND BOOK BY TITLE -" << endl;
			FindBookByTitleMenu(myLib);
			break;
		case FIND_BY_AUTHOR:
			cout << " - FIND BOOK BY AUTHOR -" << endl;
			FindBookByAuthorMenu(myLib);
			break;
		case FIND_MOST_FREQUENT:
			cout << " - MOST FREQUENT READER -" << endl;
			myLib.FindMostFrequentReader();
			break;
		case EXIT:
			cout << "Exiting program. Goodbye!" << endl;
			return 0;
		}
	}
}