#ifndef _DLINKLIST_H_
#define _DLINKLIST_H_

using namespace std;

template<class T>
class Node{
private:
	Node* next;
	Node* prev;
	T data;
public:
	Node(T d, Node* p = NULL, Node * n = NULL) : data(d), prev(p), next(n){};
	Node * GetNext() {return this->next;};
	Node * GetPrev() {return this->prev;};
	T GetData() {return data;};
	void   SetNext(Node * n) {next = n;};
};


template <class T>
class DLinkedList{
private:
	Node<T> * head;
	Node<T> * head;
public:
    DLinkedList(T d);
	//need to fix the destructor and add a removeall method
	~DLinkedList();
	DLinkedList * GetHead() {return head};
	void AppendElement(T element);
	bool RemoveElement(T element);

};


#endif