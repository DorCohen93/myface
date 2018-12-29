#include "Time.h"



Time::Time(int hours, int minutes)
{
	this->hours = hours;
	this->minutes = minutes;
}

Time::Time()
{
	this->hours = 1;
	this->hours = 1;


}
void Time::showTime()const
{
	cout << hours << ":" << minutes << endl;
}
void Time::sethour(int hour)
{
	this->hours = hour;
}
void Time::setminutes(int minutes)
{
	this->minutes = minutes;
}



