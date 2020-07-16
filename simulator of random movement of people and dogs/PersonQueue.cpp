#include "PersonQueue.h"
#include "Person.h"
#include <cstdlib>
//------------------------------------------------------------------------------------------------------------------------
//empty constractor
PersonQueue::PersonQueue(){
	_head = NULL;
	_tail = NULL;

}
//----------------------------------------------------------------------------------------------------------------------
//initialized constractor of PersonNode 
PersonNode:: PersonNode(Person* data, PersonNode* next){
	_data=data;
	_next=next;

}

//-------------------------------------------------------------------------------------------------------------------------
// A method that extract person from the queue
Person* PersonQueue::dequeue(){
	if(_head == NULL)
		return NULL;
		
	Person* temp = _head->_data;
	_head = _head -> _next;
	if(_head == NULL)
		_tail = _head;
	return temp;
	
		
}
	
//--------------------------------------------------------------------------------------------------------------------------------
// method that insert people to the queue	
void PersonQueue::enqueue( Person* p){
	if(_head == NULL){
		_head = new PersonNode(p, NULL);
		_tail = _head;
	}
	else {
		_tail -> _next = new PersonNode(p, NULL);
		_tail = _tail -> _next;
		}
}

//---------------------------------------------------------------------------------------------------------------------------------------

// destroy constructor
PersonQueue::~PersonQueue(){
 	while(_head!=NULL){
		PersonNode *tempNode =_head;//point to the node
		Person *temp = tempNode-> _data;// point on the data
		_head=_head->_next;//move to the next node
		delete (tempNode);//delete node
		delete (temp);// delete data
		}

}
//-----------------------------------------------------------------------------------------------------------------------------------------