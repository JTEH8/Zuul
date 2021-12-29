#ifndef ROOM_H
#define ROOM_H
#include <cstring>
#include <vector>
#include <map>
#include "Item.h"

using namespace std;

class Room {
private:
char description[100];
map<char*, Room*> exits;
vector <Item> Items;
public:
Room(char* newDescription);
~Room();
Room* getExit(char* newDirection);
void setExit(char* newDirection, Room* neighbor);
void ExitsAndItems();
Item getItem(char* itemTitle);
void setItem(Item newItem);
void printItems();
char* getRoomDescription();
};

#endif