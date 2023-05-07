#include "List.h"

template<class T>
List<T>::List() {
	index = 0;
}

template<class T>
List<T>::~List() {
}

template <class T>
void List<T>::add(T item) {
	if(index < 99)
		car_list[index++] = item;
}

template <class T>
T List<T>::get(int pos) {
	return car_list[pos];
}

template <class T>
int List<T>::size() {
	if (index == 0) {
		return 0;
	}
	return index;
}
template <class T>
void List<T>::swap(int i, int j) {
	T temp;
	temp = car_list[i];
	car_list[i] = car_list[j];
	car_list[j] = temp;
}