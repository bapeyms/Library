#include "Book.h"
#include "Person.h"
#include "Library.h"
#include <iostream>
using namespace std;

Book::Book() :bookName(nullptr), bookAuthor(nullptr), status(true) {}

Book::Book(const char* name, const char* author, bool st)
{
	bookName = new char[strlen(name) + 1];
	strcpy_s(bookName, strlen(name) + 1, name);

	bookAuthor = new char[strlen(author) + 1];
	strcpy_s(bookAuthor, strlen(author) + 1, author);

	status = st;
}

Book::~Book()
{
	delete[] bookName;
	delete[] bookAuthor;
}

