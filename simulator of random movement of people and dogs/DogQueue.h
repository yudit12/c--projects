# ifndef DOGQUEUE_H
# define  DOGQUEUE_H

class Dog;
class DogNode{
public:
	Dog *_data;
	DogNode*_next;
	DogNode(Dog* data, DogNode* next=0): _data(data), _next(next){}

};

class DogQueue{
	DogNode *_head, *_tail;
public:
	Dog* dequeue();
	void enqueue( Dog* d);
	DogQueue();
	~DogQueue();
};
#endif