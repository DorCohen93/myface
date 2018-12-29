#pragma once
#ifndef __DATE_H
#define __DATE_H
#include <iostream>
using namespace std;
class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date(int day, int month, int year);
	void setDay(int day);
	void setMonth(int month);

	void setYear(int year);
	int getYear() const{ return year; }
	int getMonth()const { return month; }
	int getDay() const{ return day; }
	Date() = default;
	void ShowDate();
};
#endif//__DATE_H

