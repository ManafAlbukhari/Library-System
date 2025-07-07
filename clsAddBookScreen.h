#pragma once
#include <iostream>
#include "clsBook.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
using namespace std;

class clsAddBookScreen : protected clsScreen
{
private:

	static void _ReadBookInfo(clsBook& Book)
	{
		cout << "\nEnter Title: ";
		Book.Title = clsInputValidate::ReadString();

		cout << "\nEnter Author: ";
		Book.Author = clsInputValidate::ReadString();

		cout << "\nEnter Price: ";
		Book.Price = clsInputValidate::ReadNumber<int>();

		cout << "\nEnter Total Copies: ";
		Book.TotalCopies = clsInputValidate::ReadNumber<short>();

	}


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


	static void ShowAddBookScreen()
	{
		_DrawScreenHeader("Add Book Screen");

		string ISBN = "";

		cout << "\nPlease Enter ISBN: ";
		ISBN = clsInputValidate::ReadString();

		while (clsBook::IsBookExist(ISBN))
		{
			cout << "\nBook ISBN is already exist, choose another one: ";
			ISBN = clsInputValidate::ReadString();
		}

		clsBook NewBook = clsBook::GetAddNewBookObject(ISBN);

		_ReadBookInfo(NewBook);

		clsBook::enSaveResults SaveResult;

		SaveResult = NewBook.Save();

		switch (SaveResult)
		{
		case clsBook::enSaveResults::svFaildEmptyObject:

			cout << "\nError book was not saved because it's Empty";
			break;

		case clsBook::enSaveResults::svSucceeded:

			cout << "\nBook added Successfully :-)\n";
			_PrintBook(NewBook);
			break;

		case clsBook::enSaveResults::svFaildISBNExists:

			cout << "\nError Book was not saved because Book Code number is used!\n";
			break;
		}

	}
};

