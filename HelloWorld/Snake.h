#ifndef SNAKE_H
#define SNAKE_H

class Snake {
	public:

	int x;
	int y;
	Queue positions;
	int direction; //0 - up, 1 - right, down, left
	bool hasEaten;

	Snake(int startX, int startY, int dir): x(startX), y(startY), direction(dir), hasEaten(false){
		positions = *new Queue();
	}

	void init();

	Node* move();
	void setDirection(int dir);
	void eat();
};
#endif SNAKE_H