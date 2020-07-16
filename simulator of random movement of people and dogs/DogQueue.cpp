#include "DogQueue.h"
#include "Dog.h"
#include <cstdlib>


//------------------------------------------------------------------------------------------------------------------------
//empty constractor
DogQueue::DogQueue(){
	_head = NULL;
	_tail = NULL;
}


//----------------------------------------------------------------------------------------------------------------------

// A method that extract dog from the queue
Dog* DogQueue::dequeue(){
	if(_head == NULL)
		return NULL;
		
	Dog* temp = _head->_data;
	_head = _head -> _next;
	if(_head == NULL)
		_tail = _head;
	return temp;
	
		
}
	
//---------------------------------------------------------------------------------------------------------------------------
// method that insert dogs to the queue	
	
void DogQueue::enqueue( Dog* d){
	if(_head == NULL){
		_head = new DogNode(d, NULL);
		_tail = _head;
	}
	else {
		_tail -> _next = new DogNode(d, NULL);
		_tail = _tail -> _next;
		}
}

//---------------------------------------------------------------------------------------------------------------------------------------
// destroy constructor
DogQueue::~DogQueue(){
	while(_head!=NULL){
		DogNode *tempNode =_head;//point to the node
		Dog *temp = tempNode-> _data;// point on the data
		_head=_head->_next;//move to the next node
		delete (tempNode);//delete node
		delete (temp);// delete data
		}
}
//--------------------------------------------------------------------------------------------------------------------------------------
