
#include "entity.h"
#include "Time.h"
#include "facebook.h"



void  entity::AllocateMemoryFriends()
{

	physicSizeOfFriends *= 2;
	member** tempArry = new member*[physicSizeOfFriends];
	for (int i = 0; i < logicSizeOfFriends; i++)
	{
		tempArry[i] = friends[i];
	}
	delete[] friends;
	this->friends = tempArry;

}




void  entity::AllocateMemoryStatus()
{

	physicSizeOfStatus *= 2;
	status ** tempArry = new status*[physicSizeOfStatus];
	for (int i = 0; i < logicSizeOfStatus; i++)
	{
		tempArry[i] = MemberStatus[i];
	}
	delete[] MemberStatus;
	this->MemberStatus = tempArry;

}




entity::entity(char *name, member ** friends)
{
	this->name = name;

}

void entity::setName(char *name)
{
	this->name = name;
}

entity::entity(const entity& other)
{
	int i, size = strlen(other.name);
	name = new char[size + 1];

	for (i = 0; i < size; i++)
	{
		name[i] = other.name[i];

	}
	name[i] = '\0';
	//strcpy(name, other.name);	
}


void entity::WritePost()
{
	int i = 0,duppost=0;
	status * newstatus = new status[1];
	this->MemberStatus[this->logicSizeOfStatus] = newstatus;
	for (i = 0; i < logicSizeOfStatus; i++)
	{
		duppost=*(this->MemberStatus[i]) != newstatus;
	
		if (duppost == 0) //means it is the same post
		{
			cout << "unfortunately " << this->getName() << " already has the same post in his wall, nothing was added";
			delete[]this->MemberStatus[this->logicSizeOfStatus];
			return;
		}
	}
	logicSizeOfStatus++;
	if (logicSizeOfStatus == physicSizeOfStatus)
		AllocateMemoryStatus();
}



void entity::showFriends()
{
	if (logicSizeOfFriends == 0)
	{

		cout << this->getName() << " has no Facebook friends" << endl; ///fix this!!!!
	}
	else
	{
		cout << this->getName() << "'s Facebook's friends are:" << endl;
		for (int i = 0; i < logicSizeOfFriends; i++)
		{
			cout<<i <<".  "<<friends[i]->getName()<<endl;
			//cout << i << ". " <<this->friends->show << endl;
		}
	}
}


void entity::showPosts()
{
	system("cls");
	char a;
	Date date;
	if (logicSizeOfStatus == 0)
	{

		cout << this->getName() << " doesn't have any posts" << endl;
	}
	else
	{
		cout << this->getName() << "'s posts:" << endl;
		for (int i = 0; i < logicSizeOfStatus; i++)
		{
			cout << i << ". ";
			cout << this->MemberStatus[i]->GetTheStatus();
			date = this->MemberStatus[i]->GetStatusDate();
			cout << "   posted on";
			date.ShowDate();
			cout << endl;
		}
	}

	cout << endl << endl << endl << "press any key to go to the main screen";
	cin >> a;
	system("cls");
}


void  entity::operator>(entity *other)
{
	if (logicSizeOfFriends > other->logicSizeOfFriends)
		cout << this->getName() << "'s number of followers ("<< logicSizeOfFriends <<") is higher than " << other->getName() << "'s ("<< other->logicSizeOfFriends <<")\n";
	if (logicSizeOfFriends < other->logicSizeOfFriends)
		cout << other->getName() << "'s number of followers (" << other->logicSizeOfFriends << ") is higher than " << this->getName() << "'s ("<< logicSizeOfFriends <<")\n";
	if (logicSizeOfFriends == other->logicSizeOfFriends)
		cout <<"both " <<other->getName() << " and " << this->getName() <<  " as the same number of followers - "<<logicSizeOfFriends<<"\n";
}

 entity::~entity()
{
	delete[] name;
	delete[] friends;
	delete[] MemberStatus;
}
