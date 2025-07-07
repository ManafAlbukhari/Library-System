#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "clsString.h"
#include <string>
#include "clsDate.h"
#include "clsUser.h"
#include "Global.h"

using namespace std;


class clsBook 
{

private:

	enum enMode {EmptyMode = 0, UpdateMode = 1, AddNewMode = 2};

	enMode _Mode;
	string _ISBN;
	string _Title;
	string _Author;
	int _Price = 0;
	short _TotalCopies = 0;
	bool _MarkedForDelete = false;
	short _BorrowDays = 0;

	string _PrepareBooksBorrowsRecord(string Seperator = "#//#")
	{
		clsDate ReturnDate;
		ReturnDate.IncreaseDateByXDays(BorrowDays);
		string BorrowsRecord = "";
		BorrowsRecord += CurrentUser.UserName + Seperator;
		BorrowsRecord += ISBN() + Seperator;
		BorrowsRecord += Title + Seperator;
		BorrowsRecord += clsDate::GetSystemDateTimeString() + Seperator;
		BorrowsRecord += ReturnDate.DateToString() + Seperator;
		BorrowsRecord += to_string(BorrowDays);

		return BorrowsRecord;
		
	}

	struct stBooksBorrowRecord;
	static stBooksBorrowRecord _ConvertBooksBorrowedLineToRecord(string Line, string Seperator = "#//#")
	{
		vector<string> vBooksBorrowedDataLine = clsString::Split(Line,Seperator);

		stBooksBorrowRecord BooksBorrowedRecord;
		BooksBorrowedRecord.sUsername = vBooksBorrowedDataLine[0];
		BooksBorrowedRecord.sISBN = vBooksBorrowedDataLine[1];
		BooksBorrowedRecord.sTitle = vBooksBorrowedDataLine[2];
		BooksBorrowedRecord.sBorrowedDate = vBooksBorrowedDataLine[3];
		BooksBorrowedRecord.sReturnDate = vBooksBorrowedDataLine[4];
		BooksBorrowedRecord.sBorrowDays = stoi(vBooksBorrowedDataLine[5]);

		return BooksBorrowedRecord;
	}

	static vector<stBooksBorrowRecord> _LoadBooksBorrowedDataFromFile()
	{
		stBooksBorrowRecord BooksBorrowRecord;

		vector<stBooksBorrowRecord> vBooksBorrowed;

		fstream MyFile;
		MyFile.open("BorrowedBooks.txt", ios::in);

		string Line;

		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
				BooksBorrowRecord = _ConvertBooksBorrowedLineToRecord(Line);
				vBooksBorrowed.push_back(BooksBorrowRecord);
			}
			MyFile.close();
		}
		return vBooksBorrowed;
	}

	string _PrepareBooksSalesRecord(string Seperator = "#//#")
	{
		string BooksSalesRecord = "";
		BooksSalesRecord += CurrentUser.UserName + Seperator;
		BooksSalesRecord +=  ISBN() + Seperator;
		BooksSalesRecord += Title + Seperator;
		BooksSalesRecord += to_string(Price);

		return BooksSalesRecord;

	}

	struct stBookSalesRecord;
	static stBookSalesRecord _ConvertBooksSalesLineToRecord(string Line, string Seperator = "#//#")
	{
		stBookSalesRecord BooksSalesRecord;

		vector<string> BooksSalesDataLine = clsString::Split(Line,Seperator);
		
		BooksSalesRecord.Username = BooksSalesDataLine[0];
		BooksSalesRecord.sISBN = BooksSalesDataLine[1];
		BooksSalesRecord.sTitle = BooksSalesDataLine[2];
		BooksSalesRecord.sBookPrice = stoi(BooksSalesDataLine[3]);

		return BooksSalesRecord;
	}

	static vector<stBookSalesRecord> _LoadBooksSalesDataFromFile()
	{
		vector<stBookSalesRecord> vBooksSales;

		fstream MyFile;
		MyFile.open("BooksSales.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				stBookSalesRecord Book = _ConvertBooksSalesLineToRecord(Line);
				vBooksSales.push_back(Book);
			}
			MyFile.close();
		}
		return vBooksSales;
	}

	static clsBook _ConvertLineToBookObject(string Line, string Seperator = "#//#")
	{
		vector<string> vBookData;
		vBookData = clsString::Split(Line, Seperator);

		return clsBook(enMode::UpdateMode, vBookData[0], vBookData[1], vBookData[2], stoi(vBookData[3]), stoi(vBookData[4]));
	}

	static string _ConvertBookObjectToLine(clsBook Book, string Seperator = "#//#")
	{
		string stBookRecord = "";
		stBookRecord += Book.ISBN() + Seperator;
		stBookRecord += Book.Title + Seperator;
		stBookRecord += Book.Author + Seperator;
		stBookRecord += to_string(Book.Price) + Seperator;
		stBookRecord += to_string(Book.TotalCopies);

		return stBookRecord;
	}

	static vector<clsBook> _LoadBooksDataFromFile()
	{
		vector<clsBook> vBooks;

		fstream MyFile;
		MyFile.open("Books.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBook Book = _ConvertLineToBookObject(Line);
				vBooks.push_back(Book);
			}
			MyFile.close();
		}
		return vBooks;
	}

	static void _SaveBooksDataToFile(vector<clsBook> vBooks)
	{
		fstream MyFile;
		MyFile.open("Books.txt", ios::out);

		string DataLine;

		if (MyFile.is_open())
		{
			for (clsBook& B : vBooks)
			{
				if (B.MarkedForDelete() == false)
				{
					
					DataLine = _ConvertBookObjectToLine(B);
					MyFile << DataLine << endl;
					
					
				}

			}
			MyFile.close();
		}
	}

	void _Update()
	{
		vector<clsBook> vBooks;
		vBooks = _LoadBooksDataFromFile();

		for (clsBook& B : vBooks)
		{
			if (B.ISBN() == ISBN())
			{

				B = *this;
				break;
			}
		}
		_SaveBooksDataToFile(vBooks);
	}

	static void _AddDataLineToFile(string stDataLine)
	{
		fstream MyFile;
		MyFile.open("Books.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;

			MyFile.close();
		}
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertBookObjectToLine(*this));
	}


	static clsBook _GetEmptyBookObject()
	{
		//return constructor and set mode to empty
		return clsBook(enMode::EmptyMode, "", "", "", 0, 0);
	}


