#ifndef _DLINKLIST_H_
#define _DLINKLIST_H_

#include<iostream>

template<class T>
class Node{
private:
	Node<T>* next;
	Node<T>* prev;
	T data;
public:
	Node(T d, Node<T>* p = NULL, Node<T> * n = NULL) : data(d), prev(p), next(n){};
	Node<T> * GetNext() {return this->next;};
	Node<T> * GetPrev() {return this->prev;};
	void   SetNext(Node * n) {this->next = n;}
	void   SetPrev(Node * p) {this->prev = p;}
	T GetData() {return data;};
};





template <class T>
class DLinkedList{
private:
	Node<T> * head;
	Node<T> * tail;
public:
	DLinkedList();
    DLinkedList(T d);
	~DLinkedList();
	Node<T> * GetHead() {return head;};
	void AppendElement(T element);
	bool RemoveElement(T element);

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
void DLinkedList<T>::AppendElement(T element){
	if(head==NULL&&tail==NULL){
		head = tail = new Node<T>(element);
		//std::cout << "I ;ve been here" << std::endl;
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
		if(temp->GetData()==element){
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
		nNode = temp->GetNext();
	}
}




#endif