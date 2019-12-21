#include <Arduino.h>
#line 1 "/Users/glenn/Documents/VS Code/GameBuino/HelloWorld/HelloWorld.ino"
#include <SPI.h>
#include <Gamebuino.h>
#include "Queue.h"
#include "Snake.h"

Gamebuino gb;

int i = 0;

Snake* snake;


#line 13 "/Users/glenn/Documents/VS Code/GameBuino/HelloWorld/HelloWorld.ino"
void drawSnake();
#line 20 "/Users/glenn/Documents/VS Code/GameBuino/HelloWorld/HelloWorld.ino"
void setup();
#line 35 "/Users/glenn/Documents/VS Code/GameBuino/HelloWorld/HelloWorld.ino"
void input();
#line 41 "/Users/glenn/Documents/VS Code/GameBuino/HelloWorld/HelloWorld.ino"
void update();
#line 44 "/Users/glenn/Documents/VS Code/GameBuino/HelloWorld/HelloWorld.ino"
void draw();
#line 48 "/Users/glenn/Documents/VS Code/GameBuino/HelloWorld/HelloWorld.ino"
void loop();
#line 13 "/Users/glenn/Documents/VS Code/GameBuino/HelloWorld/HelloWorld.ino"
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

