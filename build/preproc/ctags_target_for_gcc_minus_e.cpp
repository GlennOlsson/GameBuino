# 1 "/Users/glenn/Documents/VS Code/GameBuino/HelloWorld/HelloWorld.ino"
# 2 "/Users/glenn/Documents/VS Code/GameBuino/HelloWorld/HelloWorld.ino" 2
# 3 "/Users/glenn/Documents/VS Code/GameBuino/HelloWorld/HelloWorld.ino" 2
# 4 "/Users/glenn/Documents/VS Code/GameBuino/HelloWorld/HelloWorld.ino" 2
# 5 "/Users/glenn/Documents/VS Code/GameBuino/HelloWorld/HelloWorld.ino" 2

Gamebuino gb;

int i = 0;

Snake* snake;


void drawSnake(){
 Queue& positions = snake->positions;
 for(auto it = positions.begin(); !it.isEnd(); ++it){
  gb.display.drawRect((*it).x, (*it).y, 2, 2);
 }
}

void setup(){
 gb.begin();
 gb.titleScreen((reinterpret_cast<const __FlashStringHelper *>(
# 22 "/Users/glenn/Documents/VS Code/GameBuino/HelloWorld/HelloWorld.ino" 3
               (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 22 "/Users/glenn/Documents/VS Code/GameBuino/HelloWorld/HelloWorld.ino"
               "Snake"
# 22 "/Users/glenn/Documents/VS Code/GameBuino/HelloWorld/HelloWorld.ino" 3
               ); &__c[0];}))
# 22 "/Users/glenn/Documents/VS Code/GameBuino/HelloWorld/HelloWorld.ino"
               )));
 Serial.begin(9600);

 int randX = random(0, 84);
 int randY = random(0, 48);
 int dir = random(0, 4);
 snake->x = randX;
 snake->y = randY;
 snake = new Snake(30, 30, dir);
 gb.display.drawRect(30, 30, 4, 4);
 drawSnake();
}

void input()
{
  if(gb.buttons.pressed(6))
    gb.titleScreen((reinterpret_cast<const __FlashStringHelper *>(
# 38 "/Users/glenn/Documents/VS Code/GameBuino/HelloWorld/HelloWorld.ino" 3
                  (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 38 "/Users/glenn/Documents/VS Code/GameBuino/HelloWorld/HelloWorld.ino"
                  "Snake"
# 38 "/Users/glenn/Documents/VS Code/GameBuino/HelloWorld/HelloWorld.ino" 3
                  ); &__c[0];}))
# 38 "/Users/glenn/Documents/VS Code/GameBuino/HelloWorld/HelloWorld.ino"
                  )));
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
