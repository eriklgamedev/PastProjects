/*
Made by: Erik Luo
Date: 10/3/2017
This application draws a snow man
*/

int value = 0;

void setup(){
size(2304,1296);
strokeWeight(8);
}
void draw(){

fill(250);
ellipse(1000,700,500,500);
ellipse(1000,500,400,400);
ellipse(1000,250,300,300);
fill(0,0,0);
ellipse(925,250,30,30);
ellipse(1075,250,30,30);
fill(255,0,0);
triangle(975,275,1000,250,1025,275);
if(mousePressed == true){
fill(0,0,0);
ellipse(mouseX,mouseY,15,15);
}

}




  
