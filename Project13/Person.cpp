#include "Book.h"
#include "Person.h"
#include "Library.h"
#include "Funcs.h"
#include <iostream>
using namespace std;

Person::Person() :fullName(nullptr), ID(0), bookCount(0) {}
Person::Person(const char* fn, int id, int c)
{
	fullName = new char[strlen(fn) + 1];
	strcpy_s(fullName, strlen(fn) + 1, fn);

	ID = id;
	bookCount = c;
}

Person::Person(const Person& copy)
{
	fullName = new char[strlen(copy.fullName) + 1];
	strcpy_s(fullName, strlen(copy.fullName) + 1, copy.fullName);

	ID = copy.ID;
	bookCount = copy.bookCount;
}
Person& Person::operator=(const Person& copy) 
{
	if (this != &copy) 
	{
		delete[] fullName;
		fullName = new char[strlen(copy.fullName) + 1];
		strcpy_s(fullName, strlen(copy.fullName) + 1, copy.fullName);

		ID = copy.ID;
		bookCount = copy.bookCount;
	}
	return *this;
}

Person::~Person()
{
	delete[] fullName;
}

char* Person::GetFullName()
{
	return fullName;
}
int Person::GetID()
{
	return ID;
}
int Person::GetBooksCount() 
{
	return bookCount;
}

void Person::IncrementBooksCount() 
{
	bookCount++;
}
void Person::DecrementBooksCount() 
{
	bookCount--;
}
