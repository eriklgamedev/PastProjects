/*
Made by: Erik Luo
Date: 10/23/2017
This program is called follow mouse program. 
The program creates X number of different color balls, 
and the balls follow the mouse. When the ball hit the edge, 
it will be moved to the opposite edge. 
This program creates interesting visuals to the audience. 
Some difficulty I encountered was finding out how to make objects 
follow the position of the mouse with velocity, and making it move 
from edge to edge. 
It turned out to be an interesting program, I had fun coding it.
*/
Mover[] movers = new Mover[2500];
int c = 1;

color r = color(255,0,0);
color g = color(0,255,0);
color b = color(0,0,255);
PShape globe;
void setup() {
  size(1080, 1080);
  //globe = createShape(SPHERE, 280);
  smooth();
  background(0);
  // Initializing all the elements of the array
  for (int i = 0; i < movers.length; i++) {
    movers[i] = new Mover(); 
  }
}

void draw() {
  noStroke();
  stroke(255);
  beginShape();
  endShape();  
  fill(255,10);
  // Calling functions of all of the objects in the array.
  for (int i = 0; i < movers.length; i++) {
    movers[i].update();
    movers[i].checkEdges();
    movers[i].display(); 
  }
}

class Mover {

  PVector location;
  PVector velocity;
  PVector acceleration;
  float topspeed;

  Mover() {
    location = new PVector(random(width),random(height));
    velocity = new PVector(0,0);
    topspeed = 4;
  }

  void update() {
    PVector mouse = new PVector(mouseX,mouseY);
    PVector dir = PVector.sub(mouse,location);  
    dir.normalize();     
    dir.mult(0.5);       
    acceleration = dir;  
    velocity.add(acceleration);//Move towards
    velocity.limit(topspeed);
    location.add(velocity);
  }

  void display() {
    //Color
    stroke(0);
    if(c == 1){
    fill(r);
    c = 2;
    }else if (c == 2){
    fill(g);
    c = 3;
    }else if (c == 3){
    fill(b);
    c = 1;
  }
    ellipse(location.x,location.y,10,10);
  }

  void checkEdges() {
  //Back
    if (location.x > width) {
      location.x = 0;
    } else if (location.x < 0) {
      location.x = width;
    }

    if (location.y > height) {
      location.y = 0;
    }  else if (location.y < 0) {
      location.y = height;
    }

  }

}
