#include "DLinkList.h"


DLinkedList *DLinkedList::GetNext(){
	return this->next;
}

DLinkedList *DLinkedList::GetPrev(){
	return this->prev;
}

DLinkedList *DLinkedList::GetHead(){
	DLinkedList * temp = this;
	while(temp->prev!=NULL)
		temp = temp->prev;
	return temp;
}

void DLinkedList::SetNext(DLinkedList * n){
	this->next = n;
}



template <class T>
void DLinkedList::AppendElement(T element){
	DLinkedList * temp = this;
	while(temp->next!=NULL)
		temp = temp->next;
	temp->next = new DLinkedList(element,this,NULL);
}

template <class T>
bool DLinkedList::RemoveElement(T element){
	DLinkedList * temp = this->GetHead();
	while(temp!=NULL){
		if(temp->data == element){
			temp->prev->next = temp->next;
			delete temp;
		}
		temp = temp->next();
	}
	return false;
}

DLinkedList::~DLinkedList(){
	DLinkedList* temp = this->GetHead();
	DLinkedList* temp2 = temp;
	while(temp!=NULL){
		temp = temp->next();
		delete temp2;
		temp2 = temp;
	}
}


