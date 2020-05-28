#include "ListNode.h" 

ListNode::ListNode(const Person& _data, int _key) :_data(_data)
{
	this->_key = _key;
	this->_next = nullptr;
}

ListNode::ListNode(const ListNode& other) :_data(_data)
{
	this->_key = other._key;
	this->_next = other._next;
}

ListNode* ListNode::GetNext() const
{
	return this->_next;
}
int ListNode::GetKey() const
{
	return this->_key;
}
Person ListNode::GetData() const
{
	return this->_data;
}