#pragma once
#include <iostream>
#include "clsBook.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

class clsDeleteBookScreen : protected clsScreen
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

	static void ShowDeleteBookScreen()
	{
		_DrawScreenHeader("Delete Book Screen");

		string ISBN = "";

		cout << "\nPlease Enter ISBN: ";
		ISBN = clsInputValidate::ReadString();

		while (!clsBook::IsBookExist(ISBN))
		{
			cout << "\nBook ISBN is not exist, choose another one: ";
			ISBN = clsInputValidate::ReadString();
		}

		clsBook Book = clsBook::Find(ISBN);
		_PrintBook(Book);

		char Answer = 'n';
		cout << "\nAre you sure to delete this book (Y/N)? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (Book.Delete())
			{
				cout << "\nBook Deleted Successfully :-)\n";
				_PrintBook(Book);
			}
		}
		else
		{
			cout << "\nError Book was not deleted\n";
		}

	}

};

