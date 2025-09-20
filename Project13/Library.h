#pragma once
class Library
{
	Book* bookArr;
	int bookAmount;
	int currentAmount;
public:
	Library();
	~Library();

	void AddBookToTheLibrary(const Book& book);;
	void ShowAllBooks();
};

