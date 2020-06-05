//Name: Theodor Giles
//Programming Assignment: 7- Templated List Enhancements
#pragma once
#include <iostream>
#include <iomanip>
#include "LinkedList.h"
using std::cout;
using std::endl;
template <class T>
class Node
{
private:
    Node();
    ~Node();
    Node(T data);
    Node(const Node& other);
    Node& operator=(const Node& other);
    Node(Node&& other);
    Node& operator=(Node&& other);
    Node<T>* m_next;
    T m_data;
    template<class T> friend class LinkedList;
};

template<class T>
inline Node<T>::Node() :
    m_data(T()),
    m_next(nullptr)
{
}
template<class T>
inline Node<T>::~Node()
{
}
template<class T>
inline Node<T>::Node(T elem) :
    m_data(elem),
    m_next(nullptr)
{
}
template<class T>
inline Node<T>::Node(const Node& other)
{
    m_data = other.m_data;
    m_next = other.m_next;
}
template<class T>
inline Node<T>& Node<T>::operator=(const Node& other)
{
    m_data = other.m_data;
    m_next = other.m_next;
    return *this;
}
template<class T>
inline Node<T>::Node(Node&& other)
{
    m_data = other.m_data;
    m_next = other.m_next;
    delete other;
}
template<class T>
inline Node<T>& Node<T>::operator=(Node&& other)
{
    m_data = other.m_data;
    m_next = other.m_next;
    delete other;
    return *this;
}
