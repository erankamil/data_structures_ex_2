#pragma warning (disable: 4996)
#include "Person.h"


Person::Person(const char* name, int id)
{
	SetName(name);
	SetID(id);
}
Person::Person(const Person& other)
{
	SetName(other._name);
	SetID(other._id);
}
void Person::SetName(const char* name)
{
	int i = 0;
	while (name[i] != '\0')
	{
		_name[i] = name[i];
		i++;
	}
	_name[i] = '\0';

}
void Person::SetID(int id)
{
	this->_id = id;
}
int  Person::GetID() const
{
	return _id;
}
const char* Person::GetName() const
{
	return _name;
}
ostream& operator<<(ostream& os, const Person& p)
{
	os <<p._id<< " " << p._name<<"\n";
	return os;
}