#pragma once
class Book
{
	char* bookTitle;
	char* bookAuthor;
	bool status;
public:
	Book();
	Book(const char* name, const char* author, bool st);
	~Book();

	Book(const Book& copy);
	Book& operator=(const Book& copy);


	char* GetBookTitle();
	char* GetBookAuthor();
	bool GetStatus();
};

