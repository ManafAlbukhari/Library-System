#pragma once
#include <iostream>
#include <iomanip>
#include "clsBook.h"
#include "clsScreen.h"
using namespace std;

class clsBooksListScreen : protected clsScreen
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


public:

	static void ShowBooksListScreen()
	{
		_DrawScreenHeader("Books List Screen");

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


};

