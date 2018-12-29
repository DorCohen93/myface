#include "fanPage.h"
#include "member.h"
#include <string.h>
using std::cout;
using std::endl;;

fanPage::fanPage(const fanPage& other) :entity()
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



fanPage::fanPage()
{
	this->name = NULL;

}

fanPage::fanPage(char *name)
{
	this->name = name;

}


fanPage::~fanPage()
{
	delete[]name;
	delete[]friends;
	delete[]MemberStatus;
}
