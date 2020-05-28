#ifndef __BSTREE_H
#define __BSTREE_H

#include <iostream>
using namespace std;

#include "BSTreeNode.h"


class BSTree
{
private:
	BSTreeNode* _root;
private:
	void DeleteNodeOption1(BSTreeNode* parent, BSTreeNode* node_to_del);
	void DeleteNodeOption2(BSTreeNode* parent, BSTreeNode* node_to_del);
public:
	BSTree(Person** personArr, int size, int& numOfComp);
	~BSTree();

	inline BSTreeNode* GetRoot() const
	{
		return _root;
	}
	
	void PrintSmallerThanK(BSTreeNode* root, int k, int& numOfComp);
	BSTreeNode* Find(int _key);
	void Insert(Person& _data, int _key, int& numOfComp);
	void Delete(int _key);
	BSTreeNode* Min() const;
	BSTreeNode* Max()const;
	BSTreeNode* FindMaxInSubTree(BSTreeNode* root);
	void PrintTree()const;
	void MySwap(BSTreeNode** a, BSTreeNode** b);
	bool IsEmpty();
	void MakeEmpty();
	void DeleteTree(BSTreeNode* root);
};


#endif //__BSTREE_H