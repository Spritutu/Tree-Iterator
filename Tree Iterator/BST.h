#pragma once
#include "Node.h"
/************************************************************************
*Class: BST (Binary Sort Tree)
*
*Data Members:
*	Node<a_type,key_type>*Root
*		Pointer to the root node
*
*Constructors:
*	BST()
		default constructor. sets root to 0;

*	BST(a_type *in_data, key_type in_key)
		default constructor. creates a new node at the root with the passed in data and key

*	~BST()
		destructor. deletes the root then sets it to 0.

*Mutators:
*	Node<a_type,key_type>* GetRoot()
		returns private data member Root.

*Methods:
*	void Insert(Node<a_type,key_type>*root, a_type *in_data, key_type in_key)
		creates a new node and places it in the appropriate place in the tree.

*	void Delete(Node<a_type,key_type>* current, key_type in_key)
		searches the tree for the correct node then removes it and maintains tree structure.

*	void Purge()
		deletes every node in the tree.

*	int Height(Node<a_type, key_type>*root)
		returns the height of the tree.

*	void InOrder(Node<a_type, key_type>*current, bool output=false)
		traverses the tree from lowest key to highest and if output is true outputs the value to the console. output defaults to false.

*	void PreOrder(Node<a_type, key_type>*current, bool output=false)
		traverses the tree going down the left branches first moving to the right and if output is true outputs the value to the console. output defaults to false.

*	void PostOrder(Node<a_type, key_type>*current, bool output=false)
		traverses the tree from furthest children going up and if output is true outputs the value to the console. output defaults to false.

*	void BreadthFirst(Node<a_type, key_type>*current, bool output=false);
		traverses the tree level by level starting at the root and going down if output is true outputs the value to the console. output defaults to false.

*	Node<a_type, key_type>* FindMin(Node<a_type, key_type>*root)
		finds the smallest key from a given node by traveling down the left branch

*	Node<a_type, key_type>* FindAndDetachMin(Node<a_type, key_type>*root)
		finds the the smallest child and removes it from the tree to return.
		
*	void ReplaceParent(Node<a_type, key_type>* parent, Node<a_type, key_type>* child)
		replaces the parent with the child then deletes the old parent.

*************************************************************************/
template<typename a_type, typename key_type>
class BST
{
private:
	Node<a_type,key_type>*Root;
public:
	BST();
	BST(a_type *in_data, key_type in_key);
	~BST();

	void Insert(Node<a_type,key_type>*root, a_type *in_data, key_type in_key);
	void Delete(Node<a_type,key_type>* current, key_type in_key);
	void Purge();
	int Height(Node<a_type, key_type>*root);

	void InOrder(Node<a_type, key_type>*current, bool output=false);
	void PreOrder(Node<a_type, key_type>*current, bool output=false);
	void PostOrder(Node<a_type, key_type>*current, bool output=false);
	void BreadthFirst(Node<a_type, key_type>*current, bool output=false);

	Node<a_type, key_type>* FindMin(Node<a_type, key_type>*root);
	Node<a_type, key_type>* FindAndDetachMin(Node<a_type, key_type>*root);
	void ReplaceParent(Node<a_type, key_type>* parent, Node<a_type, key_type>* child);
	Node<a_type,key_type>* GetRoot();
};
#include "BST.cpp"

