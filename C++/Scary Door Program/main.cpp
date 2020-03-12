//  Title: Scary Door Program
//  Created By: Erik Luo
//  version 0.5
//  Date Created: Feb 27th 2017
//  Last Updated: Feb 27th 2017
//  Know Limitations:

//  This is a text based advanture game

/*
 a) Displays 3 "Haunted" Doors
 b) Asks user to choose a door
 c) Displays a message / graphic based on the user's choice
 d) Gives a second choice for each door (using nested if statements, an if within an if).
*/



#include <iostream>
using namespace std;

int main()
{
    int choice;
    int choice2;
    int choice3;
    int choice4;
    int choice5;
    int choice6;
    int choice7;
    
    cout << "     I slowly opened my eyes. The only light in this strange dark room flashed in my eyes. I stand up with pain. right in front of me is three stange looking doors. \n     The one on the left is a old broken wood door, it have a big crack on the top and it lead to what seems like the infinite darkness. \n     The one in the center is a cold black iron door, it has a window that's emitting stange green light. \n     The one on the right is a gate that has a lock on it, seems to be a stair case up. \n";
    cout << "______________      ______________      ______________\n";
    cout << "||----------||      ||----------||      ||----------||\n";
    cout << "||          ||      ||          ||      ||          ||\n";
    cout << "||          ||      ||          ||      ||          ||\n";
    cout << "||          ||      ||          ||      ||          ||\n";
    cout << "||          ||      ||          ||      ||          ||\n";
    cout << "||          ||      ||          ||      ||          ||\n";
    cout << "||          ||      ||          ||      ||          ||\n";
    cout << "||          ||      ||          ||      ||          ||\n";
    cout << "||          ||      ||          ||      ||          ||\n";
    cout << "||          ||      ||          ||      ||          ||\n";
    cout << "||          ||      ||          ||      ||          ||\n";
    cout << "||          ||      ||          ||      ||          ||\n";
    cout << "||          ||      ||          ||      ||          ||\n";
    cout << "--------------      --------------      --------------\n";
    
    cout << " Wood door enter 1 \n Iron door enter 2 \n Gate enter 3 \n";
    cout << "Pleas enter the number to choose:  ";
    
    cin >> choice;
    if (choice == 1){//choice 1
        cout << "I opened the wood cracking door, there is a hallway extenting to the darkness. \n";
        cout << "1.Go forward\n2.Go back\n";
        cin >> choice2;
        if (choice2 == 1){// if player enter 1, else return main
            cout << "I walked in to the darkness and suddenly a light flash on, showing a long hallway and a door in the end of it.\n";
            cout << "1.Go forward\n2.Go back\n";
            cin >> choice3;
            if(choice3 == 1){
                cout << "I walked in to the darkness and suddenly a light flash on, showing a long hallway and a door in the end of it.\n";
                cout << "1.Go forward\n2.Go back\n";
                cin >> choice4;
                if (choice4 == 1){
                    cout << "I went closer to the door, it is white and new with a golden handle. I slowly opened the door and I see the sky filled with dark red clouds, in front of me there is a stair case, down to a ally to far distance. The dark dead tree on the side of the road seems to be telling me that the world has ended.\n";
                    cout << "1.Go forward\n2.Go back\n";
                    cin >> choice5;
                    if (choice5 == 1){
                    cout << "I know this is not a easy path, but the house behind me hunts me more. Maybe I can escape this nightmare. \n";
                        return main();
                    }else if (choice5 == 2){
                        return main();
                    }
                }else if (choice4 == 2){
                    return main();
                }
            }else if (choice3 == 2){
                return main();
            }
            
        }else if (choice2 == 2){
            return main();
        }
    }else if (choice == 2){//choice 2
        cout << "I opened the heavy iron door, there is only one green light in the darkness. \n";
        cout << "1.Go forward\n2.Go back\n ";
        cin >> choice2;
        if (choice2 == 1){
            cout << "I hear a high pitch sound, like some metal is been hit. I walk closer and I see a man hitting body on a iron block with hammer. Blood spread out everywhere.\n";
            cout << "1.Go forward\n2.Go back\n ";
            cin >> choice3;
            if(choice3 == 1){
                cout << "The man noticed me, he walked towards me and grabed me. He put me on the iron block and killed me.\n";
                return main();
            }else if (choice3 == 2){
                return main();
            }
        }else if (choice2 == 2){
            return main();
        }
    }else if(choice == 3){//choice 3
        cout << "I try to open the gate, but it is locked. \n";
        cout << "1.Go forward\n2.Go back\n3.Look around";
        cin >> choice2;
        if (choice2 == 1){
            cout << "I can't go forward if the door is locked.\n";
            return main();
        }else if (choice2 == 2){
            return main();
        }else if(choice2 == 3){
            cout << "I see a block on the wall that has a mark on it. I take off the block and finds a key.\n";
            cout << "1.Go forward\n2.Go back\n";
            cin >> choice3;
            if(choice3 == 1){
                cout << "I open the door and walked up the stair. The stair leads to another door. I think it leads to outside.\n";
                cout << "1.Go forward\n2.Go back\n";
                cin >> choice4;
                if (choice4 == 1){
                    cout << "I open the door. The sky is pure and blue, without a single cloud. Right in fornt of me, there is a golden stair case up to the infinite sky.\n";
                    cout << "                                          _                                                \n                                            ===                                                \n                                           =====                                               \n                                          =======                                              \n                                         =========                                             \n                                        ===========                                            \n                                      ==============                                           \n                                     ================                                          \n                                    ==================";
                    cout << "1.Go forward\n2.Go back\n";
                    cin >> choice5;
                    if (choice5 == 1){
                    cout << "I walk up the golden stair case, for what seems like forever, the farther I go the more I think that this stair case might never end. Is not too late to go back now.\n";
                    cout << "1.Go forward\n2.Go back\n";
                    cin >> choice6;
                        if (choice6){
                        cout << "I keep going up, my feet is full of wounds and bloods, I'm going up, slowly. It might not be too late to go back. I think to my self looking to the unending stair case.\n";
                        cout << "1.Go forward\n2.Go back\n";
                        cin >> choice7;
                            if (choice7 == 1){
                            cout << "I keep going up and up, finaly I crash down, on the stair case. My consciousness is getting less and less clear, and slowly, I lost the sence of self.\n I woke up but this time not in my body, I appear as what seems as spirit. I noticed that I am flowting in the air. I realized that I cannot find the knowing of self, my thoughts and feelings comes from nowhere, and nothing. I am freed from all suffering, I flyed to the end of the stair case to what I know as truth...\n END";
                                return main();
                            }else if(choice7 == 2){
                                return main();
                            }
                        }else if (choice6 == 2){
                            return main();
                        }
                    }else if (choice5 == 2){
                        return main();
                    }
                }else if (choice4 == 2){
                    return main();
                }
            }else if (choice3 == 2){
                return main();
            }
        }
    }
    return 0;
}



