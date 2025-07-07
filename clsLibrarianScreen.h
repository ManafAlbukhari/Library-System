#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsBooksListScreen.h"
#include "clsFindBookScreen.h"
#include "clsBuyBookScreen.h"
#include "clsBookSalesRecord.h"
#include "clsBooksBorrowingRecord.h"
#include "clsUserListScreen.h"
#include "clsAddBookScreen.h"
#include "clsDeleteBookScreen.h"
#include "clsUpdateBookScreen.h"
#include "Global.h"
#include "clsScreen.h"

using namespace std;

class clsLibrarianScreen : protected clsScreen
{
private:

	enum enLibrarianOptions { eShowUsersList = 1, eShowBooksList = 2, eAddBook = 3, eDeleteBook = 4, 
		eFindBook = 5, eUpdateBook = 6, eBookSalesRecords = 7, eBookBorrowingRecords = 8, eExit = 9 };

	static short _ReadLibrarianOption()
	{
		short Choice = 0;

		cout << "\n\t\tPlease Enter your option [1 to 9]? ";
		Choice = clsInputValidate::ReadNumberBetween<short>(1, 9, "\nInvalid, Enter Number between 1 to 9? ");
		return Choice;
	}


	static void _GoBackToLibrarianMenu()
	{
		cout << "\nPress any key to go back to Librarian menu...";
		system("pause>0");
		ShowLibrarianMainScreen();
	}

	static void _ShowUsersListScreen()
	{
		clsUserListScreen::ShowUsersListScreen();
	}

	static void _ShowBooksListScreen()
	{
		clsBooksListScreen::ShowBooksListScreen();
	}

	static void _ShowAddBookScreen()
	{
		clsAddBookScreen::ShowAddBookScreen();
	}

	static void _ShowDeleteBookScreen()
	{
		clsDeleteBookScreen::ShowDeleteBookScreen();
	}


	static void _ShowFindBookScreen()
	{
		clsFindBookScreen::ShowFindBookScreen();
	}

	static void _ShowUpdateBookScreen()
	{
		clsUpdateBookScreen::ShowUpdateBookScreen();
	}

	static void _ShowBookSalesRecords()
	{
		clsBookSalesRecord::ShowBookSalesRecords();
	}
	
	static void _ShowBookBorrowingRecords()
	{
		clsBooksBorrowingRecord::ShowBookBorrowingRecords();
	}

	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
	}

	static void _PerformUserOption(enLibrarianOptions LibrarianOption)
	{
		switch (LibrarianOption)
		{
		case clsLibrarianScreen::eShowUsersList:
			system("cls");
			_ShowUsersListScreen();
			_GoBackToLibrarianMenu();
			break;

		case clsLibrarianScreen::eShowBooksList:
			system("cls");
			_ShowBooksListScreen();
			_GoBackToLibrarianMenu();
			break;

		case clsLibrarianScreen::eAddBook:
			system("cls");
			_ShowAddBookScreen();
			_GoBackToLibrarianMenu();
			break;

		case clsLibrarianScreen::eDeleteBook:
			system("cls");
			_ShowDeleteBookScreen();
			_GoBackToLibrarianMenu();
			break;

		case clsLibrarianScreen::eFindBook:
			system("cls");
			_ShowFindBookScreen();
			_GoBackToLibrarianMenu();
			break;

		case clsLibrarianScreen::eUpdateBook:
			system("cls");
			_ShowUpdateBookScreen();
			_GoBackToLibrarianMenu();
			break;

		case clsLibrarianScreen::eBookSalesRecords:
			system("cls");
			_ShowBookSalesRecords();
			_GoBackToLibrarianMenu();
			break;

		case clsLibrarianScreen::eBookBorrowingRecords:
			system("cls");
			_ShowBookBorrowingRecords();
			_GoBackToLibrarianMenu();
			break;

		case clsLibrarianScreen::eExit:
			system("cls");
			_Logout();
			break;
		
		}
	}

public:

	static void ShowLibrarianMainScreen()
	{
		system("cls");

		_DrawScreenHeader("Librarian Main Screen");

		cout << "\n\t\t_____________________________________";
		cout << "\n\t\t[1] Show Users List.";
		cout << "\n\t\t[2] Show Books List.";
		cout << "\n\t\t[3] Add Book.";
		cout << "\n\t\t[4] Delete Book.";
		cout << "\n\t\t[5] Find a Book.";
		cout << "\n\t\t[6] Update Book Info.";
		cout << "\n\t\t[7] Book Sales Records.";
		cout << "\n\t\t[8] Book Borrowing Records.";
		cout << "\n\t\t[9] Exit.";
		cout << "\n\t\t_____________________________________\n";

		_PerformUserOption((enLibrarianOptions)_ReadLibrarianOption());
	}
};

