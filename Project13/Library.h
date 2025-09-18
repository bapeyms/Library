#pragma once
class Library
{
	Book** bookArr;
	int bookAmount;
	int currentAmount;
public:
	Library();
	Library(int amount);
	~Library();
};

