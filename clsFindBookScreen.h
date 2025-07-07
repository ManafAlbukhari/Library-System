#pragma once
#include <iostream>
#include "clsBook.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

using namespace std;


class clsFindBookScreen : protected clsScreen
{
private:

	static void _PrintBook(clsBook Book)
	{
		cout << "\n\t\t__________________________________";
		cout << "\n\t\tBook Info:\n";
		cout << "\n\t\tBook Code        : " << Book.ISBN();
		cout << "\n\t\tTitle            : " << Book.Title;
		cout << "\n\t\tAuthor           : " << Book.Author;
		cout << "\n\t\tPrice            : " << Book.Price;
		cout << "\n\t\tTotal Copies     : " << Book.TotalCopies;
		cout << "\n\t\t___________________________________\n";
	}

public:

	static void ShowFindBookScreen()
	{
		_DrawScreenHeader("Find Book Screen");

		string ISBN = "";

		cout << "\nPlease Enter ISBN: ";
		ISBN = clsInputValidate::ReadString();

		while (!clsBook::IsBookExist(ISBN))
		{
			cout << "\nBook is not exist in the list , choose another one: ";
			ISBN = clsInputValidate::ReadString();
		}

		clsBook Book = clsBook::Find(ISBN);

		if (!Book.IsEmpty())
		{
			cout << "\nBook was found :-)";
		}
		else
		{
			cout << "\nBook was not found :-(";
		}

		_PrintBook(Book);

	}
};

