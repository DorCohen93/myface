#include "Facebook.h"

void Facebook::ShowMembers()
{
	member *tempforcast;
	for (int i = 0; i < LogicalNumberOfEntities; i++)
	{
		tempforcast = dynamic_cast<member*>(ArryOfEntities[i]);
		if(tempforcast)
			cout << i << " . " << tempforcast->getName() << endl; //will show only member type
	}

}


void Facebook::ShowFanPage()
{
	cout << "below you can see all the pages Facebook currently have" << endl;
	fanPage *tempforcast;
	for (int i = 0; i < LogicalNumberOfEntities; i++)
	{
		tempforcast = dynamic_cast<fanPage*>(ArryOfEntities[i]);
		if (tempforcast)
			cout << i << " . " << tempforcast->getName() << endl; //will show only member type
	}

}



void  Facebook::AllocateMemoryEntities()
{

	PhysicalNumberOfEntities *= 2;
	entity** tempemoryArr = new entity*[PhysicalNumberOfEntities];
	for (int i = 0; i < LogicalNumberOfEntities; i++)
	{
		tempemoryArr[i] = this->ArryOfEntities[i];
	}
	delete[] ArryOfEntities;
	this->ArryOfEntities = tempemoryArr;
}









void Facebook::LikePage()
{
	member *user;
	fanPage *page;
	int userindex, pageindex, flag;

	cout << endl << "From the below users, choose the number of the friend you want to add a page to" << endl;
	this->ShowMembers();
	cin >> userindex;
	user = this->GetMember(userindex);

	cout << "now, from the list below choose a page " << endl;
	this->ShowFanPage();
	cin >> pageindex;
	page = this->GetFanPage(pageindex);

	*user += page;
}



void Facebook::setfriendship()
{
	member *first, *second;
	int firstindex, secondindex, decision, flag=0;

	cout << endl << "From the below users, choose the numbers of the two you want to set as friends " << endl;
	this->ShowMembers();
	cout << "\nfirst member : ";
	cin >> firstindex;
	cout << "\nsecond member : ";
	cin >> secondindex;
	while (firstindex == secondindex)
	{
		cout << "you cannot be a friend of yourself ";
		cout << endl << "From the below users, choose the numbers of the two you want to set as friends " << endl;
		this->ShowMembers();
		cout << "\nfirst member : ";
		cin >> firstindex;
		cout << "\nsecond member : ";
		cin >> secondindex;
	}
	first = this->GetMember(firstindex);
	second = this->GetMember(secondindex);
	cout << "Please confirm you would like to set " << first->getName() << " and " << second->getName() << "as friends" << endl;
	cout << "Press 0 to abort, anything else to confirm" << endl;
	cin >> decision;
	if (decision != 0)
		*first+=second; //making them friends 

	return;
}



member *Facebook::GetMember(int index)const
{
	member *tempcast;
	tempcast = dynamic_cast<member*>( ArryOfEntities[index]);
	return tempcast;

}



int Facebook::GetNumOfEntities()const
{

	return LogicalNumberOfEntities;

}


int Facebook::GetNumOfMember()const
{

	return LogicalNumberOfMembers;

}



int Facebook::GetNumOfPages()const
{

	return LogicalNumberOfFanPage;

}

fanPage *Facebook::GetFanPage(int index) const
{

	fanPage *tempcast;
	tempcast = dynamic_cast<fanPage*>(ArryOfEntities[index]);
	return tempcast;

}

int Facebook::CheckNoDupName(char * name, int flag)
{
	int i = 0,DupName;
	member * tempforcast;
	for (i = 0; i < LogicalNumberOfEntities; i++)
	{
		tempforcast = dynamic_cast<member*>(ArryOfEntities[i]);
		if (tempforcast)
		{
			DupName = strcmp(ArryOfEntities[i]->getName(), name);
			if (DupName == 0)
			{
				cout << "this username is already taken, choose another one\n";
				return 1;
			}
		}
	}

	return 0;

}


void Facebook::AddMember()
{
	cout << "Hi, Welcome to the new Facebook, please enter your name" << endl;
	char TempName[20];
	int d, m, y, size,flagname=1;

	cin.ignore();
	cin.getline(TempName, 30);
	size = strlen(TempName);
	char *name = new char[size + 1];
	//cin.ignore();
	flagname = CheckNoDupName(TempName, flagname);
		while (flagname == 1)
	{
			//cin.ignore();
			cin.getline(TempName, 30);
			size = strlen(TempName);
			char *name = new char[size + 1];
			//cin.ignore();
		
			flagname = CheckNoDupName(TempName, flagname);
	}
	strcpy(name, TempName);
	cout << "Now, please enter your birthday, starting with day, month and year" << endl;
	cout << "day : ";
	cin >> d;
	cout << "month : ";
	cin >> m;
	cout << "year : ";
	cin >> y;
	while (d < 0 || d>30 || m > 12 || m < 0 || y>2018 || y < 1900)
	{
		cout << "please put the correct date\n";
		cin >> d >> m >> y;
	}
	Date birth(d, m, y);

	member(*NewMember) = new member();
	(*NewMember).setName(name);
	(*NewMember).setBirthDay(d, y, m);

	if (name != NULL && NewMember != NULL)
		cout << "user was added successfully :) enjoy your stay" << endl;

	ArryOfEntities[LogicalNumberOfEntities] = NewMember;
	(this->LogicalNumberOfEntities)++;
	(this->LogicalNumberOfMembers)++;
	if (LogicalNumberOfEntities == PhysicalNumberOfEntities)
		AllocateMemoryEntities();

}



void Facebook::AddFanFage()
{
	fanPage *NewFanPage;

	cout << "please enter the page's name - 20 letters maximum" << endl;
	char *name = new char[20];

	cin >> name;

	NewFanPage = new fanPage();
	(*NewFanPage).setName(name);


	if (name != NULL && NewFanPage != NULL)
		cout << "fanpage was added successfully :)" << endl;

	ArryOfEntities[LogicalNumberOfEntities] = NewFanPage;
	(this->LogicalNumberOfEntities)++;
	(this->LogicalNumberOfFanPage)++;
	if (LogicalNumberOfEntities == PhysicalNumberOfEntities)
		AllocateMemoryEntities();


}
Facebook::~Facebook()
{


//	entity ** ArryOfMember = new entity*[10];

	for (int i = 0; i < LogicalNumberOfEntities; i++)
	{
		delete[]ArryOfEntities[i];
	}

	delete[]ArryOfEntities;



}
