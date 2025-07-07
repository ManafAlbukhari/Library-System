#pragma once
#include <iostream>
#include "Global.h"
#include "clsBook.h"
#include <iomanip>
#include "clsScreen.h"

class clsBorrowBooksScreen : protected clsScreen
{

private:

	static void _PrintBooksList(clsBook Book)
	{
		cout << setw(8) << left << "" << "| " << setw(15) << left << Book.ISBN();
		cout << "| " << setw(20) << left << Book.Title;
		cout << "| " << setw(20) << left << Book.Author;
		cout << "| " << setw(10) << left << Book.Price;
		cout << "| " << setw(10) << left << Book.TotalCopies;

	}

	static void _ShowBooksList()
	{
		vector<clsBook> vBooks = clsBook::GetBooksList();

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(15) << "Book Code";
		cout << "| " << left << setw(20) << "Title";
		cout << "| " << left << setw(20) << "Author";
		cout << "| " << left << setw(10) << "Price";
		cout << "| " << left << setw(10) << "Total Copies";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vBooks.size() == 0)
			cout << "\n\n\tNo Books available in the system";

		else
			for (clsBook& Book : vBooks)
			{
				_PrintBooksList(Book);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}


public:

	static void ShowBorrowBookScreen()
	{
		_DrawScreenHeader("Borrow Book Screen");

		char Answer = 'n';
		cout << "\n\t\tDo you want to Borrow a book (Y/N) ?";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			_ShowBooksList();

			string ISBN = "";
			cout << "\n\t\tPlease select the book you want to borrow from the list: ";
			cin >> ISBN;

			clsBook Book = clsBook::Find(ISBN);

			if (!Book.IsEmpty() && Book.TotalCopies != 0)
			{
				cout << "\n\t\tThe book was found :-)";
			}
			else
			{
				cout << "\n\t\tThe book is out of stuck :-(";
				return;

			}

			cout << "\nFor How many days do you want to borrow the book? ";
			Book.BorrowDays = clsInputValidate::ReadNumber<short>();


			if (Book.Borrow())
			{
				string BorrowDate = clsDate::GetSystemDateTimeString();
				clsDate ReturnDate;

				cout << "\n\t\tBorrowing Date: " << BorrowDate << endl;
				cout << "\n\t\tBook Retrieval Date: ";
				ReturnDate.IncreaseDateByXDays(Book.BorrowDays);
				ReturnDate.Print();

			}
			else
			{

				cout << "\n\t\tThe Purchase was unsuccessful due to Insufficient Amount";

			}

		}
		else
			cout << "\n\t\tThe operation was cancelled";
	}


};

