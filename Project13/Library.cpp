#include "Book.h"
#include "Person.h"
#include "Library.h"
#include <iostream>
using namespace std;

Library::Library()
{
	bookAmount = 5;
	bookArr = new Book[bookAmount];
	currentAmount = 0;
}
Library::~Library()
{
	delete[] bookArr;
}

void Library:: AddBookToTheLibrary(const Book& book)
{
	if (currentAmount >= bookAmount)
	{
		int newAmount = currentAmount * 2;
		Book* newBooks = new Book[newAmount];
		for (int i = 0; i < currentAmount; ++i)
		{
			newBooks[i] = bookArr[i];
		}
		delete[] bookArr;
		bookArr = newBooks;
		bookAmount = newAmount;
	}
	bookArr[currentAmount] = book;
	currentAmount++;
}
void Library::ShowAllBooks()
{
	for (int i = 0; i < currentAmount; i++)
	{
		cout << "- Book #" << i + 1 << endl;
		cout << "Title: " << bookArr[i].GetBookTitle() << endl;
		cout << "Author: " << bookArr[i].GetBookAuthor() << endl;
		cout << "Status (1 - in stock, 0 - issued to reader): " << bookArr[i].GetStatus() << endl << endl;
	}
	cout << endl;
}
