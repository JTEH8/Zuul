#include <iostream>
#include <cstring>
#include <vector>
#include "Item.h"
#include "Room.h"

using namespace std;

void help();
void get (Room* &currentRoom,vector<Item> &inventory);
void drop (Room* &currentRoom,vector<Item> &inventory);
void move(Room* &currentRoom);
bool checkComplete(vector<Item> &inventory);
void printInventory(vector<Item> &inventory);
int main(){
    vector<Room*> Rooms;
    vector<Room*>::iterator ptr;
    vector<Item> inventory;
    bool x = true;
    char YesNo[10];
    char input[100];
    cout << "Welcome to Zuul, an adventure game with more than a dozen rooms!" << endl;
    cout << endl;
    cout << "You're at the Robert D. Clark debate tournament held by the University of Oregon." << endl;
    cout << endl;
    cout << "Could you help me pick up some of the items I've left behind at the rounds I've had today? (Answer 'yes' or 'no')'" << endl;
    cin >> YesNo;
    if(strcmp(YesNo, "no") == 0){
        cout << "I guess I'll just do it myself. *sigh* " << endl;
        exit(0);
    }
    if(strcmp(YesNo, "yes") == 0){
                char* North = (char*)("North");
                char* East = (char*)("East");
                char* South = (char*)("South");
                char* West = (char*)("West");
                map<char*, Room*> initialMap;
                //Library
                Room* Library = new Room("In the University of Oregon's Knight Library.");
                Item* Pen = new Item("Pen");
                Library->setItem(*Pen);
                //Law School
                Room* LawSchool = new Room("In the University of Oregon's School of Law.");
                //Admissions Office
                Room* AdmissionsOffice = new Room("In the University of Oregon's Office of Admissions.");
                //Stadium
                Room* Stadium = new Room("In the University of Oregon's Autzen Stadium.");
                Item* Stopwatch = new Item("Stopwatch");
                Stadium->setItem(*Stopwatch);
                //Computer Lab
                Room* ComputerLab = new Room("In the University of Oregon's Lawrence 100 Computer Lab.");
                Item* Laptop = new Item("Laptop");
                ComputerLab->setItem(*Laptop);
                //Medical School
                Room* MedicalSchool = new Room("In the University of Oregon's School of Medicine.");
                //Chemistry Lab
                Room* ChemistryLab = new Room("In one of the University of Oregon's many chemistry labs");
                //Courtyard
                Room* Courtyard = new Room("In the University of Oregon's Cascade Courtyard.");
                Item* Jacket = new Item("Jacket");
                Courtyard->setItem(*Jacket);
                //Theatre
                Room* Theatre = new Room("In the University of Oregon's Miller Theatre Complex.");
                //Student Center
                Room* StudentCenter = new Room("In the University of Oregon's Erb Memorial Union.");
                Item* Notebook = new Item("Notebook");
                StudentCenter->setItem(*Notebook);
                //Lecture Hall
                Room* LectureHall = new Room("In the University of Oregon's Columbia Lecture Hall.");
                //Business School
                Room* BusinessSchool = new Room("In the University of Oregon's Lundquist College of Busines.");
                //Dining Hall
                Room* DiningHall = new Room("In the University of Oregon's Barnhart Lecture Hall.");
                //Dormitories
                Room* Dormitories = new Room("In the University of Oregon's Earl Dormitory Hall.");
                Item* Schedule = new Item("Schedule");
                Dormitories->setItem(*Schedule);
                //Health Services and Counseling
                Room* HealthServices = new Room("In the University of Oregon's Health Services Building");
                Item* Backpack = new Item("Backpack");
                HealthServices->setItem(*Backpack);
                //Setting Exits
                Library-> setExit(South, LawSchool);
                LawSchool-> setExit(North, Library);
                LawSchool-> setExit(East, ComputerLab);
                LawSchool-> setExit(South, AdmissionsOffice);
                AdmissionsOffice-> setExit(North, LawSchool);
                AdmissionsOffice-> setExit(South, Stadium);
                Stadium-> setExit(North, AdmissionsOffice);
                Stadium-> setExit(East, Courtyard);
                ComputerLab-> setExit(West, LawSchool);
                ComputerLab-> setExit(East, ChemistryLab);
                MedicalSchool-> setExit(South, ChemistryLab);
                MedicalSchool-> setExit(East, StudentCenter);
                ChemistryLab-> setExit(North, MedicalSchool);
                ChemistryLab-> setExit(East, LectureHall);
                ChemistryLab-> setExit(South, Courtyard);
                ChemistryLab-> setExit(West, ComputerLab);
                Courtyard-> setExit(North, ChemistryLab);
                Courtyard-> setExit(East, BusinessSchool);
                Courtyard-> setExit(South, Theatre);
                Courtyard-> setExit(West, Stadium);
                Theatre-> setExit(North, Courtyard);
                Theatre-> setExit(East, DiningHall);
                StudentCenter-> setExit(South, LectureHall);
                StudentCenter-> setExit(West, MedicalSchool);
                LectureHall-> setExit(North, StudentCenter);
                LectureHall-> setExit(East, Dormitories);
                LectureHall-> setExit(South, BusinessSchool);
                LectureHall-> setExit(West, ChemistryLab);
                BusinessSchool-> setExit(North, LectureHall);
                BusinessSchool-> setExit(South, DiningHall);
                BusinessSchool-> setExit(West, Courtyard);
                DiningHall-> setExit(North, BusinessSchool);
                DiningHall-> setExit(East, HealthServices);
                DiningHall-> setExit(West, Theatre);
                Dormitories-> setExit(North, StudentCenter);
                Dormitories-> setExit(West, LectureHall);
                HealthServices-> setExit(West, DiningHall);
                ComputerLab->setExit(West, LawSchool);
                Rooms.push_back(Library);
                Rooms.push_back(LawSchool);
                Rooms.push_back(AdmissionsOffice);
                Rooms.push_back(Stadium);
                Rooms.push_back(ComputerLab);
                Rooms.push_back(LawSchool);
                Rooms.push_back(LawSchool);
                Room* currentRoom = Library;
    cout << "Thanks for helping me!" << endl;
    cout << endl;
    cout << "I need you to get my pen, notebook, backpack, jacket, stopwatch, laptop, and schedule." << endl;
    cout << "Once you do that, please return them to me at the dorimtory hall." << endl;
    cout << currentRoom->getRoomDescription() << endl;
    currentRoom->ExitsAndItems();
    cout << "It's getting late, we better get started. Your commands are HELP, MOVE, GET, DROP, and INVENTORY. " << endl;
    cout << "Enter a command: " << endl; 
    while(x == true){
        cin >> input;
        if(strcmp(input, "HELP") == 0){
        help();
        } 
        else if(strcmp(input, "MOVE") == 0){
        move(currentRoom);
        }
        else if(strcmp(input, "GET") == 0){
        get(currentRoom, inventory);
        }

    }
}
}
void help(){
    cout << "You're playing Zuul, an adventure game with more than a dozen rooms!" << endl;
    cout << endl;
    cout << "You're at the Robert D. Clark debate tournament held by the University of Oregon." << endl;
    cout << "I need you to get my pen, notebook, backpack, jacket, stopwatch, laptop, and schedule. Once you do that, please return them to me at the dorimtory hall." << endl;
    cout << "Your commands are HELP, MOVE, GET, DROP, and INVENTORY." << endl;
}

