#include "status.h"
#pragma warning (disable : 4996)

const char* KINDS[] = { "text","photo","video" };


status::status() {
	Time PostTime;
	Date PostDate;
	this->post = nullptr;
	int decision;
	cout << "please choose the type of post you would like upload: " << endl << "0.text" << endl << "1.photo" << endl << "2.video\n";
	cin >> decision;
	while(decision != 0 && decision != 1&& decision != 2)
	{
		cout << "please choose again\n" << endl;
		cin >> decision;
	}
	this->kind = (KIND)decision;

	char text[30];
	int size;
	cout << "what on your mind today? " << endl;
	cin.ignore();
	cin.getline(text, 30);
	size = strlen(text);
	this->post = new char[size + 1];
	//cin.ignore();
	strcpy(this->post, text);


	//set the current time of the post

	time_t rawtime;
	tm timeinfo;
	time(&rawtime);
	errno_t result = localtime_s(&timeinfo, &rawtime);

	PostTime.sethour(timeinfo.tm_hour);
	PostTime.setminutes(timeinfo.tm_min);
	this->postTime = PostTime;
	PostDate.setDay(timeinfo.tm_mday);
	PostDate.setMonth(timeinfo.tm_mon + 1);
	PostDate.setYear(timeinfo.tm_year + 1900);
	this->postDate = PostDate;
}

char * status::GetTheStatus()const
{
	return this->post;

}
void status::show()
{
	if (this->kind == text)
	{
		cout << "the kind is: " << KINDS[kind] << endl << post << endl;
		this->postDate.ShowDate();
		cout << "   ";
		this->postTime.showTime();
	}
	if (this->kind == photo)
	{
		cout << "the kind is: " << KINDS[kind] << endl << post << endl;
		this->postDate.ShowDate();
		cout << "   ";
		this->postTime.showTime();
	}
	if (this->kind == video)
	{
		cout << "the kind is: " << KINDS[kind] << endl << post << endl;
		this->postDate.ShowDate();
		cout << "   ";
		this->postTime.showTime();
	}

	cout << "\n";
}

int status::compare(status *statusToCheck)
{
	if (postDate.getYear() < statusToCheck->postDate.getYear())
		return 1;
	else if (postDate.getMonth() < statusToCheck->postDate.getMonth())
		return 1;
	else if (postDate.getDay() < statusToCheck->postDate.getDay())
		return 1;
	else if (postTime.gethour() < statusToCheck->postTime.gethour())
		return 1;
	else if (postTime.getminutes() < statusToCheck->postTime.getminutes())
		return 1;
	else
		return 0;
}
bool status::operator==(status *post)
{
	int flag;
	flag=strcmp(this->post, post->post);
	if (flag == 0)
		return true; //same post
	else
		return false; // new post
}



Date status::GetStatusDate()const
{
	return this->postDate;

}
status::~status()
{
	delete[]post;
}
status::status(const status&other)
{
	this->kind = other.kind;
	this->postDate = other.postDate;
	this->postTime = other.postTime;
	int i, size = strlen(other.post);
	post = new char[size + 1];

	for (i = 0; i < size; i++)
	{
		post[i] = other.post[i];

	}
	post[i] = '\0';
}
