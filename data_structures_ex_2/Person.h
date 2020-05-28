#ifndef __PERSON_H
#define __PERSON_H


#include <iostream>
using namespace std;

class Person
{
private:
	int _id;
	char _name[128];
public:

	Person(const char* name, int id);
	Person(const Person& other);

	void SetName(const char* name);
	void SetID(int id);
	const char* GetName() const;
	int GetID() const;
	friend ostream& operator<<(ostream& os, const Person& p);
};


#endif //__PERSON_H