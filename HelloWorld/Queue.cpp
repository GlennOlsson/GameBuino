#include "Queue.h"

// #include <iostream>
// using namespace std;

void Queue::push(int x, int y){
	// cout << "Pushing " << x << ", " << y << endl;

	// // cout << "Before push " << endl;
	// auto& it = *new QueueIterator(last);
	// for(int i = 0; i < length; i++){
	// 	cout << (*it).x << "," << (*it).y << endl;
	// 	++it;
	// }

	// cout << "input " << x << ", " << y << endl;

	Node* n = new Node(x, y);
	length++;
	if(root == nullptr){
		// cout << "Not nullprt" << endl;
		last = n;
		root = n;
		return;
	}
	
	root->prev = n;
	root = n;

	// cout << "After push " << endl;
	// it = QueueIterator(last);
	// for(int i = 0; i < length; i++){
	// 	cout << (*it).x << "," << (*it).y << endl;
	// 	++it;
	// }
}
 
Node* Queue::pop(){
	Node* tmp = last;
	last = last->prev;
	length--;
	// cout << "Popping" << tmp->x << ", " << tmp->y << endl;
	return tmp;
}

Node*& Queue::peek(){
	return last;
}

QueueIterator& Queue::begin(){
	return *new QueueIterator(last);
}
