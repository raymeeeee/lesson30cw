#pragma once
#include<iostream>
#include<ctime>
using namespace std;

class Date
{
	int year;
	int month;
	int day;

	bool isLeapYear()const{
		return (year % 4 == 0 && year % 400 == 0 || year % 4 == 0 && year % 100 != 0);
	}
	int monthDays()const {
		switch (month)
		{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			return 31;
		case 4: case 6: case 9: case 11:
			return 30;
		case 2:
			return isLeapYear() ? 29 : 28;
		}

		return 0;
	}
	void nextDate() {
		if (day == 31 && month == 12)
		{
			day = 1;
			month = 1;
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
	void prevDate() {
		if (day == 1 && month == 1)
		{
			day = 31;
			month = 12;
			year--;
		}
		else if (day == 1)
		{
			month--;
			day = monthDays();
		}
		else
		{
			day--;
		}
	}

public:
	Date() {
		struct tm* tim = new tm;
		time_t tt = time(NULL);
		localtime_s(tim, &tt);

		day = tim->tm_mday;
		month = tim->tm_mon + 1;
		year = tim->tm_year + 1900;
	}
	Date(int day, int month, int year): year(year), month(month), day(day)
	{}

	//===============================//
	void setYear(int year){ this->year = year; }
	int getYear()const{ return year; }

	void setMonth(int month){ this->month = month; }
	int getMonth()const{ return month; }

	void setDay(int day){ this->day = day; }
	int getDay()const{ return day; }

	void showDate()const {
		cout << day / 10 << day % 10 << "." << month / 10 << month % 10 << "." << year << endl;
	}

	bool valid()const {
		if (day <= 0 || day > monthDays())
		{
			return false;
		}
		else if (month <= 0 || month > 12)
		{
			return false;
		}
		else
		{
			return true;
		}

		//Error chek
		cout << "ERROR" << endl;
		return false;
	}

	//   Operators    //
	bool operator == (const Date& obj)const& {
		return this->day == obj.day && this->month == obj.month && this->year == obj.year;
	}
	bool operator != (const Date& obj)const&{ return !(*this == obj); }
	bool operator > (const Date& obj)const& {
		if (this->year > obj.year)
		{
			return true;
		}
		else if (this->year == obj.year && this->month > obj.month)
		{
			return true;
		}
		else if (this->year == obj.year && this->month == obj.month && this->day > obj.day)
		{
			return true;
		}

		return false;
	}
	bool operator < (const Date& obj)const&{ return !(*this > obj) && *this != obj; }
	bool operator >= (const Date& obj)const&{ return (*this > obj) || *this == obj; }
	bool operator <= (const Date& obj)const&{ return (*this < obj) || *this == obj; }

	//--------- ОПЕРАТОРИ ПРИСВОЄННЯ ---------	
	Date& operator += (int days) // додати days днів до дати
	{
		for (int i = 0; i < days; i++)
		{
			this->nextDate();
		}
		return *this;
	}
	Date& operator -= (int days) // відняти days дні від дати
	{
		for (int i = 0; i < days; i++)
		{
			this->prevDate();
		}
		return *this;
	}
	Date& operator += (float months) // додати months місяців до дати
	{
		this->month += month;
		if (this->month > 12)
		{
			year += (this->month - 1) / 12;
			this->month = (this->month - 1) % 12 + 1;
		}
		return *this;
	}
	Date& operator -= (float months) // відняти months місяці від дати
	{
		this->month -= month;
		if (this->month <= 0) {

			year -= abs(12 - this->month) / 12;
			this->month = (12 + this->month - 1) % 12 + 1;

		}
		return *this;
	}
	Date& operator += (long years) // додати years років до дати
	{
		this->year += years;
		return *this;
	}
	Date& operator -= (long years) // відняти years років від дати
	{
		this->year -= years;
		return *this;
	}

	//--------- АРИФМЕТИЧНІ ОПЕРАТОРИ ---------
	Date operator + (int days)const& {
		Date tmp = *this;
		tmp += days;
		return tmp;
	}
	Date operator - (int days)const& {
		Date tmp = *this;
		tmp -= days;
		return tmp;
	}
	Date operator + (float months)const& {
		Date tmp = *this;
		tmp += months;
		return tmp;
	}
	Date operator - (float months)const& {
		Date tmp = *this;
		tmp -= months;
		return tmp;
	}
	Date operator + (long years)const& {
		Date tmp = *this;
		tmp += years;
		return tmp;
	}
	Date operator - (long years)const& {
		Date tmp = *this;
		tmp -= years;
		return tmp;
	}
		
	Date& operator -- ()  // prefix
	{
		this->prevDate();
		return *this;
	}
	Date operator -- (int)//postfix
	{
		Date tmp = *this;
		this->prevDate();
		return tmp;
	}
	Date& operator ++ () {
		this->nextDate();
		return *this;
	}
	Date operator ++ (int) {
		Date tmp = *this;
		this->nextDate();
		return tmp;
	}

	// Friends
	friend Date operator + (int days, const Date& a);
	friend Date operator - (int days, const Date& a);

	friend Date operator + (float months, const Date& a);
	friend Date operator - (float months, const Date& a);

	friend Date operator + (long years, const Date& a);
	friend Date operator - (long years, const Date& a);


	friend ostream& operator << (ostream& os, const Date& t);
	friend istream& operator >> (istream& is, Date& t);
};

Date operator + (int days, const Date& a) { return a + days; }
Date operator - (int days, const Date& a) { return a - days; }

Date operator + (float months, const Date& a){ return a + months; }
Date operator - (float months, const Date& a){ return a - months; }

Date operator + (long years, const Date& a){ return a + years; }
Date operator - (long years, const Date& a){ return a - years; }


ostream& operator << (ostream& os, const Date& t) {
	os << t.day / 10 << t.day % 10 << "." << t.month / 10 << t.month % 10 << "." << t.year;
	return os;
}
istream& operator >> (istream& is, Date& t) {
	do {
		cout << "dd mm yyyy:";
		is >> t.day >> t.month >> t.year;

	} while (!t.valid());
	return is;
}
 

