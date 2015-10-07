#ifndef _DLINKLIST_H_
#define _DLINKLIST_H_

using namespace std;

template <class T>
class DLinkedList{
private:
	DLinkedList * prev;
	DLinkedList * next;
	T data;
public:
    DLinkedList(T d, DLinkedList *p, DLinkedList *n) : data(d), prev(p), next(n){}
    DLinkedList(T d) : data(d), prev(NULL), next(NULL){}
	~DLinkedList();
	DLinkedList * GetNext();
	DLinkedList * GetPrev();
	DLinkedList * GetHead();
	void SetNext(DLinkedList * n);
	void AppendElement(T element);
	bool RemoveElement(T element);

};

#endif