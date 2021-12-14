#ifndef ITEM_H
#define ITEM_H
#include <cstring>

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