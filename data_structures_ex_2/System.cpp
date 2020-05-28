#include "System.h"


System::System(Person** personArr, int size, int k) 
{
	this->_personArr = personArr;
	this->_size = size;
	this->_k = k;
}

System::~System()
{
	for (int i = 0; i < _size; i++)
	{
		delete _personArr[i];
	}
	delete[] _personArr;
}

void System::Run() 
{
	cout << "\n";
	int numOfComp1 = NaivePrint();
	cout << endl;
	int numOfComp2 = BSTPrint();
	cout << endl;
	int numOfcomp3 = PrintBySort();
	cout << endl;
	cout<<"NaivePrint:"<< numOfComp1<<" comparisons\n\n";
	cout << "BSTPrint:" << numOfComp2 << " comparisons\n\n";
	cout << "PrintBySort: " << numOfcomp3 << " comparisons\n\n";
}
int System::NaivePrint()
{
	List* lst = new List();
	int numOfComp = 0;
	for (int i = 0; i < _size; i++)
	{
		
		int currentKey = _personArr[i]->GetID();
		if (currentKey < _k)
		{
			numOfComp++;
			lst->SortedInsert(*_personArr[i], currentKey, numOfComp);
		}
		numOfComp++;

	}
	lst->Print();
	lst->MakeEmpty();
	return numOfComp;
}
int System::BSTPrint()
{
	int numOfComp = 0;
	BSTree* tr = new BSTree(_personArr, _size, numOfComp);//////////retrn here
	tr->PrintSmallerThanK(tr->GetRoot(), _k, numOfComp);
	delete tr;
	return numOfComp;
}

int System::PrintBySort()
{
	int numOfComp = 0;
	QuickSort( 0, _size-1, numOfComp);
	PrintSmallerThanK(numOfComp);
	return numOfComp;
}

void System::QuickSort(int left, int right, int& numOfComp)
{
	if (left >= right)
		return;
	else
	{
		int pivot = Partition(left, right, numOfComp);
		QuickSort(left, pivot - 1, numOfComp);
		QuickSort(pivot + 1, right, numOfComp);
	}
}

int System::Partition(int left, int  right, int&numCop)
{
	int pivotID = _personArr[right]->GetID();
	int i = (left - 1);  // Index of smaller element 

	for (int j = left; j <= right - 1; j++)
	{
		// If current element is smaller than or 
		// equal to pivot 
		if (_personArr[j]->GetID() <= pivotID)
		{
			i++;    // increment index of smaller element 
			Swap(&_personArr[i], &_personArr[j]);
		}
		numCop++; // count the comparisons 
	}
	Swap(&_personArr[i + 1], &_personArr[right]); // the position of the pivot is i+1 in the array after the loop 
	return (i + 1);
}

void System::Swap(Person** a, Person** b)
{
	Person* temp = *a;
	*a = *b;
	*b = temp;
}

void System::PrintSmallerThanK(int& numOfComp)
{
	int i = 0;
	while (i < _size && _personArr[i]->GetID() < _k)
	{
		cout << *_personArr[i];
		numOfComp++;
		i++;
	}
	numOfComp++;
}