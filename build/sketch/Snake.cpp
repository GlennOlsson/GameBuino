#include "Queue.h"
#include "Snake.h"
#include <Gamebuino.h>

void Snake::init(){
	int xDir, yDir;
	if(direction == 0){
		xDir = 0;
		yDir = -1;
	} else if(direction == 1){
		xDir = 1;
		yDir = y;
	} else if(direction == 2){
		xDir = x;
		yDir = 1;
	} else { // direction == 3
		xDir = 1;
		yDir = y;
	}

	int x = this->x;
	int y = this->y;
	for(int i = 0; i < 5; i++){
		x += xDir;
		y += yDir;
		positions.push(x % LCDWIDTH, y % LCDHEIGHT);
	}
}

Node* Snake::move(){
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
	positions.push(newX, newY);
	if(!hasEaten){
		return positions.pop();
	} else { //Don't remove last if just eaten
		hasEaten = false;
		return nullptr;
	}
}

void Snake::setDirection(int dir){
	direction = dir;
}

void Snake::eat(){
	hasEaten = true;
}