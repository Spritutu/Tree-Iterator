#pragma once
#include "Iterator.h"
void Driver();

template<typename a_type, typename key_type>
void PreIncrement(InterfaceIterator<a_type, key_type>* iter);

template<typename a_type, typename key_type>
void PostIncrement(InterfaceIterator<a_type, key_type>* iter);

#include "Driver.cpp"