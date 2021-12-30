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

void Room::removeItem(char* itemTitle){
vector <Item> :: iterator ptr2;
for(ptr2 = Items.begin(); ptr2 != Items.end(); ptr2++){
if(strcmp(ptr2->getDescription(), itemTitle) == 0){
Items.erase(ptr2);
break;
    }
}
}
void Room :: printItems(){
    vector <Item> :: iterator ptr3;
    for(ptr3= Items.begin(); ptr3 != Items.end(); ptr3++){
    cout << ptr3->getDescription() << "," << endl;
  }
}

void Room::ExitsAndItems(){
    cout << "Exits:" << endl;
  //iterate through exits and print out directions
  for(map<char*, Room*>::iterator ptr = exits.begin(); ptr != exits.end(); ptr++){
    cout << " " << ptr->first;
  }
  cout << "Items in this room:" << endl;
  printItems();
}


Room* Room::getExit(char* newDirection){
map<char*, Room*>:: iterator ptr;
for(ptr = (exits).begin(); ptr != exits.end(); ptr++){
if(strcmp(ptr->first, newDirection) == 0){
return ptr->second;
    }
}
}
char* Room :: getRoomDescription(){
    return description;
}




