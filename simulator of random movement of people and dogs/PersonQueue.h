#ifndef PERSONQUEUE_H
#define PERSONQUEUE_H

class Person;
class PersonNode{
public:
	Person *_data;
	PersonNode*_next;
	PersonNode(Person* data, PersonNode* next=0);

};

class PersonQueue{
	PersonNode *_head, *_tail;
public:
	Person* dequeue();
	void enqueue(Person* p);
	PersonQueue();
	~PersonQueue();

};
#endif

