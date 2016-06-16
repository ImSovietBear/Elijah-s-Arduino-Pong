#include <TVout.h>
#include <stdio.h>

char buffer[20];

TVout TV;
int x = 30;
int y = 40;
int pts = 0;
bool win = false;
bool lose = false;

int t = 0;

int potVal;
int const potPin = A0;

bool toRight = true;
bool toTop = true;
void setup()  {
  TV.start_render(_NTSC);
  
}

void loop(){
  

  if(!win && !lose){
    TV.clear_screen();

    t = 9;
    
    if(pts > 9){
      win = true;
    }
    
  potVal= analogRead(potPin);

  potVal = potVal / 12;
  TV.draw_line(10, 0 + potVal, 10, 10 + potVal, 5);
  for(int i=0; i < 11; i++){
    if(x == 10 && y == potVal + i){
      toRight = true;  
    }
  }
  
  if(toRight == true){
    x++;
  }else if(toRight == false){
    x--;
  }

  if(x == 124){
    toRight = false; 
    pts ++; 
  }else if(x == 0){
    lose = true;
    TV.clear_screen(); 
  }

  if(toTop == true){
    y++;
  }else if(toTop == false){
    y--;
  }

  if(y == 80){
    toTop = false;  
  }else if(y == 0){
    toTop = true;
  }

  
  TV.draw_line(0 + x,0 +y ,0 + x,0 + y,1);

  TV.print_char(80,20, char(pts + 48));

  TV.delay(1);
  }else if(win){
    TV.clear_screen();
    

    if(t < 1){
      win = false;
      lose = false;
      int x = 30;
      int y = 40;
    }
    
    TV.print_str(20,40, "You Win!");
    TV.print_str(20,0, "Get ready");
    TV.print_char(50,20, char(t + 48));
    pts = 0;
    
    TV.delay(60);

    t--;
  }else if(lose){
    TV.clear_screen();
    

    if(t < 1){
      win = false;
      lose = false;
      int x = 30;
      int y = 40;
    }
    
    TV.print_str(20,40, "You Lose!");
    TV.print_str(20,0, "Get ready!");
    TV.print_char(50,20, char(t + 48));
    int x = 30;
    int y = 40;
    pts = 0;
    
    TV.delay(60);

    t--;
  }
  
}

