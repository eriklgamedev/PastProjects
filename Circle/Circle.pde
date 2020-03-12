/*
Made by: Erik Luo
Date: 10/25/2017
This program allows the audience to create different epicycloids 
with different color. This program creates epicycloids with different size 
and patterns. As the audience click the mouse button, the radius increases 
and the pattern changes. Some difficulty I encountered was understanding 
the mathematic of epicycloids and making the program from there. 
I had fun trying out all the patterns and shapes. 
*/
//var
int c = 1;
color r = color(255,0,0);
color g = color(0,255,0);
color d = color(0,0,255);

void setup(){
  size(1000,1000);
  smooth();
  background(#cccccc);
}
 
float count = 0;//Ball counter
float xNew,yNew;//Ball x,y
float a = 13;
float b = 1;
float n = a/b;
 
void draw(){
    if(mousePressed){
    b = b+1;
    }
    epicycloid(a,b,width/2,height/2,0.5,count);//Function for epicycloid
    count = count + 0.6;
    if(count > 20000){ //Total number of balls
    noLoop();
    }
}
 
void epicycloid(float a,float b,int translateX,int translateY,float strokeWt, float count){
  float count2 = count;
  pushMatrix();//Center the graph
  translate(translateX,translateY);//Center
  if(count2<=2001){
    xNew = (a+b)*cos(radians(count))+b*cos(((a+b)*count));//Fomula x (a+b)cosphi-bcos((a+b)/bphi) phi = parameter
    yNew = (a+b)*sin(radians(count))-b*sin(((a+b)*count)); //Fomula y
    
    xNew = xNew * 4;
    yNew = yNew * 4;
    
    stroke(0,0,0);//Color change
    if(c == 1){
    
    fill(r);
    c = 2;
    }else if (c == 2){
    
    fill(g);
    c = 3;
    }else if (c == 3){
    
    fill(d);
    c = 1;
    }
    
    
    strokeWeight(strokeWt);
    ellipse(xNew,yNew,10,10);//balls

  }
  popMatrix();
}
