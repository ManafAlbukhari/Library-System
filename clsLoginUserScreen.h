#pragma once
#include <iostream>
#include "clsUserMainScreen.h"
#include "Global.h"
#include "clsScreen.h"
using namespace std;


class clsLoginUserScreen : protected clsScreen
{
private:

    static  bool _Login()
    {
        bool LoginFaild = false;
        short FailedLoginCount = 0;

        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                FailedLoginCount++;
                cout << "\nInvlaid Username/Password!\n\n";
                cout << "You have " << (3 - FailedLoginCount)
                    << " Trial(s) to login.\n\n";
            }

            if (FailedLoginCount == 3)
            {
                cout << "\nYou are locked after 3 failed trails.\n";
                return false;

            }
            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

        clsUserMainScreen::ShowUserMainScreen();
        return true;
    }

public:

	static bool ShowLoginUserScreen()
	{
        system("cls");

        _DrawScreenHeader("Login User Screen");

        return _Login();
	}
};

