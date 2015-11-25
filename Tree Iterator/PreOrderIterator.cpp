#include "PreOrderIterator.h"
#include <iostream>
#include "Exception.h"

template<typename a_type, typename key_type>
PreOrderIterator<a_type, key_type>::PreOrderIterator()
{
	m_node = 0;
	current = m_node;
}

template<typename a_type, typename key_type>
PreOrderIterator<a_type, key_type>::PreOrderIterator(Node<a_type, key_type>*x)
{
	m_node = x;
	current = m_node;
	parents.push(current);
}

template<typename a_type, typename key_type>
PreOrderIterator<a_type, key_type>::~PreOrderIterator()
{
}

template<typename a_type, typename key_type>
inline Iterator<a_type, key_type>& PreOrderIterator<a_type, key_type>::operator=(InterfaceIterator<a_type, key_type>& obj)
{
	m_node = *obj.get_m_node();
	return *this;
}

template<typename a_type, typename key_type>
InterfaceIterator<a_type, key_type>& PreOrderIterator<a_type, key_type>::operator++()
{
	if (!parents.empty() || current)
	{
		if (current)
		{
			std::cout << current->GetData() << " ";
			if (current->GetRight())
				parents.push(current->GetRight());
			current = current->GetLeft();
		}
		else
		{
			current = parents.top();
			parents.pop();
		}

	}
	else throw Exception("End of tree");
	return *this;
}

template<typename a_type, typename key_type>
InterfaceIterator<a_type, key_type>& PreOrderIterator<a_type, key_type>::operator++(int in)
{
	InterfaceIterator<a_type, key_type>* temp = this;
	++(*this);
	return *temp;
}

template<typename a_type, typename key_type>
InterfaceIterator<a_type, key_type>& PreOrderIterator<a_type, key_type>::operator--()
{
	return *this;
}

template<typename a_type, typename key_type>
InterfaceIterator<a_type, key_type>& PreOrderIterator<a_type, key_type>::operator--(int in)
{
	return PreOrderIterator<a_type, key_type>();
}