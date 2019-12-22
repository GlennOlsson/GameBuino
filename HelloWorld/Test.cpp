// #include "Queue.h"
// #include "Snake.h"
// #include <iostream>
// #include <stdlib.h>
// #include <time.h>    
// #include <stdio.h>

// using namespace std;

// Snake* snake;

// int random(int min, int max){
// 	return rand() % max + min;
// }

// void init(){
// 	srand (time(NULL));

// 	int randX = random(0, 84);
// 	int randY = random(0, 48);
// 	int dir = random(0, 4);
// 	snake = new Snake(randX, randY, dir);
// 	snake->init();
// }

// void foo(){
// 	int index = 0;
// 	Queue* positions = snake->positions;
// 	cout << "Start prints\n" << endl;
// 	cout << positions->length << endl;
// 	cout << (*positions->begin()).x << endl;
// 	cout << "," << endl;
// 	cout << (*(++positions->begin())).y << endl;
// 	auto& it = positions->begin();
// 	for(int i = 0; i < positions->length; i++){
// 		cout << (*it).x << "," << (*it).y << endl;
// 		++it;
// 		// cout << ",");
// 	}
// 	cout << "End print\n";

// 	cout << "end" << endl;
// }

// int main(int argc, char const *argv[])
// {

// 	Queue* qt = new Queue();
// 	Queue q= *qt;
// 	q.push(2, 5);
// 	q.push(2, 6);
// 	q.push(2, 7);
// 	q.push(2, 8);
// 	q.push(2, 9);
// 	auto& it = q.begin();
// 	for(int i = 0; i < q.length; i++){
// 		cout << (*it).x << "," << (*it).y << endl;
// 		++it;
// 	}

// 	delete qt;

// 	// auto tmp = q.pop();
// 	// cout << "popped " << tmp->x << ", " << tmp->y << endl;
// 	// it = q.begin();
// 	// for(int i = 0; i < q.length; i++){
// 	// 	cout << (*it).x << "," << (*it).y << endl;
// 	// 	++it;
// 	// }
// 	// tmp = q.pop();
// 	// cout << "popped " << tmp->x << ", " << tmp->y << endl;
// 	// it = q.begin();
// 	// for(int i = 0; i < q.length; i++){
// 	// 	cout << (*it).x << "," << (*it).y << endl;
// 	// 	++it;
// 	// }

// 	// cout << "hello" << endl;
// 	// init();
// 	// foo();
// 	// for(int i = 0; i < 6000000; i++){
// 	// 	snake->move();
// 	// 	foo();
// 	// }

// 	return 0;
// }
