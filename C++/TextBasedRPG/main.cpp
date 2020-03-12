//  Title: Programming 12 Project
//  Created By: Erik Luo
//  version 0.5
//  Date Created: Oct 18th 2017
//  Last Updated: Oct 18th 2017
//  Know Limitations: No limitations
// A term based RPG with text based world
/*
 Map:
 How to make self updating map 
 The goal of map:
 Allow the player to see their path 
 However the action is all random
 Procedural generate map and room when start game
 Allow the player to see them self and other things
 ***************
 ***D****#***B**    E is enemy    B is boss
 ********P*$****    P is player   D is doungeon
 ***************    $ is treasure
 
 Loading map
 Showing map
 
 
 Movement
 If player enter w, P will move in the map.
 
 var:
 Position now
 P Positions: 4 values
 Which match the key WASD
 
 */


#include <iostream>

using namespace std;
//Global

//Character
int levels = 1;
int exp = 0;
int hp = 30 * levels;
int sp = 10 * levels;
int Atk = 5 * levels;
//Enemy
int Elevels = levels + 1;
int Ehp = 10 * Elevels;
int Eatk = 1 * Elevels;
//Steps
int step;
char A = 'A';
char B = 'B';
char C = 'C';
char D = 'd';
int a = 0;
int b = 0;
int c = 0;
int d = 0;
int restart = 0;
//treasure
int treasure = 0;
int key = 0;
int turns = 0;
int treasureN[4] = {1,2,3,4};

//BossRoom
string openDoor;
int boss = 0;
//Dungeon
class dungeon{
public:
    int ridle[5] = {1,2,3,4,5};
    int randRidle = rand()% 5;
    int ridleAction = ridle[randRidle];
    int done[5] = {0,0,0,0,0};
    string answer[5] = {};
};

//Action
//dungeon

int dungeoN(int turns){//dungeon system
    dungeon one;
    while (turns == 1){
        
        if (one.ridleAction == 1 && one.done[0] == 0){
            cout << "\nAnswer this ridle and you will get a reward! \n You will always find me in the past. I can be created in the present, But the future can never taint me. What am I?\n";
            cin >> one.answer[0];
            if(one.answer[0] == "stamp" || one.answer[0] == "A stamp"){
                cout << "Correct! You gained 100 exp!\n";
                exp = exp + 100;
                one.done[0] = 1;
                turns = 0;
            }else {
                cout << "Incorrect! Try again next time!";
                one.done[0] = 0;
                return turns;
            }
        }else if (one.ridleAction == 2 && one.done[1] == 0){
            cout << "\nAnswer this ridle and you will get a reward! \n What flies without wings?\n";
            cin >> one.answer[1];
            if(one.answer[1] == "time" || one.answer[1] == "Time"){
                cout << "Correct! You gained 100 exp!\n";
                exp = exp + 100;
                one.done[1] = 1;
                turns = 0;
            }else{
                cout << "Incorrect! Try again next time!";
                one.done[1] = 0;
                return turns;
            }
        }else if (one.ridleAction == 3 && one.done[2] == 0){
            cout << "\nAnswer this ridle and you will get a reward! \n Although I’m far from the point, I don’t make mistakes, I fix yours. What am I?\n";
            cin >> one.answer[2];
            if(one.answer[2] == "Eraser" || one.answer[2] == "eraser" || one.answer[2] == "Pencil" || one.answer[2] == "pencil"){
                cout << "Correct! You gained 100 exp!\n";
                exp = exp + 100;
                one.done[2] = 1;
                turns = 0;
            }else{
                cout << "Incorrect! Try again next time!";
               one.done[2] = 1;
                return turns;
            }
        }else if (one.ridleAction == 4 && one.done[3] == 0){
            cout << "\nAnswer this ridle and you will get a reward! \n Which word does not belong in the following list: Stop cop mop chop prop shop or crop?\n";
            cin >> one.answer[3];
            if(one.answer[3] == "or" || one.answer[3] == "Or"){
                cout << "Correct! You gained 100 exp!\n";
                exp = exp + 100;
                one.done[3] = 1;
                turns = 0;
            }else{
                cout << "Incorrect! Try again next time!";
                one.done[3] = 0;
                return turns;
            }
        }else if (one.ridleAction == 5 && one.done[4] == 0){
            cout << "\nAnswer this ridle and you will get a reward! \n What English word has three consecutive double letters?\n";
            cin >> one.answer[4];
            if(one.answer[4] == "Bookkeeper" || one.answer[4] == "bookkeeper"){
                cout << "Correct! You gained 100 exp!\n";
                exp = exp + 100;
                one.done[4] = 1;
                turns = 0;
            }else{
                cout << "Incorrect! Try again next time!";
                one.done[4] = 0;
                return turns;
            }
        }
    }
    return turns;
}

