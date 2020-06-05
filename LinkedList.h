//Name: Theodor Giles
//Programming Assignment: 7- Templated List Enhancements
#pragma once
template <class T> class Node;
#include <iostream>
#include <iomanip>
#include "Node.h"
#include <stdexcept> 
using std::out_of_range;
using std::cout;
using std::endl;
template <class T>
class LinkedList
{
public:
	LinkedList();
	LinkedList(T elem);
	LinkedList(const LinkedList& other);
	LinkedList& operator=(const LinkedList& other);
	LinkedList(LinkedList&& other);
	LinkedList& operator=(LinkedList&& other);
	~LinkedList();
	void PushFront(T elem);
	void PushBack(T elem);
	T PopFront();
	T PopBack() const;
	T Front() const;
	T Back() const;
	void Purge() const;
	void Display() const;
	T operator[](int i);
	void Sort(int(*compareFunc)(const T&, const T&));
	void forEach(void(*function)(T& data));
	template<class U>
	void forEach(void(*function)(T& data1, U& data2), U& data3) {
		Node<T>* travel = m_head;
		while (travel != nullptr)
		{
			function(travel->m_data, data3);
			travel = travel->m_next;
		}
	}
	void Reverse();
private:
	bool checkempty() const;
	Node<T>* m_head;
};
template<class T>
LinkedList<T>::LinkedList()
	:m_head(nullptr)
{
}

template<class T>
LinkedList<T>::LinkedList(T elem)
{
	m_head = new Node<T>(elem);
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList& other)
{
	Purge();
	Node<T>* othertravel = other.m_head;
	while (othertravel != nullptr) {
		PushBack(othertravel->m_data);
		othertravel = othertravel->m_next;
	}
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other)
{
	Purge();
	Node<T>* othertravel = other.m_head;
	while (othertravel != nullptr) {
		PushBack(othertravel->m_data);
		othertravel = othertravel->m_next;
	}
	return *this;
}

template<class T>
LinkedList<T>::LinkedList(LinkedList&& other)
{
	Purge();
	Node<T>* othertravel = other.m_head;
	while (othertravel != nullptr) {
		PushBack(othertravel->m_data);
		othertravel = othertravel->m_next;
	}
	other.~LinkedList();
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList&& other)
{
	Purge();
	Node<T>* othertravel = other.m_head;
	while (othertravel != nullptr) {
		PushBack(othertravel->m_data);
		othertravel = othertravel->m_next;
	}
	other.~LinkedList();
	return *this;
}

template<class T>
LinkedList<T>::~LinkedList()
{
	Purge();
}

template<class T>
void LinkedList<T>::PushFront(T elem)
{
	Node<T>* new_node = new Node<T>(elem);
	if (m_head == nullptr) {
		m_head = new_node;
	}
	else {
		new_node->m_next = m_head;
		m_head = new_node;
	}
}

template<class T>
void LinkedList<T>::PushBack(T elem)
{
	Node<T>* new_node = new Node<T>(elem);
	if (m_head == nullptr) {
		m_head = new_node;
	}
	else {
		Node<T>* travel;
		travel = m_head;
		while (travel->m_next != nullptr) {
			travel = travel->m_next;
		}
		travel->m_next = new_node;
	}
}

template<class T>
T LinkedList<T>::PopFront()
{
	Node<T>* travel = m_head;
	if (checkempty()) {
		T data = m_head->m_data;
		travel = m_head;
		m_head = m_head->m_next;
		delete travel;
		return data;
	}
	else {
		return T();
	}
}

template<class T>
T LinkedList<T>::PopBack() const
{
	if (checkempty()) {
		Node<T>* pre;
		Node<T>* travel = m_head;
		while (travel->m_next != nullptr) {
			pre = travel;
			travel = travel->m_next;
			if (travel->m_next == nullptr) {
				pre->m_next = nullptr;
			}
		}
		T data = travel->m_data;
		delete travel;
		return data;
	}
	else {
		return T();
	}
}

template<class T>
T LinkedList<T>::Front() const
{
	return m_head->m_data;
}

template<class T>
T LinkedList<T>::Back() const
{
	Node<T>* travel = m_head;
	if (checkempty()) {
		while (travel->m_next != nullptr) {
			travel = travel->m_next;
		}
		return travel->m_data;
	}
	else {
		return T();
	}
}

template<class T>
void LinkedList<T>::Purge() const
{
	Node<T>* todelete;
	Node<T>* travel;
	travel = m_head;
	while (travel != nullptr) {
		todelete = travel;
		travel = travel->m_next;
		delete todelete;
		todelete = nullptr;
	}
}template<class T>
void LinkedList<T>::Display() const
{
	Node<T>* travel;
	travel = m_head;
	for (int i = 0; travel != nullptr; i++) {
		cout << "Node at index: " << i << " has the data: ";
		cout << travel->m_data << endl;
		travel = travel->m_next;
	}
}

template<class T>
T LinkedList<T>::operator[](int i)
{
	Node<T>* travel;
	travel = m_head;
	int j;
	for (j = 0; travel != nullptr; j++) {
		if (i == j) {
			return travel->m_data;
		}
		travel = travel->m_next;
	}
	if (i > j || i < 0) {
		throw out_of_range("No value at index");
	}
}

template<class T>
void LinkedList<T>::Sort(int(*compareFunc)(const T&,const T&))
{
	Node<T>* trailtrail;
	Node<T>* trail;
	Node<T>* travel;
	bool found = true;
	bool ordered = false;
	while (!ordered) {
		trailtrail = nullptr;
		trail = m_head;
		travel = m_head->m_next;
		found = false;
		while (travel != nullptr) {
			int returnval = compareFunc(trail->m_data, travel->m_data);
			if (returnval>0) {
				found = true;
				if (trail == m_head) {
					m_head = travel;
					trail->m_next = travel->m_next;
					m_head->m_next = trail;
				}
				else {
					trailtrail->m_next= travel;
					trail->m_next = travel->m_next;
					travel->m_next = trail;
				}
				trailtrail = travel;
				trail = travel;
				travel = trail->m_next;
			}
			else if(returnval < 0){
				trailtrail = trail;
				trail = travel;
				travel = travel->m_next;

			}
		}
		if (!found) {
			ordered = true;
		}
	}
}
template<class T>
void LinkedList<T>::forEach(void(*function)(T& data))
{
	Node<T>* travel = m_head;
	while (travel != nullptr)
	{
		function(travel->m_data);
		travel = travel->m_next;
	}
}

template<class T>
inline void LinkedList<T>::Reverse()
{
	Node<T>* prev = nullptr;
	Node<T>* travel = m_head;
	Node<T>* next = nullptr;
	while (travel != nullptr) {
		next = travel->m_next;

		travel->m_next = prev;

		prev = travel;
		travel = next;
	}
	m_head = prev;
}

template<class T>
bool LinkedList<T>::checkempty() const
{
	bool abletorun = true;
	if (m_head == nullptr) {
		abletorun = false;
		throw out_of_range("Empty list");
	}
	return abletorun;
}