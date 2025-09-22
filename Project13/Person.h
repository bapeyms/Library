#include "Library.h"
#include "Book.h"

#pragma once
class Person
{
	char* fullName;
	int ID;
	int bookCount;
public:
	Person();
	Person(const char* fn, int id, int c);

	Person(const Person& copy);
	Person& operator=(const Person& copy);

	~Person();

	char* GetFullName();
	int GetID();

	int GetBooksCount();
	void IncrementBooksCount();
	void DecrementBooksCount();
};

