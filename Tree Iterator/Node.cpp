#include "Node.h"

/******************************************************
*   Purpose:  default constructor for Node

*         Entry:  none

*         Exit: sets all data members to 0
*******************************************************/
template<typename a_type, typename key_type>
inline Node<a_type, key_type>::Node()
{
	data = 0;
	key = 0;
	left = 0;
	right = 0;
}

/******************************************************
*   Purpose:  default constructor for Node

*         Entry:  passed in data, a key for sorting, and a left and right child

*         Exit: sets all the data members to their passed in counter parts
*******************************************************/
template<typename a_type, typename key_type>
Node<a_type, key_type>::Node(a_type *in_data, key_type in_key, Node * in_left, Node * in_right)
{
	data = in_data;
	key = in_key;
	left = in_left;
	right = in_right;

}

/******************************************************
*   Purpose:  destructor

*         Entry:  none

*         Exit: deletes data
*******************************************************/
template<typename a_type, typename key_type>
Node<a_type, key_type>::~Node()
{
	delete data;
}

/******************************************************
*   Purpose:  getter for data

*         Entry:  none

*         Exit: returns data
*******************************************************/
template<typename a_type, typename key_type>
a_type Node<a_type, key_type>::GetData()
{
	return *data;
}

/******************************************************
*   Purpose:  getter for key

*         Entry:  none

*         Exit: returns key
*******************************************************/
template<typename a_type, typename key_type>
key_type Node<a_type, key_type>::GetKey()
{
	return key;
}


/******************************************************
*   Purpose:  getter for left

*         Entry:  none

*         Exit: returns left
*******************************************************/
template<typename a_type, typename key_type>
Node<a_type,key_type> * Node<a_type, key_type>::GetLeft()
{
	return left;
}


/******************************************************
*   Purpose:  setter for left

*         Entry:  passed in node

*         Exit: sets left to the passed in node
*******************************************************/
template<typename a_type, typename key_type>
void Node<a_type, key_type>::SetLeft(Node * in_node)
{
	left = in_node;
}


/******************************************************
*   Purpose:  getter for right

*         Entry:  none

*         Exit: returns right
*******************************************************/
template<typename a_type, typename key_type>
Node<a_type, key_type> * Node<a_type, key_type>::GetRight()
{
	return right;
}

/******************************************************
*   Purpose:  setter for right

*         Entry:  passed in node

*         Exit: sets right to the passed in node
*******************************************************/
template<typename a_type, typename key_type>
void Node<a_type, key_type>::SetRight(Node * in_node)
{
	right = in_node;
}




