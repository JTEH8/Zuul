/*
Author: Jeffrey Teh
This is Zuukm an adventure game through the console with more than a dozen different rooms. It is set at the University of Oregon.
I was helped with this project by Kyle Zhou (On the Room and item files, as well as methods like adding items) and by Nathan Zou (With initialzing Rooms and Exits)
Date Completed : 12/31/2021
*/
#include <iostream>
#include <cstring>
#include <vector>
#include "Item.h"
#include "Room.h"

using namespace std;

//Function Prototypes
void help();
void get (Room* &currentRoom,vector<Item> &inventory);
void drop (Room* &currentRoom,vector<Item> &inventory);
void move(Room* &currentRoom);
bool checkComplete(Room* &currentRoom, vector<Item> &inventory);
void printInventory(vector<Item> &inventory);
//Main Method
int main(){
    //Initializing variables
    vector<Room*> Rooms;
    vector<Room*>::iterator ptr;
    vector<Item> inventory;
    bool x = true;
    char YesNo[10];
    char input[100];
    //Introduction and prompt text
    cout << "Welcome to Zuul, an adventure game with more than a dozen rooms!" << endl;
    cout << endl;
    cout << "You're at the Robert D. Clark debate tournament held by the University of Oregon." << endl;
    cout << endl;
    cout << "Could you help me pick up some of the items I've left behind at the rounds I've had today? (Answer 'yes' or 'no')'" << endl;
    //Confirmation of whether you want to play or not
    cin >> YesNo;
    if(strcmp(YesNo, "no") == 0){
        cout << "I guess I'll just do it myself. *sigh* " << endl;
        exit(0);
    }
    if(strcmp(YesNo, "yes") == 0){
                //Initializing Rooms and Exits
                char* North = (char*)("North");
                char* East = (char*)("East");
                char* South = (char*)("South");
                char* West = (char*)("West");
                map<char*, Room*> initialMap;
                //Library
                char LibraryDescription[100] = "In the University of Oregon's Knight Library.";
                Room* Library = new Room(LibraryDescription);
                char PenDescription[100] = "Pen";
                Item* Pen = new Item(PenDescription);
                Library->setItem(*Pen);
                //Law School
                char LawDescription[100] = "In the University of Oregon's School of Law.";
                Room* LawSchool = new Room(LawDescription);
                //Admissions Office
                char AdmissionsDescription[100] = "In the University of Oregon's Office of Admissions.";
                Room* AdmissionsOffice = new Room(AdmissionsDescription);
                //Stadium
                char StadiumDescription[100] = "In the University of Oregon's Autzen Stadium.";
                Room* Stadium = new Room(StadiumDescription);
                char StopwatchDescription[100] = "Stopwatch";
                Item* Stopwatch = new Item(StopwatchDescription);
                Stadium->setItem(*Stopwatch);
                //Computer Lab
                char ComputerDescription[100] = "In the University of Oregon's Lawrence 100 Computer Lab.";
                Room* ComputerLab = new Room(ComputerDescription);
                char LaptopDescription[100] = "Laptop";
                Item* Laptop = new Item(LaptopDescription);
                ComputerLab->setItem(*Laptop);
                //Medical School
                char MedicalDescription[100] = "In the University of Oregon's School of Medicine.";
                Room* MedicalSchool = new Room(MedicalDescription);
                //Chemistry Lab
                char ChemistryDescription[100] = "In one of the University of Oregon's many chemistry labs.";
                Room* ChemistryLab = new Room(ChemistryDescription);
                //Courtyard
                char CourtyardDescription[100] = "In the University of Oregon's Cascade Courtyard.";
                Room* Courtyard = new Room(CourtyardDescription);
                char JacketDescription[100] = "Jacket";
                Item* Jacket = new Item(JacketDescription);
                Courtyard->setItem(*Jacket);
                //Theatre
                char TheatreDescription[100] = "In the University of Oregon's Miller Theatre Complex.";
                Room* Theatre = new Room(TheatreDescription);
                //Student Center
                char StudentDescription[100] = "In the University of Oregon's Erb Memorial Union.";
                Room* StudentCenter = new Room(StudentDescription);
                char NotebookDescription[100] = "Notebook";
                Item* Notebook = new Item(NotebookDescription);
                StudentCenter->setItem(*Notebook);
                //Lecture Hall
                char LectureDescription[100] = "In the University of Oregon's Columbia Lecture Hall.";
                Room* LectureHall = new Room(LectureDescription);
                //Business School
                char BusinessDescription[100] = "In the University of Oregon's Lundquist College of Busines.";
                Room* BusinessSchool = new Room(BusinessDescription);
                //Dining Hall
                char DiningDescription[100] = "In the University of Oregon's Dining Hall.";
                Room* DiningHall = new Room(DiningDescription);
                //Dormitories
                char DormitoriesDescription[100] = "In the University of Oregon's Earl Dormitory Hall.";
                Room* Dormitories = new Room(DormitoriesDescription);
                char ScheduleDescription[100] = "Schedule";
                Item* Schedule = new Item(ScheduleDescription);
                Dormitories->setItem(*Schedule);
                //Health Services and Counseling
                char HealthDescription[100] = "In the University of Oregon's Health Services Building.";
                Room* HealthServices = new Room(HealthDescription);
                char BackpackDescription[100] = "Backpack";
                Item* Backpack = new Item(BackpackDescription);
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
                StudentCenter-> setExit(East, Dormitories);
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
                //Setting the unique ID for the winning Room
                Dormitories->setWinID(8);
                //Setting starting Room to the library
                Room* currentRoom = Library;
    //If you say yes to playing
    cout << "Thanks for helping me!" << endl;
    cout << endl;
    cout << "I need you to get my pen, notebook, backpack, jacket, stopwatch, laptop, and schedule." << endl;
    cout << "Once you do that, please return them to me at the dorimtory hall." << endl;
    cout << "A map can be for this game here: https://docs.google.com/drawings/d/1O2y8JzIz8xqYjhi6Mb4EyUQcHDukn2QR-z_zamZtiqE/edit?usp=sharing" << endl;
    //Printing initial information, like the room description and your commands.
    cout << currentRoom->getRoomDescription() << endl;
    currentRoom->ExitsAndItems();
    cout << "It's getting late, we better get started. Your commands are HELP, MOVE, GET, DROP, QUIT, and INVENTORY. " << endl;
    cout << "Enter a command: " << endl; 
    //While playing
    while(x == true){
        //Read in input for a command
        cin >> input;
        //If the user enters "HELP"
        if(strcmp(input, "HELP") == 0){
        help();
        } 
         //If the user enters "MOVE"       
        else if(strcmp(input, "MOVE") == 0){
        move(currentRoom);
        if(checkComplete(currentRoom,inventory) == true){
        cout << "Thanks for grabbing all my stuff! I'll have to pay you back sometime." << endl;
        exit(0);
        }
        }
        //If the user enters "GET"
        else if(strcmp(input, "GET") == 0){
        get(currentRoom, inventory);
        }
        //If the user enters "DROP"
        else if(strcmp(input, "DROP") == 0){
        drop(currentRoom, inventory);
        }
        //If the user enters "QUIT" 
        else if(strcmp(input, "QUIT") == 0){
        cout << "Thanks for playing! See you next time!" << endl;
        //Ends loop and exits
        x=false;
        exit(0);
        }
        //If the user enters "INVENTORY"
        else if(strcmp(input, "INVENTORY") == 0){
        printInventory(inventory);
        }
    }
}
}
//Prints Help
void help(){
    cout << "You're playing Zuul, an adventure game with more than a dozen rooms!" << endl;
    cout << endl;
    cout << "You're at the Robert D. Clark debate tournament held by the University of Oregon." << endl;
    cout << "I need you to get my pen, notebook, backpack, jacket, stopwatch, laptop, and schedule. Once you do that, please return them to me at the dorimtory hall." << endl;
    cout << "A map can be for this game here: https://docs.google.com/drawings/d/1O2y8JzIz8xqYjhi6Mb4EyUQcHDukn2QR-z_zamZtiqE/edit?usp=sharing" << endl;
    cout << "Your commands are HELP, MOVE, GET, DROP, and INVENTORY." << endl;
}
//When you move   
void move(Room* &currentRoom){
char temp[100];
//Print the room you're in
cout << currentRoom->getRoomDescription() << endl;
//Show the exits and items
currentRoom->ExitsAndItems();
cout << "What direction do you want to move in (North, South, East, or West)?" << endl;
//Enter the direction you want to move in
cin >> temp;
  //sets next room to the end of the entered exit
  Room* nextRoom = currentRoom->getExit(temp);
  //sets currentRoom to the nextRoom
  currentRoom = nextRoom;
  //Prints out the description of the new (now current) room
  cout << currentRoom->getRoomDescription() << endl;
  //Prints out the exits and items in the room
  currentRoom->ExitsAndItems();
}
//When you get/pick up an item
void get(Room* &currentRoom,vector<Item> &inventory){
char temp2[100];
cout << "Here are the items in the room: " << endl;
//Prints the items in the room
currentRoom->printItems();
cout << "Which item do you want to pick up?" << endl;
//Enter the name of the item you want to pick up
cin >> temp2;
//Gets the item from the room
Item RoomItem = currentRoom->getItem(temp2);
//Adds it to the inventory
inventory.push_back(RoomItem);
//Removes it from the room
currentRoom->removeItem(temp2);
cout << "You have picked up: " << temp2 << endl;
//If you picked up all the items and are in the dormitories
if(checkComplete(currentRoom,inventory) == true){
    cout << "Thanks for grabbing all my stuff! I'll have to pay you back sometime." << endl;
    exit(0);
    }
}
//When you drop an item
void drop(Room* &currentRoom,vector<Item> &inventory){
vector<Item>::iterator ptr4;
char temp3[100];
cout << "Here are the items in your inventory: " << endl;
//Prints your current inventory
printInventory(inventory);
cout << "Which item do you want to drop?" << endl;
//Enter the name of the item you want to drop
cin >> temp3;
//Finds the item in your inventory
for(ptr4 = inventory.begin(); ptr4 != inventory.end(); ptr4++){
   if(strcmp(ptr4->getDescription(),temp3) == 0){
       char tempItemDescription[100] = " "; 
       //Creates a temporary item to delete
       Item tempItem(tempItemDescription);
       tempItem = (*ptr4);
      //Erases the temporary item from inventory
      inventory.erase(ptr4);
      //Adds a new item to the room
      currentRoom->setItem(tempItem);
      cout << "Dropped: " << temp3 << endl;
      break;
   }
    }
}
//Prints inventory
void printInventory(vector<Item> &inventory){
    vector<Item>::iterator ptr;
    //Goes through your inventory
    for(ptr = inventory.begin(); ptr != inventory.end(); ptr++){
    //Prints all the item names
    cout << ptr->getDescription() << ",";;
    }
    cout << endl;
}
//Checks to see if you've collected all the items and you're in the dormitory (WinID is 8, not 0)
bool checkComplete(Room* &currentRoom, vector<Item> &inventory){
  if(inventory.size() == 7 && currentRoom->getWinID() != 0){
    return true;
  }
  return false;
}
