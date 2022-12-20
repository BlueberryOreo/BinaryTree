#pragma once
#include "utility.h"

template<typename T>
class BinTree
{
protected:
	Node<T>* root;
	Node<T>* create(const T* arr, int& now, int dep);
	Node<T>* create(vector<T>& arr, int& now, int dep);
	int depth;
	int width;
	int deg0, deg1, deg2;
	void destroy(Node<T>* now);
	void pre(Node<T> *now);
	void in(Node<T> *now);
	void post(Node<T> *now);
	void dfs(Node<T> *now, int cnt);
	void bfs(bool flag=false);

public:
	BinTree();
	BinTree(const T *arr);
	BinTree(vector<T> arr);
	~BinTree();

	void preOrder();
	void inOrder();
	void postOrder();
	void levelOrder();

	int getDepth();
	int getWidth();
	int degree0();
	int degree1();
	int degree2();
};

template<typename T>
inline Node<T>* BinTree<T>::create(const T* arr, int& now, int dep)
{
	if (arr[now] == 0) return NULL;
	Node<T>* tmp = new Node<T>(arr[now]);
	tmp->depth = dep;
	now += 1;
	tmp->lc = create(arr, now, dep + 1);
	now += 1;
	tmp->rc = create(arr, now, dep + 1);
	return tmp;
}

template<typename T>
inline Node<T>* BinTree<T>::create(vector<T>& arr, int& now, int dep)
{
	if (arr[now] == 0) return NULL;
	Node<T>* tmp = new Node<T>(arr[now]);
	tmp->depth = dep;
	now += 1;
	tmp->lc = create(arr, now, dep + 1);
	now += 1;
	tmp->rc = create(arr, now, dep + 1);
	return tmp;
}

template<typename T>
inline void BinTree<T>::destroy(Node<T>* now)
{
	if (now->lc) destroy(now->lc);
	if (now->rc) destroy(now->rc);
	delete now;
}

template<typename T>
inline void BinTree<T>::pre(Node<T>* now)
{
	cout << now->data << " ";
	if (now->lc) pre(now->lc);
	if (now->rc) pre(now->rc);
}

template<typename T>
inline void BinTree<T>::in(Node<T>* now)
{
	if (now->lc) in(now->lc);
	cout << now->data << " ";
	if (now->rc) in(now->rc);
}

template<typename T>
inline void BinTree<T>::post(Node<T>* now)
{
	if (now->lc) post(now->lc);
	if (now->rc) post(now->rc);
	cout << now->data << " ";
}

template<typename T>
inline void BinTree<T>::dfs(Node<T>* now, int cnt)
{
	if (now == NULL) return;
	depth = max(depth, cnt);
	dfs(now->lc, cnt + 1);
	dfs(now->rc, cnt + 1);
}

template<typename T>
inline void BinTree<T>::bfs(bool flag)
{
	queue<Node<T>* > q;
	q.push(root);
	int cnt = 0, last = 0;
	while (!q.empty()) {
		Node<T>* now = q.front();
		q.pop();
		if(flag) cout << now->data << " ";
		//cout << now->depth << " ";
		if (now->depth == last) cnt++;
		else {
			width = max(width, cnt);
			last = now->depth;
			cnt = 1;
		}
		bool flag1 = false, flag2 = false;
		if (now->lc) q.push(now->lc), flag1 = true;
		if (now->rc) q.push(now->rc), flag2 = true;
		if (flag1 && flag2) deg2++;
		else if (flag1 || flag2) deg1++;
		else deg0++;
	}
	//cout << endl;
}

template<typename T>
inline BinTree<T>::BinTree()
{
	root = NULL;
	depth = width = 0;
	deg0 = deg1 = deg2 = 0;
}

template<typename T>
inline BinTree<T>::BinTree(const T* arr)
{
	int now = 0;
	root = create(arr, now, 0);
	root->depth = 0;
	depth = width = 0;
	deg0 = deg1 = deg2 = 0;
}

template<typename T>
inline BinTree<T>::BinTree(vector<T> arr)
{
	int now = 0;
	root = create(arr, now, 0);
	depth = width = 0;
	deg0 = deg1 = deg2 = 0;
}

template<typename T>
inline BinTree<T>::~BinTree()
{
	//cout << "here" << endl;
	if(root) destroy(root);
}

template<typename T>
inline void BinTree<T>::preOrder()
{
	if(root) pre(root);
	cout << endl;
}

template<typename T>
inline void BinTree<T>::inOrder()
{
	if(root) in(root);
	cout << endl;
}

template<typename T>
inline void BinTree<T>::postOrder()
{
	if(root) post(root);
	cout << endl;
}

template<typename T>
inline void BinTree<T>::levelOrder()
{
	if(root) bfs(true);
	cout << endl;
}

template<typename T>
inline int BinTree<T>::getDepth()
{
	dfs(root, 0);
	return depth;
}

template<typename T>
inline int BinTree<T>::getWidth()
{
	bfs();
	return width;
}

template<typename T>
inline int BinTree<T>::degree0()
{
	deg0 = deg1 = deg2 = 0;
	bfs();
	return deg0;
}

template<typename T>
inline int BinTree<T>::degree1()
{
	deg0 = deg1 = deg2 = 0;
	bfs();
	return deg1;
}

template<typename T>
inline int BinTree<T>::degree2()
{
	deg0 = deg1 = deg2 = 0;
	bfs();
	return deg2;
}
