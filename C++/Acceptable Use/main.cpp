//
//  main.cpp
//  Acceptable Use
//	
//  Created by Erik Luo on 2017-09-11.
//  Copyright © 2017 earl marriott. All rights reserved.
//  This program lets you read a list of law as you choose the number

#include <iostream>
using namespace std;

int main()
{
    string YN;
    int choice = 0;
    //Code
    cout << "       Do you want to read the Acceptable Use program?(Enter Y/N): ";
    cin >> YN;
    if(YN == "Y"){
        
        cout << "       Do's and don'ts of using technology in the school/classroom/district. \n\n      Please chooce the number of rule you want to see(between 1-13): ";
        cin >> choice;
        if(choice == 1){
            cout << "       1.Transmission of materials in violation of Canadian law\n\n";
            return main();
        }else if(choice == 2){
            cout << "       2.Transmission, storage, or duplication of pornographic material\n\n";
            return main();
        }else if(choice == 3){
            cout << "       3.Transmission or postiong or threatening, abusive, obscene material\n\n";
            return main();
        }else if(choice == 4){
            cout << "       4.Transmission or duplication of material in violation of copyright law\n\n";
            return main();
        }else if(choice == 5){
            cout << "       5.Participation in pyramid or chain mail\n\n";
            return main();
        }else if(choice == 6){
            cout << "       6.Harassment of others\n\n";
            return main();
        }else if(choice == 7){
            cout << "       7.Attempts at unauthorized access to data, servers, or external services\n\n";
            return main();
        }else if(choice == 8){
            cout << "       8.Attempts to vandalize district or external systems including malicious attempts to destroy data of another user, via virus or other means\n\n";
            return main();
        }else if(choice == 9){
            cout << "       9.Use of another user's account or resources\n\n";
            return main();
        }else if(choice == 10){
            cout << "       10.Use of abusive vulger, profane, obscene, or other inappropriate language\n\n";
                return main();
        }else if(choice == 11){
            cout << "       11.Re-posting personal mail without permission of the author\n\n";
            return main();
        }else if(choice == 12){
            cout << "       12.Sharing of passwords with others\n\n";
            return main();
        }else if(choice == 13){
            cout << "       13.No food or drink\n\n";
            return main();
        }else{
            cout << "Please enter numbers between 1-13. \n";
            return main();
        }
        
    }else if(YN =="N"){
        cout << "       Thank you for using our program! \n";
        
    }else{
        cout << "       Please enter Y or N \n";
        return main();
    }
}
