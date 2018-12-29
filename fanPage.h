#pragma once
#ifndef __FANPAGE_H
#define __FANPAGE_H
#include <iostream>
#include "status.h"
#include "entity.h"

class fanPage : public entity
{
	friend class member; //why can't that be removed!?
private:


public:
	fanPage();
	fanPage(char * name);
	fanPage(const fanPage& other);
	char * getName() const
	{
		return name;

	}
	~fanPage();


};

#endif
