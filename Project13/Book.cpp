#include "Book.h"
#include "Funcs.h"
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
    issuedTo = nullptr;
}
Book::~Book()
{
	delete[] bookTitle;
	delete[] bookAuthor;
    issuedTo = nullptr;
}

Book::Book(const Book& copy)
{
    bookTitle = new char[strlen(copy.bookTitle) + 1];
    strcpy_s(bookTitle, strlen(copy.bookTitle) + 1, copy.bookTitle);

    bookAuthor = new char[strlen(copy.bookAuthor) + 1];
    strcpy_s(bookAuthor, strlen(copy.bookAuthor) + 1, copy.bookAuthor);

    status = copy.status;
    issuedTo = copy.issuedTo;
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
        issuedTo = copy.issuedTo;
    }
    return *this;
}

Person* Book::GetIssuedTo()
{
    return issuedTo;
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

void Book::SetStatus(bool st) 
{
    status = st;
}
void Book::SetIssuedTo(Person* person) 
{
    issuedTo = person;
}

