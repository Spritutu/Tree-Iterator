#pragma once
/************************************************************************
*Class: BST (Binary Sort Tree)
*
*Data Members:
*	a_type* data
		holds the passed in data.

*	key_type key
		holds the key for sorting into the tree.
		
*	Node*left
		pointer for the left child

*	Node*right
		pointer for the right child
*
*Constructors:
*	Node()
		default constructor. sets all the data members to 0;

*	Node(a_type *in_data, key_type in_key,Node*in_left,Node*in_right)
		default constructor. sets all the data members to their passed in counter parts.

*	~BST()
		destructor. deletes the memory stored at data.

*Mutators:
*	a_type GetData()
		returns data.

*	key_type GetKey()
		returns key.

*	Node*GetLeft()
		returns left.

*	void SetLeft(Node*in_node)
		sets left to in_node.

*	Node*GetRight()
		returns right.

*	void SetRight(Node*in_node)
		sets right to in_node

*Methods:
*

*************************************************************************/
template<typename a_type,typename key_type>
class Node
{
private:
	a_type* data;
	key_type key;
	Node*left;
	Node*right;
public:
	Node();
	Node(a_type *in_data, key_type in_key,Node*in_left,Node*in_right);
	~Node();
	a_type GetData();
	key_type GetKey();
	Node*GetLeft();
	void SetLeft(Node*in_node);
	Node*GetRight();
	void SetRight(Node*in_node);
};

#include "Node.cpp"