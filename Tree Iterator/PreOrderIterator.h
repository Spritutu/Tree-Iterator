#pragma once
#include "Node.h"
#include "Iterator.h"
#include <stack>

template<typename a_type, typename key_type>
class PreOrderIterator :public Iterator<a_type, key_type>
{
private:
	std::stack<Node<a_type, key_type>*> parents;
public:
	PreOrderIterator();
	PreOrderIterator(Node < a_type, key_type>*x);
	~PreOrderIterator();
	Iterator<a_type, key_type>& operator=(InterfaceIterator<a_type, key_type>& obj);
	InterfaceIterator<a_type, key_type>& operator++() override;
	InterfaceIterator<a_type, key_type>& operator++(int in) override;
	InterfaceIterator<a_type, key_type>& operator--() override;
	InterfaceIterator<a_type, key_type>& operator--(int in) override;

};
#include "PreOrderIterator.cpp"