#ifndef _LIST_H
#define _LIST_H

#include <iostream>
using namespace std;
#include "ListNode.h"

class List
{
private:
	ListNode* _head;
	ListNode* _tail;
public:
	List();
	~List();

	// Gets
	ListNode* GetHead(); // First
	ListNode* GetTail(); // Last

	//methodes
	void MakeEmpty();
	bool IsEmpty();
	ListNode* FindByKey(int _key);
	void DeleteNode(int _key);
	void InsertAfter(const Person& _data, int _key, int keyToInsertAfter);
	void InsertToHead(const Person& _data, int _key);
	void InsertToTail(const Person& _data, int _key);
	ListNode* FindPlaceToinsertAfter(int _key, int& numOfComp);
	void SortedInsert(const Person& _data, int _key, int& numOfComp);
	void Print() const;
};

#endif // _LIST_H
#pragma once
