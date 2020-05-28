#define _CRT_SECURE_NO_WARNINGS

#include "BSTreeNode.h"
#include "Person.h"

BSTreeNode::BSTreeNode(int _key, const Person& _data, BSTreeNode* left, BSTreeNode* right) :_left(NULL), _right(NULL), _data(_data)
{
	SetKey(_key);
}
void BSTreeNode::SetKey(int _key)
{
	this->_key = _key;
}
void BSTreeNode::InOrder()
{
	if (this->_left)
		_left->InOrder();
	cout << *this;
	if (this->_right)
		_right->InOrder();
}
void BSTreeNode::PreOrder()
{
	cout << *this;
	if (this->_left)
		_left->PreOrder();
	if (this->_right)
		_right->PreOrder();
}
void BSTreeNode::PostOrder()
{
	if (this->_left)
		_left->PostOrder();
	if (this->_right)
		_right->PostOrder();
	cout << *this;
}
ostream& operator<<(ostream& os, const BSTreeNode& node)
{
	os << node._data;
	return os;
}
