#ifndef QUEUE_H
#define QUEUE_H

class Node {
	public:
	Node* prev;
	int x;
	int y;
	Node(int x, int y): x(x), y(y){}
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

	QueueIterator& begin();
};

#endif