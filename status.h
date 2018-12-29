#pragma once
#ifndef __STATUS_H
#define __STATUS_H
#include <ctime>
#include "Date.h"
#include "Time.h"

enum KIND { text, photo, video };
class status
{
	friend class member;

private:
	char * post;
	Date postDate;
	Time postTime;
	KIND kind;


public:
	status();
	status(const status&other);
	int compare(status *statusToCheck);
	void show() ;
	char *GetTheStatus() const;
	Date GetStatusDate() const;
	bool operator==(status *post);

	bool operator!=(status *post){
		return !(*this == post); //return the opposite of the == function
	}
	~status();
};
#endif
