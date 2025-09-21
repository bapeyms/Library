#pragma once
#include "Library.h"
#include <iostream>

int MenuChoice(int menuNumber);
void AddNewBook(Library& library);
void AddNewPerson(Library& library);
void IssueBookMenu(Library& library);
void ReturnBookMenu(Library& library);
void FindBookByTitleMenu(Library& library);
void FindBookByAuthorMenu(Library& library);
void FindMostFrequentReaderMenu(Library& library);