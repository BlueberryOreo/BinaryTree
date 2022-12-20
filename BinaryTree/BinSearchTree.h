#pragma once
#include "BinTree.h"

template<typename T>
class BinSearchTree : public BinTree<T>
{
public:
	typedef Node<T>* node;
	BinSearchTree() {}
	BinSearchTree(const T *arr, int n);
	BinSearchTree(vector<T> arr);
	int insert(T n);
	int remove(T n);
	Node<T>* search(T n);
};

template<typename T>
inline BinSearchTree<T>::BinSearchTree(const T* arr, int n)
{
	for (int i = 0; i < n; i ++) {
		if(arr[i]) insert(arr[i]);
	}
}

template<typename T>
inline BinSearchTree<T>::BinSearchTree(vector<T> arr)
{
	for (int i = 0; i < arr.size(); i++) {
		if(arr[i]) insert(arr[i]);
	}
}

template<typename T>
inline int BinSearchTree<T>::insert(T n)
{
	if (this->root == NULL) {
		this->root = new Node<T>(n);
		this->root->depth = 0;
		return 1;
	}
	Node<T>* tmp = this->root;
	while (true) {
		if (n < tmp->data) {
			if(tmp->lc) tmp = tmp->lc;
			else {
				tmp->lc = new Node<T>(n);
				tmp->lc->depth = tmp->depth + 1;
				return 1;
			}
		}
		else if (tmp->data < n) {
			if(tmp->rc) tmp = tmp->rc;
			else {
				tmp->rc = new Node<T>(n);
				tmp->rc->depth = tmp->depth + 1;
				return 1;
			}
		}
		else return 0;
	}
}

template<typename T>
inline int BinSearchTree<T>::remove(T n)
{
	Node<T>* needToMove = search(n);
	if (needToMove == NULL) return 0;

	Node<T>* f = this->root;
	while (f != needToMove && f->lc != needToMove && f->rc != needToMove) {
		if (needToMove->data < f->data) f = f->lc;
		else if(f->data < needToMove->data) f = f->rc;
	}

	if (needToMove->lc == NULL && needToMove->rc == NULL) {
		// 叶子节点
		if (needToMove != this->root) {
			if (f->lc == needToMove) f->lc = NULL;
			else f->rc = NULL;
		}
		else {
			this->root = NULL;
		}
		delete needToMove;
		return 1;
	}

	if (needToMove->lc == NULL) {
		// 只有右子树
		if (needToMove == this->root) this->root = needToMove->rc;
		else if (f->lc == needToMove) f->lc = needToMove->rc;
		else f->rc = needToMove->rc;
		delete needToMove;
		return 1;
	}

	if (needToMove->rc == NULL) {
		// 只有左子树
		if (needToMove == this->root) this->root = needToMove->lc;
		else if (f->lc == needToMove) f->lc = needToMove->lc;
		else f->rc = needToMove->lc;
		delete needToMove;
		return 1;
	}

	// 左右子树均不为空
	Node<T>* par = needToMove, * s = needToMove->rc;
	while (s->lc != NULL) {
		// 查找最左下节点
		par = s;
		s = s->lc;
	}
	needToMove->data = s->data;
	if (par == needToMove) par->rc = s->rc;
	else par->lc = s->rc;
	delete s;

	return 1;
}

template<typename T>
inline Node<T>* BinSearchTree<T>::search(T n)
{
	Node<T>* tmp = this->root;
	while (tmp != NULL) {
		if (n < tmp->data) {
			tmp = tmp->lc;
		}
		else if (tmp->data < n) {
			tmp = tmp->rc;
		}
		else {
			break;
		}
	}
	return tmp;
}
