#include <SPI.h>
#include <Gamebuino.h>
#include "Queue.h"
#include "Snake.h"

Gamebuino gb;

int i = 1;
int loops = 0;

Snake* snake;
Food* food;

//Gets some prints with this version

void drawSnake(){
	Queue& positions = snake->positions;
	auto& it = positions.begin();
	for(int i = 0; i < positions.length; i++){
		// Serial.print((*it).x);
		// Serial.print(",");
		// Serial.print((*it).y);
		// Serial.print("\n");
		gb.display.drawRect((*it).x, (*it).y, 1, 1);
		++it;
	}
	delete &it;
}

void drawFood(){
	gb.display.drawRect(food->x, food->y, 1, 1); 
}

void generateFood(){
	int foodX = random(0, 84);
	int foodY = random(0, 48);
	food = new Food(foodX, foodY);
}
 
void setup(){
	gb.begin();
	gb.pickRandomSeed();
	gb.titleScreen(F("Snakes")); 
	Serial.begin(9600);

	int randX = random(0, LCDWIDTH);
	int randY = random(0, LCDHEIGHT);
	int dir = random(0, 4);
	snake = new Snake(randX, randY, dir);
	snake->init();

	generateFood();
}

void input(){
	if(gb.buttons.pressed(BTN_C))
		gb.titleScreen(F("Snake"));
	else if (gb.buttons.pressed(BTN_A)){
		// gb.display.drawRect(30, 30, 1, 1);
		i ++; 
	}
	else if (gb.buttons.pressed(BTN_B)){
	} 
	
	auto currPos = snake->positions.peekBottom();
	int currX = (*currPos).x;
	int currY = (*currPos).y;
	
	if (gb.buttons.pressed(BTN_UP) && snake->direction % 2 != 0) {
		snake->setDirection(0);
	} else if (gb.buttons.pressed(BTN_RIGHT) && snake->direction % 2 != 1) {
		snake->setDirection(1);		
	} else if (gb.buttons.pressed(BTN_DOWN) && snake->direction % 2 != 0) {
		snake->setDirection(2);		
	} else if (gb.buttons.pressed(BTN_LEFT) && snake->direction % 2 != 1) {
		snake->setDirection(3);		
	}
}

void update(){
}

void draw(){
	// gb.display.drawRect(i, 50, 2, 2);
}

void moveSnake(){
	if(loops++ != 1)
		return;
	loops = 0;
	
	snake->move();

	auto currPos = snake->positions.peekBottom();
	int currX = (*currPos).x;
	int currY = (*currPos).y;
	if(currX == food->x && currY == food->y){
		snake->eat();
		delete food;
		generateFood();
	}

}

void loop(){
	if (gb.update()){
		input();
		moveSnake();
		drawSnake();
		drawFood();
		// gb.display.drawRect(30, 30, i, i);
		// Serial.println("Hey"); 
	}
}
