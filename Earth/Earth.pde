/*
Made by: Erik Luo
Date: 10/6/2017
This program draws a globe with an assigned image
*/
PImage img;
PShape globe;


int t = 0;
int v = 100;

PVector location = new PVector((540),(360));
PVector velocity = new PVector(1,1);
int x,y;
PVector mouse = new PVector(mouseX , mouseY);

void setup(){
x = width/2;
y = height/2; 
size(1080, 720, P3D);
img = loadImage("E:/Programming/Erik Luo/1.jpg");
globe = createShape(SPHERE, 280);
globe.setTexture(img);
noStroke();
smooth();
background(0);
}



void draw(){
  
  background(0);
  camera(mouseX, mouseY, (height/2) / tan(PI/6), mouseX, mouseY, 0, 0, 1, 0);
  translate(width/2, height/2, -100);
  stroke(255);
  beginShape();
  texture(img);
  sphere(300);
  endShape();  
  mousePressed();
  display1();
  

}
void display1(){
  /*
  if(v != 0){
  v = v-1;
  }
  scale(v);
  */
  fill(255);
  ellipse(x,y,25,25);
  if (x < mouseX){
   x = x++;
  }else if(x > mouseX){
   x = x--;
  }else if(x == mouseX){
   x = 0; 
  }
  if(y < mouseY){
    y = y++;
  }else if(y < mouseY){
    y = y--;
  }else if(y == mouseY){
    y = 0;
  }
}
/*
void display(){
  
  location.add(velocity);
  if (location.x < mouseX){
    velocity.x = velocity.x + 1;
  }else if(location.x > mouseX){
    velocity.x = velocity.x - 1;
  }
  if(location.y < mouseY){
    velocity.y = velocity.y + 1;
  }else if(location.y < mouseY){
    velocity.y = velocity.y - 1;
  }
  if(v != 0){
  v = v-1;
  }
  scale(v);
 
  if(mousePressed == true){
  fill(255);
  ellipse(location.x,location.y,50,50);
  }
}
*/
