#pragma once
#include "Person.h"
#include "Library.h"
#include "Book.h"
class Person;

class Book
{
	char* bookTitle;
	char* bookAuthor;
	bool status;
	Person* issuedTo;
public:
	Book();
	Book(const char* name, const char* author, bool st);
	~Book();

	Book(const Book& copy);
	Book& operator=(const Book& copy);

	Person* GetIssuedTo();

	char* GetBookTitle();
	char* GetBookAuthor();
	bool GetStatus();

	void SetStatus(bool st);
	void SetIssuedTo(Person* person);
};

