#include "DLinkList.h"

/*template <class T>
DLinkedList<T>::DLinkedList(T d){
	this->head = new Node<T>(d);
	this->tail = this->head;
}


template <class T>
void DLinkedList<T>::AppendElement(T element){
	if(head==NULL&&tail==NULL){
		head = tail = new Node(T);
		return;
	}
	this->tail->SetNext(new Node(element));
	this->tail->next->SetPrev(this->tail);
	this->tail = this->tail->GetNext();
	
}

template <class T>
bool DLinkedList<T>::RemoveElement(T element){
	Node<T>*temp = this->head;
	while(temp!=NUll){
		if(temp->GetData()==element){
			if(temp==head){
				Node<T>*holder = temp->GetNext();
				delete temp;
				head = holer;
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
		nNode = temp->getNe
	}
}


*/