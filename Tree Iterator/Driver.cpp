#include "Driver.h"
#include "Iterator.h"
#include "InOrderIterator.h"
#include "PreOrderIterator.h"
#include "BST.h"
#include <iostream>
using namespace std;
void Driver()
{
	int start = 5;
	int	*data = new int[10];
	BST<int, int>*a = new BST<int, int>(&start, start);
	for (int i = 0; i < 10; i++)
	{
		data[i] = i;
		a->Insert(a->GetRoot(), &data[i], data[i]);
	}
	a->InOrder(a->GetRoot(), true);
	cout << endl;
	InterfaceIterator<int, int>* temp = new InOrderIterator<int, int>(a->GetRoot());
	try
	{
		PreIncrement(temp);
	}
	catch (const Exception& e) {
		cout << e << endl;
	}
	cout << endl;
	delete temp;
	temp = new InOrderIterator<int, int>(a->GetRoot());
	try
	{
		PostIncrement(temp);
	}
	catch (const Exception& e) {
		cout << e << endl;
	}
	cout << endl;
	delete temp;
	temp = new PreOrderIterator<int, int>(a->GetRoot());
	try
	{
		PreIncrement(temp);
	}
	catch (const Exception& e) {
		cout << e << endl;
	}
}

template<typename a_type, typename key_type>
void PreIncrement(InterfaceIterator<a_type, key_type>* iter)
{
	for (int i = 0; i < 12; i++)
		++(*iter);
}

template<typename a_type, typename key_type>
void PostIncrement(InterfaceIterator<a_type, key_type>* iter)
{
	for (int i = 0; i < 12; i++)
		(*iter)++;
}