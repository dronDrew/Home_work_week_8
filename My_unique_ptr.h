#pragma once
#include "dependies.h"
template<class T>
class My_unique_ptr {
	T* ptr;
public:
	My_unique_ptr( T* a =nullptr);
	My_unique_ptr& operator =( T* a);
	~My_unique_ptr();
	T& operator *();
	T* operator ->();
};
template<class T>
My_unique_ptr<T>::My_unique_ptr( T* a) {
	this->ptr = a;
	a = nullptr;
}
template<class T>
My_unique_ptr<T>::~My_unique_ptr() {
	delete this->ptr;
}
template<class T>
My_unique_ptr<T>& My_unique_ptr<T>::operator =( T* a) {
	if (this->ptr==nullptr)
	{
		this->ptr = a;
		a = nullptr;
	}
	else {
		delete this->ptr;
		this->ptr = a;
		a = nullptr;
	}
	return *this;
}
template<class T>
T& My_unique_ptr<T>::operator *() {
	return *this->ptr;
}
template<class T>
T* My_unique_ptr<T>::operator ->() {
	return this->ptr;
}