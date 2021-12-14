#include <iostream>
#include <cstring>
#include <vector>
#include "Item.h"

using namespace std;

Item::Item(char* newDescription){
strcpy(description, newDescription);

}

char* Item::getDescription(){
    return description;
}

Item::~Item(){

}