public:


	clsBook(enMode Mode, string ISBN, string Title, string Author, int Price, short TotalCopies)
	{
		_Mode = Mode;
		_ISBN = ISBN;
		_Title = Title;
		_Author = Author;
		_Price = Price;
		_TotalCopies = TotalCopies;
	}

	string ISBN()
	{
		return _ISBN;
	}

	void SetTitle(string Title)
	{
		_Title = Title;
	}

	string GetTitle()
	{
		return _Title;
	}

	_declspec(property(get = GetTitle, put = SetTitle)) string Title;

	void SetAuthor(string Author)
	{
		_Author = Author;
	}

	string GetAuthor()
	{
		return _Author;
	}

	_declspec(property(get = GetAuthor, put = SetAuthor)) string Author;

	void SetTotalCopies(short TotalCopies)
	{
		_TotalCopies = TotalCopies;
	}

	short GetTotalCopies()
	{
		return _TotalCopies;
	}

	_declspec(property(get = GetTotalCopies, put = SetTotalCopies)) short TotalCopies;

	void SetPrice(int Price)
	{
		_Price = Price;
	}

	int GetPrice()
	{
		return _Price;
	}

	_declspec(property(get = GetPrice, put = SetPrice)) int Price;

	void SetBorrowDays(short BorrowDays)
	{
		_BorrowDays = BorrowDays;
	}

	short GetBorrowDays()
	{
		return _BorrowDays;
	}

	_declspec(property(get = GetBorrowDays, put = SetBorrowDays)) short BorrowDays;

	bool MarkedForDelete()
	{
		return _MarkedForDelete;
	}
	

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	bool Delete()
	{
		vector<clsBook> vBooks;

		vBooks = _LoadBooksDataFromFile();

		for (clsBook& B : vBooks)
		{
			if (B.ISBN() == ISBN())
			{
				B._MarkedForDelete = true;
				break;
			}
		}
		_SaveBooksDataToFile(vBooks);

		*this = _GetEmptyBookObject();

		return true;
	}

	bool Buy(int Amount)
	{
		if (Amount < Price)
			return false;
		
		if (TotalCopies == 0)
			return false;

		TotalCopies--;
		Save();
		RegisterBooksSales();
		return true;

	}

	bool Borrow()
	{
		if (TotalCopies <= 0)
			return false;	

		TotalCopies--;
		Save();
		RegisterBooksBorrows();
		return true;
		
	}

	static clsBook Find(string ISBN)
	{

		fstream MyFile;
		MyFile.open("Books.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBook Book = _ConvertLineToBookObject(Line);
				if (Book.ISBN() == ISBN)
				{
					MyFile.close();
					return Book;
				}
			}
			MyFile.close();
		}
		return _GetEmptyBookObject();
	}

	static clsBook Find(string ISBN, string Title)
	{

		fstream MyFile;
		MyFile.open("Books.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBook Book = _ConvertLineToBookObject(Line);
				if (Book.ISBN() == ISBN && Book.Title == Title)
				{
					MyFile.close();
					return Book;
				}
			}
			MyFile.close();
		}
		return _GetEmptyBookObject();
	}


	static bool IsBookExist(string ISBN)
	{
		clsBook Book = clsBook::Find(ISBN);
		return (!Book.IsEmpty());
	}


	static clsBook GetAddNewBookObject(string ISBN)
	{
		return clsBook(enMode::AddNewMode, ISBN, "", "", 0, 0);
	}

	static vector<clsBook> GetBooksList()
	{
		return _LoadBooksDataFromFile();
	}


	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildISBNExists = 2 };

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:

			return enSaveResults::svFaildEmptyObject;

		case enMode::UpdateMode:

			_Update();
			return enSaveResults::svSucceeded;

		case enMode::AddNewMode:

			if (clsBook::IsBookExist(ISBN()))
			{
				return enSaveResults::svFaildISBNExists;
			}
			else
			{
				_AddNew();

				//We need to set the mode to update after add new
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}

		
		}
	}

	static struct stBooksBorrowRecord
	{
		string sUsername;
		string sISBN;
		string sTitle;
		string sBorrowedDate;
		string sReturnDate;
		short sBorrowDays;
	};

	static struct stBookSalesRecord
	{
		string Username;
		string sISBN;
		string sTitle;
		int sBookPrice;
	};
	
	static vector<stBookSalesRecord> GetBooksSalesRecord()
	{
		return _LoadBooksSalesDataFromFile();

	}

	void RegisterBooksSales()
	{
		string DataLine = _PrepareBooksSalesRecord();
		fstream MyFile;

		MyFile.open("BooksSales.txt", ios::app | ios::out);

		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;

			MyFile.close();
		}
	}

	void RegisterBooksBorrows()
	{
		string DataLine = _PrepareBooksBorrowsRecord();
		fstream MyFile;

		MyFile.open("BorrowedBooks.txt", ios::app | ios::out);

		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;

			MyFile.close();
		}
	}

	static vector<stBooksBorrowRecord> GetBooksBorrowedRecord()
	{
		return _LoadBooksBorrowedDataFromFile();
	}

};

