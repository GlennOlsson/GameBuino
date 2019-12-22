#ifndef QUEUE_H
#define QUEUE_H

// #include <iostream>
// using namespace std;

class Node {
	public:
	Node* prev;
	int x;
	int y;
	Node(int x, int y): x(x), y(y){}
	bool operator==(Node& other){
		return x == other.x && y == other.y;
	}
};

class QueueIterator {
	public:

	Node* node;

	QueueIterator(Node* n): node(n){}

	Node& operator*(){
		return *node;
	}
	Node*& operator++(){
		node = node->prev;
		return node;
	}

	bool isEnd(){
		return node == nullptr;
	}
};

class Queue {
	public:

	Node* root;
	Node* last;

	int length;

	Queue(){
		length = 0;
	}

	void push(int x, int y);

	Node* pop();

	Node*& peek();

	Node*& peekBottom();

	QueueIterator& begin();

	bool contains(Node* n);

	~Queue(){
		while(length > 0){
			// std::cout << "popping" << std::endl;
			delete pop();
		}
		// cout << "done popping" << endl;
	}
};

#endif