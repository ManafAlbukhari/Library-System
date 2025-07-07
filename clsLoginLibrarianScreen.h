#pragma once
#include <iostream>
#include "Global.h"
#include "clsLibrarianScreen.h"
#include "clsScreen.h"
using namespace std;

class clsLoginLibrarianScreen : protected clsScreen
{
private:

    static  bool _Login()
    {
        bool LoginFaild = false;
        short LoginFailedCount = 0;
        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                LoginFailedCount++;

                cout << "\nInvalid Username/Password!\n\n";
                cout << "You have " << (3 - LoginFailedCount)
                    << " Trial(s) to login.\n\n";
            }

            if (LoginFailedCount == 3)
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

        clsLibrarianScreen::ShowLibrarianMainScreen();
        return true;
    }

public:

    static bool ShowLoginLibrarianScreen()
    {
        system("cls");

        _DrawScreenHeader("Login Librarian Screen");

       return _Login();
    }
};

