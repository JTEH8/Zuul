//.cpp file for the Room Class, thanks to Kyle Zhou for helping with this
#include <iostream>
#include <cstring>
#include <vector>
#include "Item.h"
#include "Room.h"

using namespace std;
//Constructor, copying the entered name to the description cstring
Room::Room(char* newDescription){
strcpy(description, newDescription);

}
//Setting the item by adding it to the vector of items in the class
void Room::setItem(Item newItem){
Items.push_back(newItem);
}
//Getting the item from the room by using an iterator to find the item by name
Item Room::getItem(char* itemTitle){
vector <Item> :: iterator ptr;
for(ptr = Items.begin(); ptr != Items.end(); ptr++){
if(strcmp(ptr->getDescription(), itemTitle) == 0){
return (*ptr);
    }
}
return 0;
}
//Removing an item from the room by searching by the item's name and erasing
void Room::removeItem(char* itemTitle){
vector <Item> :: iterator ptr2;
for(ptr2 = Items.begin(); ptr2 != Items.end(); ptr2++){
if(strcmp(ptr2->getDescription(), itemTitle) == 0){
Items.erase(ptr2);
break;
    }
}
}
//Printing the items in the room using an iterator
void Room :: printItems(){
    vector <Item> :: iterator ptr3;
    for(ptr3= Items.begin(); ptr3 != Items.end(); ptr3++){
    cout << ptr3->getDescription() << ",";
  }
  cout << endl;
}
//Printing the exits with a map iterator
void Room::ExitsAndItems(){
    cout << "Exits:" << endl;
  //Prints out the exits to the room (Directions)
  for(map<char*, Room*>::iterator ptr = exits.begin(); ptr != exits.end(); ptr++){
    cout << " " << ptr->first;
  }
  cout << endl;
  cout << "Items in this room:" << endl;
  //PrintItems method from above
  printItems();
}
//Setting the exit by setting the exit in a particular direction to go to a Room's neighbor
void Room::setExit(char* newDirection,Room* neighbor){
  exits[newDirection] = neighbor;
  }
//Getting the exit (next room) by checking what room the entered direction goes to
Room* Room::getExit(char* newDirection){
map<char*, Room*>:: iterator ptr;
for(ptr = (exits).begin(); ptr != exits.end(); ptr++){
if(strcmp(ptr->first, newDirection) == 0){
return ptr->second;
    }
}
return 0;
}
//Setting the win ID of the room (Only used for the dormitories)
void Room::setWinID(int number){
  WinID = number;
}
//Getting the win ID of the room (Only used for the dormitories)
int Room :: getWinID(){
  return WinID;
}
//Getting the name of the Room
char* Room :: getRoomDescription(){
    return description;
}




