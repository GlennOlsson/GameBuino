#include <SPI.h>
#include <Gamebuino.h>
#include "Queue.h"
#include "Snake.h"

Gamebuino gb;

int i = 0;

Snake* snake;

//Gets some prints with this version

void drawSnake(){
	Queue& positions = snake->positions;
	for(auto it = positions.begin(); !it.isEnd(); ++it){
		gb.display.drawRect((*it).x, (*it).y, 2, 2);
	}
}

void setup(){
	gb.begin();
	gb.titleScreen(F("Snake")); 
	Serial.begin(9600);

	int randX = random(0, LCDWIDTH);
	int randY = random(0, LCDHEIGHT);
	int dir = random(0, 4);
	snake->x = randX;
	snake->y = randY;
	snake = new Snake(30, 30, dir);
	gb.display.drawRect(30, 30, 4, 4);
	drawSnake();
}

void input()
{
  if(gb.buttons.pressed(BTN_C))
    gb.titleScreen(F("Snake"));
}

void update(){
}

void draw(){
	// gb.display.drawRect(i, 50, 2, 2);
}

void loop()
{
	if (gb.update()){
		drawSnake();
		gb.display.drawRect(30, 30, 10, 10);
		Serial.print("Hello, world");
	}
}
