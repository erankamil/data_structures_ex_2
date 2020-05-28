#ifndef __BSTREENODE_H
#define __BSTREENODE_H

#include "Person.h"

class BSTreeNode
{
private:
	int _key;
	Person _data;
	BSTreeNode *_left, *_right;
public:
	BSTreeNode() = default;
	BSTreeNode(int _key, const  Person& _data, BSTreeNode* left, BSTreeNode* right);
	void SetKey(int _key);
	inline const int GetKey() const { return _key; }
	inline const Person&  GetData() const { return _data; }
	void InOrder();
	void PreOrder();
	void PostOrder();
	friend ostream& operator<<(ostream& os, const BSTreeNode& p);
	friend class BSTree;

};


#endif //__BSTREENODE_H
