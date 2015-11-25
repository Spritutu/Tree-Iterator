#include "InOrderIterator.h"
#include <iostream>
#include "Exception.h"

template<typename a_type, typename key_type>
InOrderIterator<a_type, key_type>::InOrderIterator()
{
	m_node = 0;
	current = m_node;
}

template<typename a_type, typename key_type>
InOrderIterator<a_type, key_type>::InOrderIterator(Node<a_type, key_type>*x)
{
	m_node = x;
	current = m_node;
}

template<typename a_type, typename key_type>
InOrderIterator<a_type, key_type>::~InOrderIterator()
{
}

template<typename a_type, typename key_type>
inline Iterator<a_type, key_type>& InOrderIterator<a_type, key_type>::operator=(InterfaceIterator<a_type, key_type>& obj)
{
	m_node = *obj.get_m_node();
	return *this;
}

template<typename a_type, typename key_type>
InterfaceIterator<a_type, key_type>& InOrderIterator<a_type, key_type>::operator++()
{
	if (!parents.empty()||current)
	{
		while (current)
		{
			parents.push(current);
			current = current->GetLeft();
		}
		current = parents.top();
		parents.pop();
		std::cout << current->GetData() << " ";
		current = current->GetRight();
	}
	else throw Exception("End of tree");
	return *this;
}

template<typename a_type, typename key_type>
InterfaceIterator<a_type, key_type>& InOrderIterator<a_type, key_type>::operator++(int in)
{
	InterfaceIterator<a_type, key_type>* temp = this;
	++(*this);
	return *temp;
}

template<typename a_type, typename key_type>
InterfaceIterator<a_type, key_type>& InOrderIterator<a_type, key_type>::operator--()
{
	if(parents.empty()&&!current->GetLeft())
	{
		parents.push(FindParent(m_node, current));
		current = parents.top();
	}
		//parents.pop();
	else if (current->GetLeft())
	{
		current = current->GetLeft();
		parents.push(current);
	}
	else
	{
		//parents.pop();
		current = FindParent(m_node, current);
		parents.push(current);
	}
	//cout << current->GetData() << " ";
	return *this;
}

template<typename a_type, typename key_type>
InterfaceIterator<a_type, key_type>& InOrderIterator<a_type, key_type>::operator--(int in)
{
	return InOrderIterator<a_type, key_type>();
}