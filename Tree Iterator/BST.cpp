#include "BST.h"
#include <iostream>
#include <queue>
#include <chrono>

using namespace std;
/******************************************************
*   Purpose:  default constructor for BST

*         Entry:  none

*         Exit: sets Root to 0
*******************************************************/
template<typename a_type, typename key_type>
inline BST<a_type, key_type>::BST()
{
	Root = 0;
}

/******************************************************
*   Purpose:  default constructor for BST

*         Entry:  passed in data and a key for sorting into the tree

*         Exit: creates a new node at Root using the passed in data and key
*******************************************************/
template<typename a_type, typename key_type>
inline BST<a_type, key_type>::BST(a_type *in_data, key_type in_key)
{
	Root = new Node<a_type, key_type>(in_data, in_key,0,0);
}

/******************************************************
*   Purpose:  destructor for BST

*         Entry:  none

*         Exit: deletes Root and sets it to 0;
*******************************************************/
template<typename a_type, typename key_type>
BST<a_type, key_type>::~BST()
{
	delete Root;
	Root = 0;
}

/******************************************************
*   Purpose:  create a node and place it in the proper place in our tree.

*         Entry:  passed in a node to start from, some data and a key.

*         Exit: a recursive function that moves down the tree till it finds the proper place for the passed in data based on comparing keys.
				when root == 0 we have found it's correct place in the tree and create a new node there.
*******************************************************/
template<typename a_type, typename key_type>
void BST<a_type, key_type>::Insert(Node<a_type,key_type>*root, a_type *in_data, key_type in_key)
{
	if (root == 0)
	{
		root = new Node<a_type, key_type>(in_data, in_key, 0, 0);
		return;
	}
		
	if (in_key < root->GetKey())
	{
		if (!root->GetLeft())
			root->SetLeft(new Node<a_type, key_type>(in_data, in_key, 0, 0));
		else
		{
			Node<a_type, key_type>*temp = root->GetLeft();
			Insert(temp, in_data, in_key);
		}
	}
	else
	{
		if (!root->GetRight())
			root->SetRight(new Node<a_type, key_type>(in_data, in_key, 0, 0));
		else
		{
			Node<a_type, key_type>*temp = root->GetRight();
			Insert(temp, in_data, in_key);
		}
	}
}

/******************************************************
*   Purpose:  finds the correct node based by moving through the tree comparing keys 
				then removes that node and restructures the tree if needed

*         Entry:  passed in a node as a starting place and the key for comparison

*         Exit: finds the correct node based by moving through the tree comparing keys 
				then removes that node and restructures the tree if needed
*******************************************************/
template<typename a_type, typename key_type>
void BST<a_type, key_type>::Delete(Node<a_type, key_type>* current, key_type in_key)
{
	
	Node<a_type, key_type>* temp = 0;
	if (in_key == current->GetLeft()->GetKey()) 
	{
		temp = current->GetLeft();
		Node<a_type, key_type>* temp2 = FindAndDetachMin(temp);
		if (temp2 != 0 && temp2 != temp->GetLeft()) 
		{
			temp2->SetLeft(temp->GetLeft());
		}

		if (temp2 != 0 && temp2 != temp->GetRight()) 
		{
			temp2->SetRight(temp->GetRight());
		}
		current->SetLeft(temp2);
		delete temp;
		return;
	}

	else if (in_key == current->GetRight()->GetKey())
	{
		temp = current->GetRight();
		Node<a_type, key_type>* temp2 = FindAndDetachMin(temp);
		if (temp2 != 0) 
		{
			temp2->SetLeft(temp->GetLeft());
			temp2->SetRight(temp->GetRight());
		}
		current->SetRight(temp2);
		delete temp;
		return;
	}

	if (in_key < current->GetKey())
		Delete(current->GetLeft(), in_key);
	else if (in_key >= current->GetKey())
		Delete(current->GetRight(), in_key);
}

/******************************************************
*   Purpose:  remove all nodes in tree

*         Entry:  none

*         Exit: while the left or right child exists we call delete on each child. 
				then when there are no children we delete Root and set it to 0
*******************************************************/
template<typename a_type, typename key_type>
void BST<a_type, key_type>::Purge()
{
	while (Root->GetLeft() || Root->GetRight())
	{
		if (Root->GetRight())
			Delete(Root, Root->GetRight()->GetKey());
		else if (Root->GetLeft())
			Delete(Root, Root->GetLeft()->GetKey());
	}
	delete Root;
	Root = 0;
}

/******************************************************
*   Purpose:  find the max height of the tree

*         Entry:  passed in a node to start from

*         Exit: recursive function that as long as there is a left or right child  keeps calling itself and returning +1
*******************************************************/
template<typename a_type, typename key_type>
int BST<a_type, key_type>::Height(Node<a_type, key_type>*current)
{
		if (!current) 
			return 0;

		int left = Height(current->GetLeft());
		int right = Height(current->GetRight());
		return (left > right) ? left + 1 : right + 1;
}

