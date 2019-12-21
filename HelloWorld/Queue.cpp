#include "Queue.h"

void Queue::push(int x, int y){
	Node* n = new Node(x, y);
	root->prev = n;
	root = n;
}

Node* Queue::pop(){
	Node* tmp = last;
	last = last->prev;
	return tmp;
}

Node* Queue::peek(){
	return last;
}

QueueIterator Queue::begin(){
	return *new QueueIterator(last);
}
