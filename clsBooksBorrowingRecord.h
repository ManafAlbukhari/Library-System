#pragma once
#include <iostream>
#include <iomanip>
#include "clsBook.h"
#include "clsScreen.h"
using namespace std;

class clsBooksBorrowingRecord : protected clsScreen
{
private:

	static void _PrintBorrowedBooksList(clsBook::stBooksBorrowRecord Book)
	{
		cout << setw(8) << left << "" << "| " << setw(10) << left << Book.sUsername;
		cout << "| " << setw(10) << left << Book.sISBN;
		cout << "| " << setw(25) << left << Book.sTitle;
		cout << "| " << setw(22) << left << Book.sBorrowedDate;
		cout << "| " << setw(15) << left << Book.sReturnDate;

	}


public:

	static void ShowBookBorrowingRecords()
	{
		_DrawScreenHeader("Book Borrowing Records Screen");

		vector<clsBook::stBooksBorrowRecord> vBorrowedBooks = clsBook::GetBooksBorrowedRecord();

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(10) << "Username";
		cout << "| " << left << setw(10) << "ISBN ";
		cout << "| " << left << setw(25) << "Title";
		cout << "| " << left << setw(22) << "Borrowed Date";
		cout << "| " << left << setw(15) << "Return Date";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vBorrowedBooks.size() == 0)
			cout << "\n\n\tNo Books available in the system";

		else
			for (clsBook::stBooksBorrowRecord& Book : vBorrowedBooks)
			{
				_PrintBorrowedBooksList(Book);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}

};

