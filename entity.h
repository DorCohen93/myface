#pragma once
#ifndef __ENTITY_H
#define __ENTITY_H
#define NOTHINGTOCHECK -1
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include "Date.h"

#include "status.h"
#include <string.h>



class entity
{

protected:
	char *name;
	int logicSizeOfFriends = 0;
	int physicSizeOfFriends = 4;
	int logicSizeOfStatus = 0;
	int physicSizeOfStatus = 1;
	member ** friends = new member *[1];
	status ** MemberStatus = new status *[1];
	

	void  AllocateMemoryFriends();
	void  AllocateMemoryStatus();
	
public:


	entity() = default;
	
	void operator>(entity *other);
	entity(char name[20], member ** friends);
	entity(const entity& other);
	

	virtual char * getName() const
	{
		return name;

	}
	int  getlogicSizeOfStatus() const
	{
		return logicSizeOfStatus;

	}
	
	void setName(char *name);
	void WritePost();
	

	void showFriends();

	void showPosts();
	virtual ~entity();


};
#endif // __ENTITY_H