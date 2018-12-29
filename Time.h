#pragma once
#ifndef __TIME_H
#define __TIME_H



#include <iostream>
using namespace std;
class Time
{
private:
	friend class member;
	int hours;
	int minutes;
public:
	Time(int hours, int minutes);
	void showTime()const;
	void sethour(int hour);
	void setminutes(int minutes);
	int gethour() const{ return hours; }
	int getminutes() const{ return minutes; }
	Time();
};
#endif // 


