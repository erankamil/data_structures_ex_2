#ifndef _LIST_NODE_WITH_H
#define _LIST_NODE_WITH_H

#include <iostream>
#include "Person.h"

class ListNode
{

private:
	int _key;
	Person _data;
	ListNode* _next;

public:
	ListNode(const Person& _data, int _key);
	ListNode(const ListNode& i_other);

	// Gets
	ListNode* GetNext() const;
	int GetKey() const;
	Person GetData() const;

	friend class List;
};

#endif // _LIST_NODE_WITH_H

#pragma once
