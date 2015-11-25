#include "Iterator.h"
using namespace std;

template<typename a_type, typename key_type>
inline Node<a_type, key_type>* Iterator<a_type, key_type>::get_m_node() const
{
	return m_node;
}

template<typename a_type, typename key_type>
Node<a_type, key_type>* Iterator<a_type, key_type>::get_current() const
{
	return current;
}

template<typename a_type, typename key_type>
void Iterator<a_type, key_type>::set_m_node(Node<a_type, key_type>* x)
{
	m_node = x;
}

template<typename a_type, typename key_type>
Node<a_type, key_type>* Iterator<a_type, key_type>::FindParent(Node<a_type, key_type>* node, Node<a_type, key_type>* child)
{
	if (node->GetData() == child->GetData())
	{
		return nullptr;//root
	}
	else if ((node->GetLeft() != 0 && child->GetKey() == node->GetLeft()->GetKey()) || (node->GetRight() != 0 && child->GetKey() == node->GetRight()->GetKey()))
	{
		return node;
	}
	else if (child->GetKey()<node->GetKey())
	{
		return FindParent(node->GetLeft(), child);
	}
	else if (child->GetKey()>node->GetKey())
	{
		return FindParent(node->GetRight(), child);
	}
}

template<typename a_type, typename key_type>
Node<a_type, key_type>* Iterator<a_type, key_type>::FindMin(Node<a_type, key_type>* root)
{
	Node<a_type, key_type>* temp = root;
	while (temp->GetLeft())
	{
		temp = temp->GetLeft();
	}
	return temp;
}