/******************************************************
*   Purpose:  traverses the tree from lowest key to highest

*         Entry:  passed in a node to start from and a bool to decide if we output the data at the node

*         Exit: recursive function that calls itself using the left first to get the lowest key 
				then does the visit (in this case output data to console) then moves on to the next lowest key.
*******************************************************/
template<typename a_type, typename key_type>
void BST<a_type, key_type>::InOrder(Node<a_type, key_type>*current,bool output)
{


	if (!current)
		return;

	InOrder(current->GetLeft(),output);
	if(output==true)
		cout << current->GetData()<<",";
	InOrder(current->GetRight(),output);


}

/******************************************************
*   Purpose:  traverses the tree going down the left branches first moving to the right and if output is true outputs the value to the console.

*         Entry:  passed in a node to start from and a bool to decide if we output the data at the node

*         Exit: recursive function that does the visit() (in this case output data to console) then moves down the tree to the left child and recurses. 
*******************************************************/
template<typename a_type, typename key_type>
void BST<a_type, key_type>::PreOrder(Node<a_type, key_type>*current,bool output)
{
	if (!current)
		return;
	if (output==true)
		cout << current->GetData() << ",";
	InOrder(current->GetLeft(),output);
	InOrder(current->GetRight(),output);

}

/******************************************************
*   Purpose:  traverses the tree from furthest children going up and if output is true outputs the value to the console. output defaults to false.

*         Entry:  passed in a node to start from and a bool to decide if we output the data at the node

*         Exit: recursive function that calls itself on the left child then the right and then does visit(in this case output to the console).
*******************************************************/
template<typename a_type, typename key_type>
void BST<a_type, key_type>::PostOrder(Node<a_type, key_type>*current,bool output)
{
	if (!current)
		return;

	InOrder(current->GetLeft(),output);
	InOrder(current->GetRight(),output);
	if (output==true)
		cout << current->GetData() << ",";

}

/******************************************************
*   Purpose:  traverses the tree from root going down visiting each node on a level before moving down again.

*         Entry:  passed in a node to start from and a bool to decide if we output the data at the node

*         Exit: travel down the tree level by level pushing values into a queue and pop them back out till the queue is empty( reach end of tree).
*******************************************************/
template<typename a_type, typename key_type>
void BST<a_type, key_type>::BreadthFirst(Node<a_type, key_type>*current,bool output)
{
	queue<Node<a_type,key_type>*> *Queue = new queue<Node<a_type, key_type>*>();

	if (current == NULL) 
		return;
	Queue->push(current);
	while (!Queue->empty())
	{
		Node<a_type,key_type> * traverse = Queue->front();
		Queue->pop();
		if (output==true)
			cout << traverse->GetData() << ",";
		if (traverse->GetLeft() != NULL)
			Queue->push(traverse->GetLeft());
		if (traverse->GetRight() != NULL)
			Queue->push(traverse->GetRight());
	}
	delete Queue;
}

/******************************************************
*   Purpose:  find the smallest key from given node in the tree.

*         Entry:  passed in a node to start from

*         Exit: we store the passed in node in temp 
				then we keep getting the left child of temp till there is no child then return temp.
*******************************************************/
template<typename a_type, typename key_type>
Node<a_type, key_type>* BST<a_type, key_type>::FindMin(Node<a_type, key_type>*root)
{
	Node<a_type, key_type>* temp = root;
	while (temp->GetLeft())
	{
		temp = temp->GetLeft();
	}
	return temp;
}

/******************************************************
*   Purpose:  find the smallest key from given node in the tree remove it and maintain the structure of the tree.

*         Entry:  passed in a node to start from

*         Exit: if there is no right child from passed in root we return the left child.
				else if there is no left child of the right child we set the right childs left to the passed in roots left and return the passed in roots right.
				else walk down the left most branch of the passed in root till we hit the end store the last child in a temp pointer set it's parent's left ot 0 and return the child.
*******************************************************/
template<typename a_type, typename key_type>
Node<a_type, key_type>* BST<a_type, key_type>::FindAndDetachMin(Node<a_type, key_type>*root)
{
	if (!root->GetRight()) {
		return root->GetLeft();
	}
	else if (!root->GetRight()->GetLeft())
	{
		root->GetRight()->SetLeft(root->GetLeft());
		return root->GetRight();
	}
	else {
		Node<a_type, key_type>* temp = root->GetRight();
		Node<a_type, key_type>* temp2;
		while (temp->GetLeft()->GetLeft())
		{
			temp = temp->GetLeft();
		}
		temp2 = temp->GetLeft();
		temp->SetLeft(0);


		return temp2;
	}
}

/******************************************************
*   Purpose:  replace the passed in parent with the passed in child

*         Entry:  passed in a parent node and a child node

*         Exit: store the parent in a temp, set parent equal to the passed in child then delete the parent.
*******************************************************/
template<typename a_type, typename key_type>
void BST<a_type, key_type>::ReplaceParent(Node<a_type, key_type>* parent, Node<a_type, key_type>* child)
{
	Node<a_type, key_type>* temp = parent;
	parent = child;
	delete temp;
}

/******************************************************
*   Purpose:  getter for Root

*         Entry:  none

*         Exit: returns Root
*******************************************************/
template<typename a_type, typename key_type>
Node<a_type, key_type>* BST<a_type, key_type>::GetRoot()
{
	return Root;
}



