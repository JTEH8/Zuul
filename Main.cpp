#include <iostream>
#include <cstring>
#include <vector>
#include "Item.h"
#include "Room.h"

using namespace std;

void help();
int main(){
    bool x = true;
    char YesNo[10];
    cout << "Welcome to Zuul, an adventure game with more than a dozen rooms!" << endl;
    cout << endl;
    cout << "You're at the Robert D. Clark debate tournament held by the University of Oregon." << endl;
    cout << endl;
    cout << "Could you help me pick up some of the items I've left behind at the rounds I've had today? (Answer 'yes' or 'no')'" << endl;
    cin >> YesNo;
    if(strcmp(YesNo, "no") == 0){
        cout << "I guess I'll just do it myself. *sigh* " << endl;
        break;
    }
    if(strcmp(YesNo, "yes") == 0){
    cout << "Thanks for helping me!" << endl;
    cout << endl;
    cout << "I need you to get my pen, notebook, stopwatch, laptop, and schedule." << endl;
    cout << "It's getting late, we better get started. Your commands are HELP, MOVE, GET, DROP, and INVENTORY." << endl;
    while(x == true){
    
    }
    }
}

void help(){
    cout << "You're playing Zuul, an adventure game with more than a dozen rooms!" << endl;
    cout << endl;
    cout << "You're at the Robert D. Clark debate tournament held by the University of Oregon." << endl;
}