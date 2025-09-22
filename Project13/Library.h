#pragma once
#include "Book.h"
#include "Person.h"
class Library
{
	Book* bookArr;
	int bookAmount;
	int currentBookAmount;

	Person* personArr;
	int personAmount;
	int currentPersonAmount;
public:
	Library();
	~Library();

	void AddBookToTheLibrary(const Book& book);
	void ShowAllBooks();

	void AddPersonToTheLibrary(const Person& person);

	Book* FindBookByTitle(const char* title);
	Book* FindBookByAuthor(const char* author);
	Person* FindPersonByID(int id);

	void IssueBook(const char* bookTitle, int personID);
	void ReturnBook(const char* bookTitle);
	void FindMostFrequentReader();
};

