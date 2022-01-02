//Header Guard
#ifndef ROOM_H
#define ROOM_H
#include <cstring>
#include <vector>
#include <map>
#include "Item.h"

using namespace std;
//Room Class
class Room {
private:
//Room Name
char description[100];
//WinID (Only changed for the winning room)
int WinID = 0;
//Map of exits
map<char*, Room*> exits;
//Vector of Items (To store the items in the room)
vector <Item> Items;
public:
//Constructor
Room(char* newDescription);
~Room();
//Methods for exits
Room* getExit(char* newDirection);
void setExit(char* newDirection, Room* neighbor);
void ExitsAndItems();
//Item methods
Item getItem(char* itemTitle);
void setWinID(int number);
void setItem(Item newItem);
void removeItem(char* itemTitle);
void printItems();
//Win ID method
int getWinID();
//Getting the Room name 
char* getRoomDescription();
};

#endif