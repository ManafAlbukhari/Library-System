#pragma once
#include <iostream>
#include <iomanip>
#include "clsBook.h"
#include "clsScreen.h"
using namespace std;

class clsBookSalesRecord : protected clsScreen
{
private:

	static void _PrintBooksList(clsBook::stBookSalesRecord Book)
	{
		cout << setw(8) << left << "" << "| " << setw(15) << left << Book.Username;
		cout << "| " << setw(12) << left << Book.sISBN;
		cout << "| " << setw(20) << left << Book.sTitle;
		cout << "| " << setw(10) << left << Book.sBookPrice;

	}


public:

	static void ShowBookSalesRecords()
	{
		_DrawScreenHeader("Book Sales Records Screen");
		
		vector<clsBook::stBookSalesRecord> vBoughtBooks = clsBook::GetBooksSalesRecord();

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(15) << "Username";
		cout << "| " << left << setw(12) << "ISBN ";
		cout << "| " << left << setw(20) << "Title";
		cout << "| " << left << setw(10) << "Price";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vBoughtBooks.size() == 0)
			cout << "\n\n\tNo Books available in the system";

		else
			for (clsBook::stBookSalesRecord& Book : vBoughtBooks)
			{
				_PrintBooksList(Book);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}


};

