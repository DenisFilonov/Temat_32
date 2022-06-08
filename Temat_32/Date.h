#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Date{
	
	int year = 0;
	int month = 0;
	int day = 0;

	
	void fillDate()	{
		cout << "YYYY -> ";
		cin >> year;
		cout << "MM -> ";
		cin >> month;
		cout << "DD -> ";
		cin >> day;
	}
	void getNowDate()	{		 
		struct tm *tim = new tm;		
		time_t tt = time(NULL);		
		localtime_s(tim, &tt);
		 
		year = 1900 + tim->tm_year;
		month = 1 + tim->tm_mon;
		day = tim->tm_mday;
	}
	void printDate(){
		cout << year << "/" << month / 10 << month%10 << "/" << day/10 << day%10 << endl;
	}

	char* toString()
	{
		char* str = new char[11];
		sprintf_s(str, 11, "%d/%d%d/%d%d", year, month / 10, month%10, day/10,day%10);
		return str;
	}

	bool isLeapYear(){
		if (year % 4 == 0 && !(year % 100 == 0 && year % 400 != 0))
			return true;
		else 
			return false;
	}

	int monthDays(){
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			return 31;
		else if (month == 4 || month == 6 || month == 9 || month == 11)
			return 30;
		else if (isLeapYear())
			return 29;
		else
			return 28;
	}

	void toNextDay(){
		if (month == 12 && day == 31)
		{
			month = 1;
			day = 1;
			year++;
		}
		else if (day == monthDays())
		{
			day = 1;
			month++;
		}
		else
		{
			day++;
		}
	}
};

 