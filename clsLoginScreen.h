#pragma once

#include <iostream>
#include "clsUser.h"
#include <iomanip>
#include "clsUserMainScreen.h"
#include "Global.h"
#include "clsLibrarianScreen.h"
#include "clsInputValidate.h"
#include "clsLoginUserScreen.h"
#include "clsLoginLibrarianScreen.h"
#include "clsScreen.h"

class clsLoginScreen : protected clsScreen
{

private:

    enum enLoginOption {eUserLogin = 1, eLibrarianLogin = 2};

    static short _ReadLoginOption()
    {
        short Choice = 0;
        cout << "\n\nChoose Login Option? ";
        Choice = clsInputValidate::ReadNumberBetween(1, 2);
        return Choice;
    }

    static void _GoBackToLoginMenu()
    {
        cout << "\nPress any key to go back to Login menu...";
        system("pause>0");
        ShowLoginScreen();
    }


    static bool _PerformLoginOption(enLoginOption LoginOption)
    {
        switch (LoginOption)
        {
        case clsLoginScreen::eUserLogin:
            system("cls");
            return clsLoginUserScreen::ShowLoginUserScreen();
            //_GoBackToLoginMenu();
            

        case clsLoginScreen::eLibrarianLogin:
            system("cls");
            return clsLoginLibrarianScreen::ShowLoginLibrarianScreen();
           // _GoBackToLoginMenu();

        default:
            return false;
        }
    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");

        _DrawScreenHeader("Login Main Screen");

        cout << "\n[1] Login as User.";
        cout << "\n[2] Login as Librarian.";

       return _PerformLoginOption((enLoginOption)_ReadLoginOption());
        
    }

};

