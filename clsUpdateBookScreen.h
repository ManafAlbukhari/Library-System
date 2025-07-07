#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDate.h"
#include "clsBook.h"
class clsUpdateBookScreen : protected clsScreen
{
private:

    static void _ReadBookInfo(clsBook& Book)
    {
        cout << "\nEnter Title: ";
        Book.Title = clsInputValidate::ReadString();

        cout << "\nEnter Author: ";
        Book.Author = clsInputValidate::ReadString();

        cout << "\nEnter Price: ";
        Book.Price = clsInputValidate::ReadNumber<int>();

        cout << "\nEnter Total Copies: ";
        Book.TotalCopies = clsInputValidate::ReadNumber<short>();

    }


    static void _PrintBook(clsBook Book)
    {
        cout << "\n\t\t__________________________________";
        cout << "\n\t\tBook Info:\n";
        cout << "\n\t\tBook Code        : " << Book.ISBN();
        cout << "\n\t\tTitle            : " << Book.Title;
        cout << "\n\t\tAuthor           : " << Book.Author;
        cout << "\n\t\tPrice            : " << Book.Price;
        cout << "\n\t\tTotal Copies     : " << Book.TotalCopies;
        cout << "\n\t\t___________________________________\n";
    }


public:

	static void ShowUpdateBookScreen()
	{
        _DrawScreenHeader("\t  Update Book Screen");


        string ISBN = "";

        cout << "\nPlease Enter ISBN number: ";
        ISBN = clsInputValidate::ReadString();

        while (!clsBook::IsBookExist(ISBN))
        {
            cout << "\nISBN Number is not found, choose another one: ";
            ISBN = clsInputValidate::ReadString();

        }

        clsBook Book = clsBook::Find(ISBN);

        _PrintBook(Book);

        char Answer = 'n';

        cout << "\nAre you sure you want to update this book y/n? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            cout << "\n\nUpdate Book Info:";
            cout << "\n____________________\n";

            _ReadBookInfo(Book);

            clsBook::enSaveResults SaveResult;
            SaveResult = Book.Save();

            switch (SaveResult)
            {
            case clsBook::enSaveResults::svFaildEmptyObject:

                cout << "\nError book was not saved because it's Empty";
                break;

            case clsBook::enSaveResults::svSucceeded:

                cout << "\nBook Updated Successfully :-)\n";
                _PrintBook(Book);
                break;

            }

        }
	}
};

