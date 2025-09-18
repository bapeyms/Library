#pragma once
class Book
{
	char* bookName;
	char* bookAuthor;
	bool status;
public:
	Book();
	Book(const char* name, const char* author, bool st);
	~Book();
};

