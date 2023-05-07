#pragma once
#ifndef _LIST_H_
#define _LIST_H_
#include "Setting.h"
using namespace std;

template <class T>
class List {
private:
	T car_list[100];
	int index = 0;
public:
	List();
	~List();
	void add(T item);
	T get(int pos);
	int size();
	void swap(int i, int j);
};

#endif //_LIST_H_

