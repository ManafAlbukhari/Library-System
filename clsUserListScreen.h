#pragma once
#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsScreen.h"

using namespace std;

class clsUserListScreen : protected clsScreen
{
private:

	static void _PrintUsersList(clsUser User)
	{
		cout << setw(8) << left << "" << "| " << setw(12) << left << User.FirstName;
		cout << "| " << setw(12) << left << User.LastName;
		cout << "| " << setw(12) << left << User.Email;
		cout << "| " << setw(12) << left << User.Phone;
		cout << "| " << setw(10) << left << User.UserName;
		cout << "| " << setw(10) << left << User.Password;
		cout << "| " << setw(8) << left << User.Permissions;


	}


public:

	static void ShowUsersListScreen()
	{
		_DrawScreenHeader("Users List Screen");

		vector<clsUser> vUsers = clsUser::GetUsersList();

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(12) << "First Name";
		cout << "| " << left << setw(12) << "Last Name ";
		cout << "| " << left << setw(12) << "Email";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(10) << "Username";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(8)  << "Permission";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vUsers.size() == 0)
			cout << "\n\n\tNo Users available in the system";

		else
			for (clsUser& User : vUsers)
			{
				_PrintUsersList(User);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}

};