int nothing(int turns) {
    cout << "\nYou moved, keep going to find the treasure.\n";
    turns = 0;
    return turns;
}

void character() {
    //Hp, Sp, Atk, Skill, Exp, Levels
    if (exp == 100){//level up
        levels ++;
        exp = 0;
        hp = 20 * levels;
        cout << "\nLeveled up! You are level " << levels << " !\n";
    }
    
}

int combat(int turns) {
    //When enter combat, choose action
    int action;
    cout << "\nA monster showed up!\n";
    while (Ehp > 0 && turns == 1 && hp > 0) {
        cout << "What do you want to do? \n Enter 1 to attack, 2 to use skill, 3 to heal\n";
        cin >> action;
        
        if (action == 1){
            Ehp = Ehp - Atk;
            cout << "The enemy took " << Atk << " damage, it has " << Ehp << " health left. \n";
        }else if (action == 2 && sp >= 5){
            cout << "Attack increased\n";
            Atk = Atk + 4;
            sp = sp-5;
        }else if (action == 3 && sp >= 5) {
            cout << "Healed 30 % HP\n";
            hp = hp + 20*levels*0.30;
            sp = sp - 5;
        }else if (sp <= 10){
            cout << "You don't have enough sp!\n";
        }else{
            cout << "Please enter 1,2,or 3\n";
            return combat(1);
        }
        
        //enemy combat
        int enemyAction[3] = {1,2,3};
        int erandAction = rand() % 3;
        int eactionNum = enemyAction[erandAction];
        if (eactionNum == 1 && Ehp > 0 && hp > 0){
            cout << "The monster attacked!\n";
            hp = hp - Eatk;
            cout << "You took " << Eatk << " damage, you have " << hp << " health left!\n";
        }else if (eactionNum == 3 && Ehp > 0 && hp > 0){
            cout << "The monster attacked!\n";
            hp = hp - Eatk;
            cout << "You took " << Eatk << " damage, you have " << hp << " health left!\n";
        }else if (eactionNum == 2 && Ehp > 0 && hp > 0){
            cout << "The moster used magic! Its attack increased! \n";
            Eatk = Eatk + 3;
        }//Player Death
        
        if (hp <= 0){
            cout << "You died!\n";
            cout << "Game restarted!\n";
            //Character
            levels = 1;
            exp = 0;
            hp = 10 * levels;
            sp = 10 * levels;
            Atk = 3 * levels;
            //Enemy
            Elevels = levels + 1;
            Ehp = 10 * Elevels;
            Eatk = 2 * Elevels;
            //Steps
            step = 0;
            //treasure
            treasure = 0;
            key = 0;
            //BossRoom
            boss = 0;
            //Action
            turns = 0;
        }
        
    }while (turns == 1) {
        //Ememy Death
        if (Ehp <= 0 && boss == 0){
            cout << "Enemy died! \n";
            sp = 10 * levels;
            hp = 20 * levels;
            exp = exp + 50;
            Atk = 4 * levels;
            
            turns = 0;
            Ehp = 10 * Elevels;
            
        }else if (Ehp <= 0 && boss == 1){
            cout << "You've killed the boss! \n";
            exp = exp + 500;
            restart = 1;
            cout << restart;
            turns = 0;
            
            
        }
    }
    return turns;
}

