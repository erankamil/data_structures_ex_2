#include "List.h"


List::List()
{
	this->_head = this->_tail = nullptr;
}
List::~List()
{
	MakeEmpty(); // call makeEmpty fucntion to delete the allocate memory
}
ListNode* List::GetHead()
{
	return this->_head;
}
ListNode* List::GetTail()
{
	return this->_tail;
}

void List::MakeEmpty()
{
	ListNode* currNode = this->_head, *temp;
	while (currNode)
	{
		temp = currNode;
		currNode = currNode->_next;
		delete temp; // delete each node in the List
	}
	_head = _tail = nullptr; // Set the List to be empty
}

bool List::IsEmpty()
{
	if (!_head) // the _head=nullptr -> List empty
		return true;
	else
		return false;
}

// the function Gets _key to find in the List
ListNode* List::FindByKey(int keyToFind)
{
	ListNode* currNode = this->_head;

	//runs over the List untuil we found the item or we finished the List
	while ((currNode) && (currNode->_key != keyToFind))
	{
		currNode = currNode->_next;
	}
	return currNode; // if we didnt find the item, currNode will be nullptr
}

//the function Gets _key to delete from the List
void List::DeleteNode(int keyToDelete)
{
	ListNode* currNode = this->_head, *prev = nullptr, *nodeToDelete;

	if (IsEmpty()) // check first if the List empty
	{
		cout << "EROR: THE LIST IS EMPTY, CANNOT DELETE.";
		exit(1);
	}

	//check if the item we want to delete is the _head - delete from _head of List
	if (this->_head->_key == keyToDelete)
	{
		nodeToDelete = _head;
		this->_head = this->_head->_next; // Set the new _head of the List

		if (!_head)
			_tail = nullptr; // the List is empty now
	}

	//check if the item to delete is the _tail of the List - delete from _tail
	else if (this->_tail->_key == keyToDelete)
	{
		nodeToDelete = _tail;
		while (currNode->_next != _tail) // Get the node before the _tail node
		{
			currNode = currNode->_next;
		}
		_tail = currNode; // update the _tail of the List
		_tail->_next = nullptr;
	}

	else            // delete from inner place
	{
		// find the prev node and the node we want to delete
		while (currNode && (currNode->_key != keyToDelete))
		{
			prev = currNode;
			currNode = currNode->_next;
		}

		if (!currNode) 
		{
			exit(1);
		}

		nodeToDelete = currNode;
		// Set the _next(pointer) of prev to the node after the node to delete
		prev->_next = currNode->_next;
	}

	delete nodeToDelete; // delete the node 
}


void List::InsertAfter(const Person& _data, int _key, int keyToInsertAfter)
{
	ListNode* currNode = this->_head;
	ListNode* newNode = new ListNode(_data, _key);

	if (keyToInsertAfter == this->_tail->_key) // insert after _tail
	{
		this->_tail->_next = newNode;
		this->_tail = newNode;
	}
	else   // insert to inner place
	{
		while (currNode && (currNode->_key != keyToInsertAfter))
		{
			currNode = currNode->_next;
		}

		if (!currNode)
		{
			exit(1);
		}

		newNode->_next = currNode->_next;
		currNode->_next = newNode;
	}
}

//the function alloctes new node and inserts it to the _head of the List
void List::InsertToHead(const Person& _data, int _key)
{

	ListNode* newNode = new ListNode(_data, _key);

	newNode->_next = this->_head;
	this->_head = newNode;
	if (_tail == nullptr)//List is empty
		_tail = newNode;
}

//the function alloctes new node and inserts it to the _tail of the List
void List::InsertToTail(const Person& _data, int _key)
{
	ListNode* newNode = new ListNode(_data, _key);
	if (IsEmpty()) // List is empty
	{
		_head = _tail = newNode;
	}
	else // the List is not empty
	{
		this->_tail->_next = newNode;
		this->_tail = newNode;
	}
}

void List::Print() const
{
	ListNode* currNode = this->_head;

	while (currNode)
	{
		cout << currNode->_key << " " << currNode->_data.GetName() << endl;
		currNode = currNode->_next;
	}

}

ListNode* List::FindPlaceToinsertAfter(int _key, int& numOfComp)
{
	ListNode* currNode = this->_head;
	ListNode* prevNode = nullptr;

	//runs over the List until we found the first item bigger than cuurNode
	while ((currNode) && (currNode->_key < _key))
	{
		prevNode = currNode;
		currNode = currNode->_next;
		numOfComp++;
	}
	numOfComp++;
	return prevNode; // if we didnt find the item, prevNode will be nullptr

}
void List::SortedInsert(const Person& _data, int _key, int& numOfComp)
{
	ListNode* nodeToInsertAfter = FindPlaceToinsertAfter(_key, numOfComp);
	if (!nodeToInsertAfter)
	{
		this->InsertToHead(_data, _key);
	}
	else if (nodeToInsertAfter == this->_tail)
	{
		this->InsertToTail(_data, _key);
	}
	else
	{
		this->InsertAfter(_data, _key, nodeToInsertAfter->_key);
	}
}