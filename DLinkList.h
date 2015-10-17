#ifndef _DLINKLIST_H_
#define _DLINKLIST_H_

#include<iostream>

template<class T>
class Node{
private:
	Node<T>* next;
	Node<T>* prev;
	T *data;
public:
	Node(T d) : data(new T(d)), next(NULL), prev(NULL) {};
	Node<T> * GetNext() {return this->next;};
	Node<T> * GetPrev() {return this->prev;};
	void   SetNext(Node * n) {this->next = n;}
	void   SetPrev(Node * p) {this->prev = p;}
	T * GetData() {return data;};
};



template <class T>
class DLinkedList{
private:
	Node<T> * head;
	Node<T> * tail;
public:
	DLinkedList();
    DLinkedList(T d);
	DLinkedList( const DLinkedList<T> &d);
	~DLinkedList();
	Node<T> * GetHead() const {return head;};
	void AppendElement(T element);
	bool RemoveElement(T element);
	void SetHead(Node<T> *newhead) { head = newhead; }

};













//function defination 

template <class T>
DLinkedList<T>::DLinkedList(T d){
	this->head = new Node<T>(d);
	this->tail = this->head;
}

template <class T>
DLinkedList<T>::DLinkedList() {
	this->head = this->tail = NULL;
}

template <class T>
DLinkedList<T>::DLinkedList(const DLinkedList<T>& d) {
	Node<T> *temp = d.GetHead();
	while (temp != NULL) {
		this->AppendElement(*temp->GetData());
		temp = temp->GetNext();
	}
}


template <class T>
void DLinkedList<T>::AppendElement(T element){
	if(head==NULL&&tail==NULL){
		tail = head = new Node<T>(element);
		
		return;
	}
	this->tail->SetNext(new Node<T>(element));
	this->tail->GetNext()->SetPrev(this->tail);
	this->tail = this->tail->GetNext();
	
}

template <class T>
bool DLinkedList<T>::RemoveElement(T element){
	Node<T>*temp = this->head;
	while(temp!=NULL){
		if(*temp->GetData()==element){
			if(temp==head){
				Node<T>*holder = temp->GetNext();
				delete temp;
				head = holder;
				return true;
			}

			if(temp==tail){
				Node<T>*holder = temp->GetPrev();
				delete temp;
				tail = holder;
				return true;
			}

			temp->GetPrev()->SetNext(temp->GetNext());
			temp->GetNext()->SetPrev(temp->GetPrev());
			delete temp;
			return true;
			
		}
		temp = temp->GetNext();
	}
	return false;
}

template <class T>
DLinkedList<T>::~DLinkedList(){
	Node<T> *temp =this->head;
	Node<T> *nNode = temp;
	while(temp!=NULL){
	  delete temp->GetData();
		nNode = temp->GetNext();
		delete temp;
		temp = nNode;
	}
}




#endif
