#pragma once
#ifndef __MEMBER_H
#define __MEMBER_H
#define NOTHINGTOCHECK -1
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include "Date.h"
#include "Facebook.h"
#include "status.h"
#include "fanpage.h"
#include <string.h>



class facebook;
class member : public entity{

private:
	Date birthday;
	int whereToCheck;
	int logicSizeOfPage = 0;
	int physicSizeOfPage = 4;
	fanPage ** pageArr = new fanPage *[1];

	void  AllocateMemoryFanPage();
public:


	member() = default;
	void showLastTenFriendsStatuses();

	member(Date birthday);
	member(const member& other);

	void operator+=(member *newfriend); //set two members as friends
	void operator+=(fanPage *page);     //set a member to follow a page

	void getBirthDay()     {this->birthday.ShowDate();}
	int getwheretocheck()  {	return whereToCheck; }
	char * getName() const {  return name;	}
	void setwheretocheck(int newchec) { whereToCheck= newchec; }
	void setBirthDay(int day, int month, int year);
	void showPages();

	~member();


};
#endif // __MEMBER_H