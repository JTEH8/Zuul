//Item Class .cpp File
#include <iostream>
#include <cstring>
#include <vector>
#include "Item.h"

using namespace std;
//Copying the entered description to the Item's name
Item::Item(char* newDescription){
strcpy(description, newDescription);

}
//Getting the Item's name
char* Item::getDescription(){
    return description;
}
//Destructor
Item::~Item(){

}

