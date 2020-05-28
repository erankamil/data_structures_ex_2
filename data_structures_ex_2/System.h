#ifndef __SYSTEM_H
#define __SYSTEM_H
#include "Person.h"
#include "BSTree.h"
#include "List.h"

#include <iostream>
using namespace std;

class System
{
private:
	Person** _personArr;
	int _size;
	int _k;
public:
	System(Person** personArr, int size, int k);
	~System();

	void Run();
	int NaivePrint();
	int BSTPrint();
	int PrintBySort();
	void QuickSort(int left, int right, int& numOfComp);
	int Partition(int left, int  right, int&numCop);
	void Swap(Person** a, Person** b);
	void PrintSmallerThanK(int& numOfComp);
};
#endif // !__SYSTEM_H
