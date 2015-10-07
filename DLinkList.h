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
	//need to fix the destructor and add a removeall method
	~DLinkedList();
	DLinkedList * GetNext();
	DLinkedList * GetPrev();
	DLinkedList * GetHead();
	T GetData() {return data};
	void SetNext(DLinkedList * n);
	void AppendElement(T element);
	bool RemoveElement(T element);

};

#endif