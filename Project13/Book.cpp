#include "Book.h"
#include "Person.h"
#include "Library.h"
#include <iostream>
using namespace std;

Book::Book() :bookTitle(nullptr), bookAuthor(nullptr), status(true) {}
Book::Book(const char* name, const char* author, bool st)
{
	bookTitle = new char[strlen(name) + 1];
	strcpy_s(bookTitle, strlen(name) + 1, name);

	bookAuthor = new char[strlen(author) + 1];
	strcpy_s(bookAuthor, strlen(author) + 1, author);

	status = st;
}
Book::~Book()
{
	delete[] bookTitle;
	delete[] bookAuthor;
}
Book::Book(const Book& copy)
{
    bookTitle = new char[strlen(copy.bookTitle) + 1];
    strcpy_s(bookTitle, strlen(copy.bookTitle) + 1, copy.bookTitle);

    bookAuthor = new char[strlen(copy.bookAuthor) + 1];
    strcpy_s(bookAuthor, strlen(copy.bookAuthor) + 1, copy.bookAuthor);

    status = copy.status;
}
Book& Book::operator=(const Book& copy) 
{
    if (this != &copy) 
    {
        delete[] bookTitle;
        delete[] bookAuthor;

        bookTitle = new char[strlen(copy.bookTitle) + 1];
        strcpy_s(bookTitle, strlen(copy.bookTitle) + 1, copy.bookTitle);

        bookAuthor = new char[strlen(copy.bookAuthor) + 1];
        strcpy_s(bookAuthor, strlen(copy.bookAuthor) + 1, copy.bookAuthor);

        status = copy.status;
    }
    return *this;
}

char* Book::GetBookTitle()
{
	return bookTitle;
}
char* Book::GetBookAuthor()
{
	return bookAuthor;
}
bool Book::GetStatus()
{
	return status;
}