int treasureGet(int turns) {//treasure system
    
    while (turns == 1) {
        
        if(step >= 1 && step < 10 && treasureN[0] == 1){
            treasure++;
            cout << "\nYou found a treasure! There are four treasure in total, keep exploring to find them all. Something might happen when you do!\n";
            turns = 0;
            treasureN[0] = 0;
        }else if(step >= 10 && step < 40 && treasureN[1] == 2){
            treasure++;
            cout << "\nYou found a treasure! You gained 100 EXP! There are four treasure in total, keep exploring to find them all. Something might happen when you do!\n";
            exp = exp + 100;
            turns = 0;
            treasureN[1] = 0;
        }else if(step >= 40 && step < 70 && treasureN[2] == 3){
            treasure++;
            cout << "\nYou found a treasure! You restored 20 SP. There are four treasure in total, keep exploring to find them all. Something might happen when you do!\n";
            turns = 0;
            treasureN[2] = 0;
        }else if(step >= 70 && treasureN[3] == 4){
            treasure++;
            cout << "\nYou found a treasure! Congrats! You've found the holy blade! And you have all four treasure! Four treasure put together, forms some kind of key!\n";
            Atk = Atk + 1000;
            key = key + 1;
            turns = 0;
            treasureN[3] = 0;
        }else{
            cout << "\nYou found a treasure chest, but there is nothing in it.\n";
            turns = 0;
        }
    }

    return turns;
}

void bossRoom() {//bossRoom
    if(key == 1 && step == 100){
        cout << "\nThere is a locked door, the door is made out of gold and iron, with two monster sculpture each side.\n";
        cout << "Do you want to open it? (Y/N)";
        cin >> openDoor;
        if (openDoor == "Y"){
            cout << "You used the key to open the door. And there is a monster that's ten times bigger than you, who seems to be the lord of all monsters. \n";
            cout << "The hero of the land! You've arrived, I have been waiting. Today you will die under my blade! The moster said.";
            key = key - 1;
            Ehp = Ehp * 100;
            boss = 1;
            combat(1);
            
        }else if (openDoor == "N"){
            cout<<" You left.\n";
            
            return;
        }
    }
}

int action(int turns){
    //Random action
    do{
        int action[6] = {0,1,2,3,4,5};
        int randAction = rand() % 6;
        int actionNum = action[randAction];
        if(actionNum == 0){//Nothing
            if(A == 'A'){
                A = '*';
                turns++;
            }else if (B == 'B'){
                B = '*';
                turns++;
            }else if (C == 'C'){
                C = '*';
                turns++;
            }else if (D == 'd'){
                D = '*';
                turns++;
            }
            
        }if(actionNum == 3){//Nothing
            if(A == 'A'){
                A = '*';
                turns++;
            }else if (B == 'B'){
                B = '*';
                turns++;
            }else if (C == 'C'){
                C = '*';
                turns++;
            }else if (D == 'd'){
                D = '*';
                turns++;
            }
            
            
        }if (actionNum == 1){//Combat
            if(A == 'A'){
                A = 'E';
                turns++;
            }else if (B == 'B'){
                B = 'E';
                turns++;
            }else if (C == 'C'){
                C = 'E';
                turns++;
            }else if (D == 'd'){
                D = 'E';
                turns++;
            }
            
            
       }if (actionNum == 5){//Combat
           if(A == 'A'){
               A = 'E';
               turns++;
           }else if (B == 'B'){
               B = 'E';
               turns++;
           }else if (C == 'C'){
               C = 'E';
               turns++;
           }else if (D == 'd'){
               D = 'E';
               turns++;
           }
        }if(actionNum == 2){//Treasure
            if(A == 'A'){
                A = '$';
                turns++;
            }else if (B == 'B'){
                B = '$';
                turns++;
            }else if (C == 'C'){
                C = '$';
                turns++;
            }else if (D == 'd'){
                D = '$';
                turns++;
            }
        }if(actionNum == 4){//Dungeon
            if(A == 'A'){
                A = 'D';
                turns++;
            }else if (B == 'B'){
                B = 'D';
                turns++;
            }else if (C == 'C'){
                C = 'D';
                turns++;
            }else if (D == 'd'){
                D = 'D';
                turns++;
            }
        }
    }while(turns < 4) ;
    return A;
    return B;
    return C;
    return D;
    
 }

