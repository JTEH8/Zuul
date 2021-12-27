#include <iostream>
#include <cstring>
#include <vector>
#include "Item.h"
#include "Room.h"

using namespace std;

Room::Room(char* newDescription){
strcpy(description, newDescription);

}
void Room::setItem(Item newItem){
Items.push_back(newItem);
}

Item Room::getItem(char* itemTitle){
vector <Item> :: iterator ptr;
for(ptr = Items.begin(); ptr != Items.end(); ptr++){
if(strcmp(ptr->getDescription(), itemTitle) == 0){
return (*ptr);
    }
}
}

Room* Room::getExit(char* newDirection){
    map<char*, Room*>:: iterator ptr;
for(ptr = (exits).begin(); ptr != exits.end(); ptr++){
if(strcmp(ptr->first, newDirection) == 0){
return ptr->second;
    }
}
}

