#include <iostream>
#include "BSTree.h"
#include "Person.h"
#include "System.h"

#include <stdlib.h>

#define MAX 128

using namespace std;
bool checkValidId(int idToCheck, Person** personArr, int currentSize);
bool checkValidName(char* inputNameStrToCheck);
void cleanBuffer();

int main()
{
	char name[128];
	int id, size, k;
	cin >> size;
	Person** personArr = new Person*[100];
	for (int i = 0; i < size; i++)
	{
		cin >> id;
		getchar();
		cin.getline(name, MAX);
		if (checkValidName(name) == false || checkValidId(id, personArr, i) == false)
		{
			cout << "Invalid Input";
			exit(1);
		}
	
		Person personToAdd(name, id);
		personArr[i] = new Person(personToAdd);
	}
	cin >> k;
	System ex_2(personArr, size, k);
	ex_2.Run();
	return 0;
}

//check if there is same id in the array
bool checkValidId(int idToCheck, Person** personArr, int currentSize)
{
	bool isValid = true;
	for (int i=0; i < currentSize && isValid == true; i++)
	{
		if (personArr[i]->GetID() == idToCheck)
		{
			isValid = false;
		}
	}
	return isValid;
}

// checking if the input is only name and family name with one space in between them 
// chacking if every char is a letter exept one space in the middle.
 bool checkValidName(char* inputNameStrToCheck)
{
	bool seenASpace = false;
	int i = 0;
	while (inputNameStrToCheck[i] != '\0')
	{
		if (inputNameStrToCheck[i] == ' ')
		{
			if (!seenASpace) // first space
			{
				seenASpace = true;
			}
			else // second space
			{
				return false;
			}
		}
		else if (((inputNameStrToCheck[i] >= 'a' &&  inputNameStrToCheck[i] <= 'z') == false) &&
			((inputNameStrToCheck[i] >= 'A' &&  inputNameStrToCheck[i] <= 'Z') == false)) // if the char is not a letter

		{
			return false;
		}
		i++;
	}

	if (i <= 3 || !seenASpace || inputNameStrToCheck[i - 1] == ' ') // check if there were space in the string, if it not too short, and if the space is not last char. 
	{
		return false;
	}
}
 void cleanBuffer()
 {
	 int c;
	 do
	 {
		 c = getchar();
	 } while (c != EOF && c != '\n');
 }