void move(Room* &currentRoom){
    char temp[100];
    cout << currentRoom->getRoomDescription() << endl;
    currentRoom->ExitsAndItems();
    cout << "What direction do you want to move in (North, South, East, or West)?" << endl;
    cin >> temp;
    Room* nextRoom = currentRoom->getExit(temp);
    cout << currentRoom->getRoomDescription() << endl;
    //prints out exits
    currentRoom->ExitsAndItems();
}
void get(Room* &currentRoom,vector<Item> &inventory){
char temp2[100];

cout << "Here are the items in the room: " << endl;
currentRoom->printItems();
cout << "Which item do you want to pick up?" << endl;
cin >> temp2;
Item RoomItem = currentRoom->getItem(temp2);
inventory.push_back(RoomItem);
currentRoom->removeItem(temp2);
cout << "You have picked up: " << temp2 << endl;
if(checkComplete(inventory) == true){
    cout << "Thanks for grabbing all my stuff! I'll have to pay you back sometime." << endl;
    exit(0);
    }
}
void drop(Room* &currentRoom,vector<Item> &inventory){
char temp3[100];
cout << "Here are the items in your inventory: " << endl;
printInventory(inventory);
cout << "Which item do you want to drop?" << endl;
cin >> temp3;
Item RoomItem = currentRoom->getItem(temp3);
inventory.push_back(RoomItem);
currentRoom->removeItem(temp3);
cout << "You have picked up: " << temp3 << endl;
if(checkComplete(inventory) == true){
    cout << "Thanks for grabbing all my stuff! I'll have to pay you back sometime." << endl;
    exit(0);
    }
}

void printInventory(vector<Item> &inventory){
    vector<Item>::iterator ptr;
    for(ptr = inventory.begin(); ptr != inventory.end(); ptr++){
    cout << ptr->getDescription() << "," << endl;
    break;
    }
}

bool checkComplete(Room* &currentRoom, vector<Item> &inventory){
  if(inventory.size() == 5 && strcmp(currentRoom->getRoomDescription(),"In the University of Oregon's Earl Dormitory Hall.") == 0){
    return true;
  }
  return false;
}
