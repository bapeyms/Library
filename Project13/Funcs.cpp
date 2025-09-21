#pragma once
#include "Funcs.h"
#include "Book.h"
#include "Person.h"
#include "Library.h"
#include <iostream>
using namespace std;


int MenuChoice(int menuNumber)
{
    int menuChoice;
    cout << "Enter the menu number to perform a desired action" << endl;
    cout << "Number: ";
    cin >> menuChoice;
    cin.ignore(1000, '\n');
    while (menuChoice < 0 || menuChoice > menuNumber)
    {
        cout << "Enter a number from 0 to " << menuNumber << "!" << endl;
        cout << "Number: ";
        cin >> menuChoice;
        cin.ignore(1000, '\n');
    }
    cout << endl;
    return menuChoice;
}

void AddNewBook(Library& library)
{
    const int N = 256;
    char title[N];
    char author[N];
    bool status;

    cout << "Enter title: ";
    cin.getline(title, N);

    cout << "Enter author: ";
    cin.getline(author, N);

    cout << "Status (1 - in stock, 0 - issued to reader): ";
    cin >> status;
    cin.ignore(1000, '\n');
    Book newBook(title, author, status);
    library.AddBookToTheLibrary(newBook);
    cout << "New book is successfully entered!" << endl;
}
void AddNewPerson(Library& library)
{
    const int N = 256;
    char name[N];
    int id;
    int st = 0;

    cout << "Enter person's full name: ";
    cin.getline(name, N);

    cout << "Enter person's ID: ";
    cin >> id;
    cin.ignore(1000, '\n');

    library.AddPersonToTheLibrary(Person(name, id, st));
    cout << "Person added successfully!" << endl;
}
void IssueBookMenu(Library& library)
{
    const int N = 256;
    char title[N];
    int id;

    cout << "Enter the title of the book to issue: ";
    cin.getline(title, N);

    cout << "Enter the person's ID: ";
    cin >> id;
    cin.ignore(1000, '\n');

    library.IssueBook(title, id);
}
void ReturnBookMenu(Library& library)
{
    const int N = 256;
    char title[N];
    cout << "Enter the title of the book to return: ";
    cin.getline(title, N);

    library.ReturnBook(title);
}
void FindBookByTitleMenu(Library& library)
{
    const int N = 256;
    char title[N];

    cout << "Enter book title or a part of it: ";
    cin.getline(title, N);

    Book* foundBook = library.FindBookByTitle(title);
    if (foundBook)
    {
        cout << "\nBook Found!" << endl;
        cout << "Title: " << foundBook->GetBookTitle() << endl;
        cout << "Author: " << foundBook->GetBookAuthor() << endl;
    }
    else
    {
        cout << "\nBook with this title was not found" << endl;
    }
}
void FindBookByAuthorMenu(Library& library)
{
    const int N = 256;
    char author[N];
    cout << "Enter author's name or a part of it: ";
    cin.getline(author, N);

    Book* foundBook = library.FindBookByAuthor(author);
    if (foundBook)
    {
        cout << "\nBook Found!" << endl;
        cout << "Title: " << foundBook->GetBookTitle() << endl;
        cout << "Author: " << foundBook->GetBookAuthor() << endl;
    }
    else
    {
        cout << "\nBook with this author was not found." << endl;
    }
}
void FindMostFrequentReaderMenu(Library& library)
{
    library.FindMostFrequentReader();
}