
#include "member.h"
#include "Time.h"




void  member::AllocateMemoryFanPage()
{

	physicSizeOfPage *= 2;
	status ** tempArry = new status*[physicSizeOfPage];
	for (int i = 0; i < logicSizeOfPage; i++)
	{
		tempArry[i] = MemberStatus[i];
	}
	delete[] MemberStatus;
	this->MemberStatus = tempArry;

}

void member::showLastTenFriendsStatuses()
{
	char *name;
	int flag = 0;

	if (logicSizeOfFriends == 0)
	{
		cout << "This user has no friends yet";
		return;
	}
	for (int d = 0; d <this->logicSizeOfFriends;d++ )
	{
		if (this->friends[d]->logicSizeOfStatus !=0)
			flag = 1;

	}
	if (flag == 0)
	{
		cout << "This user's friends are not so active - no posts found";
		return;
	}
	status *mostRecentStatus = nullptr, *currStatus;
	member *theWriterOfMostRecentStatus = nullptr;
	for (int i = 0; i < logicSizeOfFriends; i++)
	{
		if (friends[i]->logicSizeOfStatus != 0)
			friends[i]->whereToCheck = friends[i]->logicSizeOfStatus;
		else
			friends[i]->whereToCheck = NOTHINGTOCHECK;
	}
	for (int i = 0; i < 10; i++)
	{

		for (int j = 0; j < logicSizeOfFriends; j++)
		{
			if (friends[j]->whereToCheck != NOTHINGTOCHECK)
			{
				currStatus = friends[j]->MemberStatus[friends[j]->whereToCheck - 1];
				if (mostRecentStatus == nullptr)
				{
					mostRecentStatus = currStatus;
					theWriterOfMostRecentStatus = friends[j];
				}
				else if (mostRecentStatus != nullptr)
				{
					flag = mostRecentStatus->compare(currStatus);

					if (flag)
					{
						mostRecentStatus = currStatus;
						theWriterOfMostRecentStatus = friends[j];
					}

				}

			}
		}
		if (mostRecentStatus != nullptr)
		{
			name = theWriterOfMostRecentStatus->getName();
			cout << name << "'s post" << endl;
			mostRecentStatus->show();
		}
		if (theWriterOfMostRecentStatus)
		{
			if (theWriterOfMostRecentStatus->whereToCheck <= 1)
				theWriterOfMostRecentStatus->whereToCheck = NOTHINGTOCHECK;
			else
				theWriterOfMostRecentStatus->whereToCheck--;
			mostRecentStatus = nullptr;
		}

	}
}



member::member( Date birthday) 
{
	this->birthday = birthday;
}


void member::setBirthDay(int day, int month, int year)
{
	birthday.setDay(day);
	birthday.setMonth(month);
	birthday.setYear(year);
}
member::member(const member& other)
{
	int i, size = strlen(other.name);
	name = new char[size + 1];

	for (i = 0; i < size; i++)
	{
		name[i] = other.name[i];

	}
	name[i] = '\0';
	//strcpy(name, other.name);	
	this->birthday = other.birthday;
}



void member::operator+=(member * newfriend)
{
	int flag = 1, logicalsize;
	for (int i = 0; i < this->logicSizeOfFriends; i++)
	{
		if (this->friends[i] == newfriend)
		{
			cout << this->getName() << " and " << newfriend->getName() << " are already friends ";
			return;
		}
	}
	logicalsize = newfriend->logicSizeOfFriends;
	newfriend->friends[logicalsize] = this;
	this->friends[this->logicSizeOfFriends] = newfriend;
	logicSizeOfFriends++;
	newfriend->logicSizeOfFriends = newfriend->logicSizeOfFriends + 1;
	if (logicSizeOfFriends == physicSizeOfFriends)
		AllocateMemoryFriends();
	if (newfriend->logicSizeOfFriends == newfriend->physicSizeOfFriends)
		newfriend->AllocateMemoryFriends();
	
	cout << this->getName() << " and " << newfriend->getName() << " are now friends " << endl;
	return;
}



void member::operator+=(fanPage *page)
{
	int flag = 1, logicalsizeofpage;


	for (int i = 0; i < this->logicSizeOfPage; i++)
	{
		if (this->pageArr[i] == page)
		{
			cout << this->getName() << "already likes this page" << endl;
			return;
		}
	}
	
	this->pageArr[logicSizeOfPage] = page;
	logicalsizeofpage = this->pageArr[logicSizeOfPage]->logicSizeOfFriends;
	this->pageArr[logicSizeOfPage]->friends[logicalsizeofpage] = this;
	logicSizeOfPage++;

	if (this->logicSizeOfPage == this->physicSizeOfPage) //increase memory of page for followers
		this->AllocateMemoryFanPage();

	this->pageArr[logicSizeOfPage - 1]->logicSizeOfFriends++;
	if (this->pageArr[logicSizeOfPage - 1]->logicSizeOfFriends == this->pageArr[logicSizeOfPage - 1]->physicSizeOfFriends) //increase memory of page for followers
		this->pageArr[logicSizeOfPage - 1]->AllocateMemoryFriends();

	cout << this->getName() << " now like the page " << page->getName();

}




void member::showPages()
{
	if (logicSizeOfPage == 0)
	{
		cout << this->getName() << " doesn't like any page" << endl;
	}
	else
	{
		cout << this->getName() << " is following the page:" << endl;
		for (int i = 0; i < logicSizeOfFriends; i++)
		{
			cout << i << ". ";
			pageArr[i]->getName();
			cout << endl;
		}
	}
}

member::~member()
{
	delete[] name;
	delete[] friends;
	delete[] pageArr;
	delete[] MemberStatus;
}



