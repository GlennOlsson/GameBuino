#ifndef SNAKE_H
#define SNAKE_H

struct Food {
	int x, y;
	Food(int x, int y): x(x), y(y){}
};

class Snake {
	public:

	int x;
	int y;
	Queue* positions;
	int direction; //0 - up, 1 - right, down, left
	bool hasEaten;

	// Snake(int startX, int startY, int dir): x(startX), y(startY), direction(dir), hasEaten(false){
	// 	positions = *new Queue();
	// }

	Snake(int startX, int startY, int dir): x(startX), y(startY), hasEaten(false), direction(dir){
		positions = new Queue();
	}

	void init();

	int length(){
		return positions->length;
	}
	
	void move();
	void setDirection(int dir);
	void eat();

	~Snake(){
		delete positions;
	}
};
#endif