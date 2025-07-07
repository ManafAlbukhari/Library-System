#pragma once
#include <iostream>
#include "Global.h"
#include "clsDate.h"
using namespace std;

class clsScreen
{
protected:

	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		cout << "\t\t\t\t\t_________________________________________";

		cout << "\n\n\t\t\t\t\t  " << Title;


		if (SubTitle != "")
		{
			cout << "\n\t\t\t\t\t  " << SubTitle;

		}
		cout << "\n\t\t\t\t\t_________________________________________\n\n";
		cout << "\t\t\t\t\tUser: " << CurrentUser.UserName << endl;
		cout << "\t\t\t\t\tDate: " << clsDate::DateToString(clsDate()) << "\n\n";
	}
};

