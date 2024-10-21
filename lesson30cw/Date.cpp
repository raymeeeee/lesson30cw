#include "Date.h"


Date operator + (int days, const Date& a) { return a + days; }
Date operator - (int days, const Date& a) { return a - days; }

Date operator + (float months, const Date& a) { return a + months; }
Date operator - (float months, const Date& a) { return a - months; }

Date operator + (long years, const Date& a) { return a + years; }
Date operator - (long years, const Date& a) { return a - years; }


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
