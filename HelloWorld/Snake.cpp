#include "Queue.h"
#include "Snake.h"
#include <Gamebuino.h>

// #include <iostream>
// using namespace std;

void Snake::init(){
	int xDir, yDir;
	if(direction == 0){
		xDir = 0;
		yDir = 1;
	} else if(direction == 1){
		xDir = -1;
		yDir = 0;
	} else if(direction == 2){
		xDir = 0;
		yDir = -1;
	} else { // direction == 3
		xDir = -1;
		yDir = 0;
	}

	int xTmp = this->x;
	int yTmp = this->y;
	for(int i = 4; i >= 0; i--){
		xTmp = x + (xDir * i);
		yTmp = y + (yDir * i);
		if(xTmp < 0)
			xTmp = LCDWIDTH + xTmp;
		
		if(yTmp < 0)
			yTmp = LCDHEIGHT + yTmp;

		positions.push(xTmp % LCDWIDTH, yTmp % LCDHEIGHT);
	}
}

void Snake::move(){
	int newX, newY;
	if(direction == 0){
		newX = x;
		newY = y - 1;
	} else if(direction == 1){
		newX = x + 1;
		newY = y;
	} else if(direction == 2){
		newX = x;
		newY = y + 1;
	} else { // direction == 3
		newX = x - 1;
		newY = y;
	}
	if(newX < 0)
		newX = LCDWIDTH + newX;
		
	if(newY < 0)
		newY = LCDHEIGHT + newY;

	positions.push(newX % LCDWIDTH, newY % LCDHEIGHT);
	x = newX,
	y = newY;
	if(!hasEaten){
		Node* tmp = positions.pop();
		if(tmp != nullptr)
			delete tmp;
		
	} else { //Don't remove last if just eaten
		hasEaten = false;
	}
}

void Snake::setDirection(int dir){
	direction = dir;
}

void Snake::eat(){
	hasEaten = true;
}