int actionT(int turns){

    while (turns == 1){
        if(a == 1){
            switch(A){
                case '*':{
                    step++;
                    nothing(1);
                    a = 0;
                    return turns;
                }
                case 'E':{
                    step++;
                    combat(1);
                    a = 0;
                    return turns;
                }case '$':{
                    step++;
                    treasureGet(1);
                    a = 0;
                    return turns;
                }case 'D':{
                    step++;
                    dungeoN(1);
                    a = 0;
                    return turns;
                }
            }
            
        }else if(b == 1){
            switch(B){
                case '*':{
                    step++;
                    nothing(1);
                    b = 0;
                    return turns;
                }
                case 'E':{
                    step++;
                    combat(1);
                    b = 0;
                    return turns;
                }case '$':{
                    step++;
                    treasureGet(1);
                    b = 0;
                    return turns;
                }case 'D':{
                    step++;
                    dungeoN(1);
                    b = 0;
                    return turns;
                }
            }
        }
        else if(c == 1){
            switch(C){
                case '*':{
                    step++;
                    nothing(1);
                    c = 0;
                    return turns;
                }
                case 'E':{
                    step++;
                    combat(1);
                    c = 0;
                    return turns;
                }case '$':{
                    step++;
                    treasureGet(1);
                    c = 0;
                    return turns;
                }case 'D':{
                    step++;
                    dungeoN(1);
                    c = 0;
                    return turns;
                }
            }
            
        }
        else if(d == 1){
            switch(D){
                case '*':{
                step++;
                nothing(1);
                d = 0;
                return turns;
                }
                case 'E':{
                step++;
                combat(1);
                d = 0;
                return turns;
                }case '$':{
                step++;
                treasureGet(1);
                d = 0;
                return turns;
                }case 'D':{
                step++;
                dungeoN(1);
                d = 0;
                return turns;
                }
            }
        }
    }
    return turns;
}


int main() {
     restart = 0;
    //Movement:
    if(hp > 0){
        restart = 0;
        char move;
    mainloop:
        do {
        A = 'A';
        B = 'B';
        C = 'C';
        D = 'd';
        action(0);
        
        cout << "\n* "<<A<<" *\n"<<B<<" P "<<D<<"\n* "<<C<<" *\n\n";
        cout << "E is enemy    B is boss\nP is player   D is doungeon\n$ is treasure * is nothing\n";
        cout << "   w\n a s d To move around: ";
        cin >> move;
            
        switch (move){
            case ('w'):{
                a = 1;
                actionT(1);
                goto mainloop;
                //restart = 0;
                break;
            }case ('a'):{
                b = 1;
                actionT(1);
                //restart = 0;
                goto mainloop;
                break;
            }case ('s'):{
                c = 1;
                actionT(1);
                //restart = 0;
                goto mainloop;
                break;
            }case ('d'):{
                d = 1;
                actionT(1);
                //restart = 0;
                goto mainloop;
                break;
            }default:{
                cout << "Please enter a letter!";
                //restart = 0;
                goto mainloop;
                break;
            }
        }
        } while (restart == 0);
    }else if (hp <= 0){
        character();
    }
}

int Restart(){
    if(restart == 1){
        main();
    }
    return restart;
}
