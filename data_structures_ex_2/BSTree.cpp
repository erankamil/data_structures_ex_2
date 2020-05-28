#include "BSTree.h"

BSTree::BSTree(Person** personArr, int size, int& numOfComp)
{
	for (int i = 0; i < size; i++)
	{
		int currentKey = personArr[i]->GetID();
		this->Insert(*personArr[i], currentKey, numOfComp);
	}
}

BSTree::~BSTree()
{
	if (_root)
		DeleteTree(_root);
};

// the methode find the _key and returned  the BST Node (null if not found)
BSTreeNode* BSTree::Find(int _key)
{
	BSTreeNode* temp = _root;
	while (temp)
	{
		if (_key == temp->_key) // we found the node with the _key 
			return temp;
		else if (_key < temp->GetKey()) // the ascii value of our _key less than the node _key, need to go to the left child
			temp = temp->_left;
		else
			temp = temp->_right;
	}
	return NULL;
}
bool  BSTree::IsEmpty()
{
	if (!_root)
		return true;
	return false;

}
void BSTree::MakeEmpty()
{
	_root = NULL;
}
// delete all the allocated nodes and the root
void  BSTree::DeleteTree(BSTreeNode* root)
{
	if (root->_left)
		DeleteTree(root->_left);
	if (root->_right)
		DeleteTree(root->_right);
	delete root;
}
// the methode create Node from _data and _key and inserts to the BSTree
void BSTree::Insert(Person& _data, int _key, int& numOfComp)
{
	if (Find(_key) != NULL)
		cout << "Error:_key already exist" << endl;

	BSTreeNode* temp = _root; // current node in tree
	BSTreeNode* parent = NULL; // parent of temp
	BSTreeNode* newNode; // new allocated node

	while (temp) // find parent of new node
	{
		parent = temp;
		if (_key < temp->_key)
		{
			numOfComp++;
			temp = temp->_left;
		}
		else
		{
			numOfComp++;
			temp = temp->_right;
		}
	}
	newNode = new BSTreeNode(_key, _data, NULL, NULL); // allocate new node
	if (parent == NULL)
		_root = newNode; // insert newNode as root
	else if (_key < parent->_key)
	{
		numOfComp++;
		parent->_left = newNode; //insert as left child
	}
	else
	{
		numOfComp++;
		parent->_right = newNode; //insert as right child
	}
}
// node_to_del has maximum 1 child
void BSTree::DeleteNodeOption1(BSTreeNode* parent, BSTreeNode* node_to_del)
{ 
	if (node_to_del->_left)
	{
		if (node_to_del == parent->_left) // we delete the left child of the parent
			parent->_left = node_to_del->_left; // Set the new child of the parent
		else // node_to_del is the right chid of parent
			parent->_right = node_to_del->_left;
	}
	else if (node_to_del->_right) // node_to_del has right child
	{
		if (node_to_del == parent->_left) // we delete the left child of the parent
			parent->_left = node_to_del->_right; // Set the new child of the parent
		else // node_to_del is the right chid of parent
			parent->_right = node_to_del->_right;
	}
	delete[] node_to_del;

}
// node_to_del has 2 children
void BSTree::DeleteNodeOption2(BSTreeNode* parent, BSTreeNode* node_to_del)
{
	BSTreeNode* max_left = FindMaxInSubTree(node_to_del->_left);
	MySwap(&node_to_del, &max_left); // swap between the
									 //node_to_del = max_left;
	/*Delete(max_left->_key);*/
}
void BSTree::MySwap(BSTreeNode** a, BSTreeNode** b)
{
	BSTreeNode* temp = *a;
	*a = *b;
	*b = temp;
}
// the methode deletes the Node with the _key 
void BSTree::Delete(int _key)
{
	BSTreeNode* tmp = _root, *parent = NULL, *node_to_del = NULL;
	while (!node_to_del) // find the node we want to delete and his parent
	{
		if (_key == tmp->_key) // we found the node with the _key 
			node_to_del = tmp;
		else if (_key < tmp->GetKey()) // the ascii value of our _key less than the node _key, need to go to the left child
		{
			parent = tmp;
			tmp = tmp->_left;
		}
		else
		{
			parent = tmp;
			tmp = tmp->_right;
		}
	}
	if (node_to_del->_left == NULL || node_to_del->_right == NULL) // option 1
		DeleteNodeOption1(parent, node_to_del);
	else
		DeleteNodeOption2(parent, node_to_del);

}
// finding max node in subtree left
BSTreeNode* BSTree::FindMaxInSubTree(BSTreeNode* root)
{ 
	BSTreeNode* curr_max = NULL;
	while (root)
	{
		curr_max = root;
		root = root->_right;
	}
	return curr_max;
}
void BSTree::PrintTree() const
{
	if (_root)
		_root->InOrder();
}
// the methode prints the k nodes that their _key smallest than k
void BSTree::PrintSmallerThanK(BSTreeNode* root, int k, int& numOfComp)
{
	// in case we got to _key which >= to k we just call the left child
	numOfComp++;
	if (root->_key >= k) 
	{
		if (root->_left)
			PrintSmallerThanK(root->_left, k, numOfComp);
	}
	// else we want to print inorder the tree
	else 
	{
		if (root->_left)
			PrintSmallerThanK(root->_left, k, numOfComp);
		cout << *root;
		if (root->_right)
			PrintSmallerThanK(root->_right, k, numOfComp);
	}
}
BSTreeNode* BSTree::Max() const
{
	if (_root)
	{
		BSTreeNode* temp = _root;
		BSTreeNode* parent = NULL;
		while (temp)
		{
			parent = temp;
			temp = temp->_right;
		}
		return parent;
	}
	return NULL;
}
BSTreeNode* BSTree::Min() const
{
	if (_root)
	{
		BSTreeNode* temp = _root;
		BSTreeNode* parent = NULL;
		while (temp)
		{
			parent = temp;
			temp = temp->_left;
		}
		return parent;
	}
	return NULL;
}