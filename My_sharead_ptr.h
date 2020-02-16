#pragma once
#include "dependies.h"
template<class T>
class My_sharead_ptr {
	T* ptr;
	int counter;
public:
	My_sharead_ptr(T* a =nullptr);//done
	~My_sharead_ptr();//done
	My_sharead_ptr& operator =(T* a);
	My_sharead_ptr& operator =(My_sharead_ptr<T>& a);
	T& operator *();
	T* operator ->();
};
template<class T>
My_sharead_ptr<T>::My_sharead_ptr(T* a) {
	this->ptr = a;
	this->counter={1};
}
template<class T>
My_sharead_ptr<T>::~My_sharead_ptr() {
	this->counter--;
	if (this->counter==0&&this->ptr!=nullptr)
	{
		delete this->ptr;
	}
}
template<class T>
My_sharead_ptr<T>& My_sharead_ptr<T>::operator =(T* a) {
	if (this->ptr == nullptr) {
		this->ptr = a;
		this->counter++;
	}
	else
	{
		delete this->ptr;
		this->ptr = a;
	}
	return *this;
}
template<class T>
My_sharead_ptr<T>& My_sharead_ptr<T>::operator =(My_sharead_ptr<T>& a) {
	if (this->ptr != nullptr) {
		delete this->ptr;
		this->ptr = a.ptr;
	    this->counter = a.counter;
		a.counter++;

	}
	else
	{
		this->ptr = a.ptr;
		a.counter++;
	}
	return *this;
}
template<class T>
T& My_sharead_ptr<T>::operator *() {
	return *this->ptr;
}
template<class T>
T* My_sharead_ptr<T>::operator ->() {
	return *this->ptr;
}
