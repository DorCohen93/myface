#include <iostream>
using namespace std;
#include "Date.h"
#include "Facebook.h"
#include "member.h"
#include "Time.h"
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
//trying
int menu(Facebook *myFace)
{

	cout << endl << "1. add member \n2. add fan page \n3. add status\n4. show last 10 statuses\n5. add friendship\n6. add fan to page\n7. show all members and pages\n8. show all friends of member\n9. show all fans of page\n10.extra\n11.exit" << endl;

	int choice = 0;
	cin >> choice;
	while (choice > 11 || choice < 1)
	{
		cout << "please make sure to enter the correct number\n";
		cin >> choice;

	}
	system("cls");
	if (choice == 1)
	{
		(*myFace).AddMember();
	}
	if (choice == 2)
	{

		(*myFace).AddFanFage();
	}

	if (choice == 3)
	{
		int  index;
		member * user;
		fanPage *fan;
		cout << "choose fanPage or members\n1.members\n2.fanpages" << endl;
		cin >> index;

		if (index == 1)
		{
			if ((*myFace).GetNumOfMember() == 0)
			{
				cout << "there are no active users";
				getchar();
				return 3;

			}
			(*myFace).ShowMembers();
			cout << "Choose the member you would like to post a status from" << endl;

			cin >> index;
			user = (*myFace).GetMember(index);
			user->WritePost();
		}

		else
		{
			if ((*myFace).GetNumOfPages() == 0)
			{
				cout << "there are no active Fan Pages";
				getchar();
				return 3;

			}
			(*myFace).ShowFanPage();
			cout << "Choose the member you would like to post a status from" << endl;

			cin >> index;
			fan = (*myFace).GetFanPage(index);
			fan->WritePost();
		}



	}

	if (choice == 4)
	{
		int index;
		member * user;
		cout << "Choose the member which you'd like to see the last 10 statuses his friends posted" << endl;
		(*myFace).ShowMembers();
		cin >> index;
		user = (*myFace).GetMember(index);
		user->showLastTenFriendsStatuses();

	}

	if (choice == 5)
	{
		//	cout << endl << "From the below users, choose one that you will add him a friend:" << endl;
		if ((*myFace).GetNumOfMember() < 2)
		{
			cout << "there are less than 2 member, we are going to the main screen";
			getchar();
			return 5;
		}
		myFace->setfriendship();
	}


	if (choice == 6)
	{
		if ((*myFace).GetNumOfPages() == 0)
		{
			cout << "there are still no fan pages at the site, back to the main screen";
			getchar();
			return 6;
		}
		myFace->LikePage();
	}
	if (choice == 7)
	{
		cout << endl << "Facebook members:" << endl;
		(*myFace).ShowMembers();
		cout << endl << "Facebook pages:" << endl;
		(*myFace).ShowFanPage();
	}



	if (choice == 8)
	{
		member *TheMember;
		int NumOfFriend;
		cout << endl << "choose the member you'd like to check his friends" << endl;
		(*myFace).ShowMembers();
		cin >> NumOfFriend;
		TheMember = (*myFace).GetMember(NumOfFriend);

		(*TheMember).showFriends();
	}
	if (choice == 9)
	{
		int NumOfPage;
		fanPage *page;
		cout << endl << "choose the member you'd like to check his friends" << endl;
		(*myFace).ShowFanPage();
		cout << "your decision : ";
		cin >> NumOfPage;
		page = (*myFace).GetFanPage(NumOfPage);
		(*page).showFriends();
		cout << endl << endl;
	}

	if (choice == 10)
	{
		int firstindex, secondindex;
		entity *first, *second;
		cout << endl << "time to compare two facebook entities based on number of followers" << endl;
		myFace->ShowMembers();
		cout << endl << "From the below users, choose the numbers of the two you want to compare " << endl;
		myFace->ShowMembers();
		cout << "\nfirst member : ";
		cin >> firstindex;
		cout << "\nsecond member : ";
		cin >> secondindex;
		first=myFace->GetMember(firstindex);
		second=myFace->GetMember(secondindex);
		*first > second;
	}


	return choice;
}

void main()
{
	cout << "WELCOME TO THE NEW GENERATION OF FACEBOOK!!!" << endl << endl;
	Facebook myface;
	int choice;
	choice = menu(&myface);
	while (choice < 10 && choice>0)
	{
		choice = menu(&myface);

	}
}