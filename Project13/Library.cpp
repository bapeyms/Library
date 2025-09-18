#include "Book.h"
#include "Person.h"
#include "Library.h"
#include <iostream>
using namespace std;

Library::Library() :bookArr(nullptr), bookAmount(0), currentAmount(0) {}
Library::Library(int amount)
{
	bookAmount = amount;
	bookArr = new Book * [bookAmount];
	currentAmount = 0;
}
Library::~Library()
{
	for (int i = 0; i < currentAmount; i++)
	{
		delete bookArr[i];
	}
	delete[] bookArr;
}
