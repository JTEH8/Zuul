#ifndef ROOM_H
#define ROOM_H
#include <cstring>
#include "Item.h"

using namespace std;

class Item {
private:
char description[100];
public:
Item(char* newDescription);
~Item();
char* getDescription();

};

#endif