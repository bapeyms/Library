#include "Book.h"
#include "Person.h"
#include "Library.h"
#include "Funcs.h"
#include <iostream>
using namespace std;

Library::Library()
{
	bookAmount = 5;
	bookArr = new Book[bookAmount];
	currentBookAmount = 0;

	personAmount = 2;
	personArr = new Person[personAmount];
	currentPersonAmount = 0;
}
Library::~Library()
{
	delete[] bookArr;
	delete[] personArr;
}

void Library:: AddBookToTheLibrary(const Book& book)
{
	if (currentBookAmount >= bookAmount)
	{
		int newAmount = currentBookAmount * 2;
		Book* newBooks = new Book[newAmount];
		for (int i = 0; i < currentBookAmount; ++i)
		{
			newBooks[i] = bookArr[i];
		}
		delete[] bookArr;
		bookArr = newBooks;
		bookAmount = newAmount;
	}
	bookArr[currentBookAmount] = book;
	currentBookAmount++;
}
void Library::ShowAllBooks()
{
	for (int i = 0; i < currentBookAmount; i++)
	{
		cout << "- Book #" << i + 1 << endl;
		cout << "Title: " << bookArr[i].GetBookTitle() << endl;
		cout << "Author: " << bookArr[i].GetBookAuthor() << endl;
		cout << "Status (1 - in stock, 0 - issued to reader): " << bookArr[i].GetStatus() << endl << endl;
		if (!bookArr[i].GetStatus() && bookArr[i].GetIssuedTo() != nullptr) 
		{
			cout << "Issued to: " << bookArr[i].GetIssuedTo()->GetFullName() << endl;
		}
		cout << endl;
	}
	cout << endl;
}

void Library::AddPersonToTheLibrary(const Person& person)
{
	if (currentPersonAmount >= personAmount)
	{
		int newAmount = 2 * currentPersonAmount;
		Person* persons = new Person[newAmount];
		for (int i = 0; i < currentPersonAmount; i++)
		{
			persons[i] = personArr[i];
		}
		delete[] personArr;
		personArr = persons;
		personAmount = newAmount;
	}
	personArr[currentPersonAmount] = person;
	currentPersonAmount++;
}

Book* Library::FindBookByTitle(const char* title)
{
	for (int i = 0; i < currentBookAmount; ++i) 
	{
		if (strstr(bookArr[i].GetBookTitle(), title) != nullptr)
		{
			return &bookArr[i];
		}
	}
	return nullptr;
}
Book* Library::FindBookByAuthor(const char* author)
{
	for (int i = 0; i < currentBookAmount; i++)
	{
		if (strstr(bookArr[i].GetBookAuthor(), author) != nullptr)
		{
			return &bookArr[i];
		}
	}
	return nullptr;
}
Person* Library::FindPersonByID(int id)
{
	for (int i = 0; i < currentPersonAmount; i++)
	{
		if (personArr[i].GetID() == id) 
		{
			return &personArr[i];
		}
	}
	return nullptr;
}

void Library::IssueBook(const char* bookTitle, int personID)
{
	Book* book = FindBookByTitle(bookTitle);
	if (!book)
	{
		cout << "Error: Book with this title was not found." << endl;
		return;
	}
	if (!book->GetStatus())
	{
		cout << "Error: Book is already issued." << endl;
		return;
	}

	Person* person = FindPersonByID(personID);
	if (!person)
	{
		cout << "Error: Person with this ID was not found." << endl;
		return;
	}

	if (person->GetBooksCount() >= 3)
	{
		cout << "Error: " << person->GetFullName() << " has reached the book limit (3)." << endl;
		return;
	}

	book->SetStatus(false);
	book->SetIssuedTo(person);
	person->IncrementBooksCount();
	cout << "Success! Book '" << book->GetBookTitle() 
		<< "' has been issued to " << person->GetFullName() << "." << endl;
}
void Library::ReturnBook(const char* bookTitle)
{
	Book* book = FindBookByTitle(bookTitle);
	if (!book)
	{
		cout << "Error: Book with this title was not found." << endl;
		return;
	}
	if (book->GetStatus())
	{
		cout << "Error: Book is already in stock." << endl;
		return;
	}

	Person* person = book->GetIssuedTo();
	book->SetStatus(true);
	book->SetIssuedTo(nullptr);
	if (person) 
	{
		person->DecrementBooksCount();
	}
	cout << "Success! Book '" << book->GetBookTitle() << "' has been returned." << endl;
}
void Library::FindMostFrequentReader()
{
	if (currentPersonAmount == 0) 
	{
		cout << "No readers in the library yet" << endl;
		return;
	}

	Person* mostFrequent = &personArr[0];
	for (int i = 1; i < currentPersonAmount; ++i) 
	{
		if (personArr[i].GetBooksCount() > mostFrequent->GetBooksCount()) 
		{
			mostFrequent = &personArr[i];
		}
	}
	if (mostFrequent->GetBooksCount() == 0) 
	{
		cout << "No books have been issued yet" << endl;
	}
	else {
		cout << "The most frequent reader is: " << mostFrequent->GetFullName() 
			<< " with " << mostFrequent->GetBooksCount() << " books" << endl;
	}
}


