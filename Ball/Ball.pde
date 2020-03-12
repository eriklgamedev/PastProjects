/*
Created by: Erik Luo
Date: 10/25/2017
This program is a bouncing ball program that have multiple ball bouncing around 
while changing color as the same time. 
The challenges I had with is program was learning the rules and limitation of Java. 
I did practice my logic and code understanding. 
Things such as vectors.
*/
int s = 10;
Mover[] movers = new Mover[s];
int t = 0;
int c = 1;
color r = color(0,249,255);
color g = color(0,159,255);
color b = color(9,0,255);
void setup() {
  size(1000,500);
  smooth();
  background(255);
  for (int i = 0; i < movers.length; i++) {
    movers[i] = new Mover(); //ball array
  }
}

void draw() {
  noStroke();
  fill(255,10);
  rect(0,0,width,height);
   for (int i = 0; i < movers.length; i++) {//ball
    movers[i].display(); 
    movers[i].checkEdges(); 
  }

  
}
class Mover {

PVector location = new PVector(100,100);//Vector
PVector velocity = new PVector(1,3.3);
Mover(){
location = new PVector(random(width),random(height));
velocity = new PVector(5,10);
}


void display(){
  stroke(0);
  if(c == 1){//Colour change
    fill(r);
    c = 2;
    }else if (c == 2){
    fill(g);
    c = 3;
    }else if (c == 3){
    fill(b);
    c = 1;
  }
    
  ellipse(location.x,location.y,30,30);//Ball
}


void checkEdges(){//Collision
  location.add(velocity);
  if ((location.x > width) || (location.x < 0)) {
    velocity.x = velocity.x * -1;
  }
  if ((location.y > height) || (location.y < 0)) {
    velocity.y = velocity.y * -1;
  }

 }
 }
