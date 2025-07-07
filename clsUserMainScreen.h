#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsBooksListScreen.h"
#include "clsFindBookScreen.h"
#include "clsBuyBookScreen.h"
#include "clsBorrowBooksScreen.h"
#include "Global.h"
#include "clsScreen.h"

using namespace std;

class clsUserMainScreen : protected clsScreen
{
private:

	enum enUserOptions {eShowBooksList = 1, eFindBook = 2, eBuyBook = 3, eBorrowBook = 4, eExit = 5};

	static short _ReadUserOption()
	{
		short Choice = 0;

		cout << "\n\t\tPlease Enter your option [1 to 5]? ";
		Choice = clsInputValidate::ReadNumberBetween<short>(1, 5, "\nInvalid, Enter Number between 1 to 5? ");
		return Choice;
	}


	static void _GoBackToUserMenu()
	{
		cout << "\nPress any key to go back to user menu...";
		system("pause>0");
		ShowUserMainScreen();
	}

	static void _ShowBooksListScreen()
	{
		clsBooksListScreen::ShowBooksListScreen();
	}


	static void _ShowFindBookScreen()
	{
		clsFindBookScreen::ShowFindBookScreen();
	}

	static void _ShowBuyBookScreen()
	{
		clsBuyBookScreen::ShowBuyBookScreen();
	}

	static void _ShowBorrowBookScreen()
	{
		clsBorrowBooksScreen::ShowBorrowBookScreen();
	}

	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");

		//then it will go back to the main function
	}


	static void _PerformUserOption(enUserOptions UserOption)
	{
		switch (UserOption)
		{
		case clsUserMainScreen::eShowBooksList:
			system("cls");
			_ShowBooksListScreen();
			_GoBackToUserMenu();
			break;

		case clsUserMainScreen::eFindBook:
			system("cls");
			_ShowFindBookScreen();
			_GoBackToUserMenu();
			break;

		case clsUserMainScreen::eBuyBook:
			system("cls");
			_ShowBuyBookScreen();
			_GoBackToUserMenu();
			break;

		case clsUserMainScreen::eBorrowBook:
			system("cls");
			_ShowBorrowBookScreen();
			_GoBackToUserMenu();
			break;

		case clsUserMainScreen::eExit:
			system("cls");
			_Logout();
			break;
		
		}
	}

public:

	static void ShowUserMainScreen()
	{
		system("cls");

		_DrawScreenHeader("User Main Screen");

		cout << "\n\t\t_____________________________________";
		cout << "\n\t\t[1] Show Books List.";
		cout << "\n\t\t[2] Search for a Book.";
		cout << "\n\t\t[3] Buy a Book.";
		cout << "\n\t\t[4] Borrow a Book.";
		cout << "\n\t\t[5] Go Back.";
		cout << "\n\t\t_____________________________________\n";

		_PerformUserOption((enUserOptions)_ReadUserOption());
	}
};

