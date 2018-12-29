
#pragma once
#ifndef __FACEBOOK_H
#define __FACEBOOK_H
#include "member.h"
#include "fanPage.h"
// Respect
class member;
class fanPage;

class Facebook
{
public:

	void AddMember();
	void AddFanFage();
	int GetNumOfMember()const;
	int GetNumOfPages()const;
	int GetNumOfEntities()const;
	member * GetMember(int index)const;
	fanPage* GetFanPage(int index)const;
	void setfriendship();
	void LikePage();
	//GetFanPage;
	void ShowMembers();
	void ShowFanPage();
	int CheckNoDupName(char * name, int flag);
	~Facebook();
	
private:

	int PhysicalNumberOfEntities = 1;
	int LogicalNumberOfMembers = 0;
	int LogicalNumberOfFanPage = 0;
	void  AllocateMemoryEntities();
	int LogicalNumberOfEntities = 0;

	entity **ArryOfEntities= new entity*[10];


};


#endif
