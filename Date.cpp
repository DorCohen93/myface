#include "Date.h"



Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}
void Date::setDay(int day)
{
	this->day = day;
}
void Date::setMonth(int month)
{
	this->month = month;
}

void Date::setYear(int year)
{
	this->year = year;
}
void Date::ShowDate()
{
	cout << " " << day << "/" << month << "/" << year;
}



