#pragma once
#include <iostream>
#include <iomanip>
#include "clsBook.h"
#include "clsScreen.h"

using namespace std;

class clsBuyBookScreen : protected clsScreen
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

	static void ShowBuyBookScreen()
	{
		_DrawScreenHeader("Buy Book Screen");

		char Answer = 'n';
		cout << "\n\t\tDo you want to buy a book (Y/N) ?";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			_ShowBooksList();
			
			string ISBN = "";
			cout << "\n\t\tPlease select the book you want to buy from the list: ";
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

			cout << "\n\t\tThe price for [" << Book.Title << "] is: ";
			cout << Book.Price;

			int Amount = 0;
			cout << "\n\t\tPlease Enter the Amount: ";
			cin >> Amount;


			
			if (Book.Buy(Amount))
			{
				cout << "\n\t\tThe Purchase was successful";
				cout << "\n\t\tHere is you change : " << Amount - Book.Price;
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

