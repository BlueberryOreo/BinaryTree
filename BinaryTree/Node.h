#pragma once

template<typename T>
struct Node {
	T data;
	Node<T>* lc, * rc;
	int depth;
	Node();
	Node(T data);
};

template<typename T>
inline Node<T>::Node()
{
	data = 0;
	lc = rc = NULL;
	depth = 0;
}

template<typename T>
inline Node<T>::Node(T data)
{
	this->data = data;
	lc = rc = NULL;
	depth = 0;
}