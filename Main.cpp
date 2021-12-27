#include <iostream>
#include <cstring>
#include <vector>
#include "Item.h"
#include "Room.h"

using namespace std;

void help();
void createRooms();

int main(){
    bool x = true;
    char YesNo[10];
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
    createRooms();
    cout << "Thanks for helping me!" << endl;
    cout << endl;
    cout << "I need you to get my pen, notebook, backpack, jacket, stopwatch, laptop, and schedule." << endl;
    cout << "It's getting late, we better get started. Your commands are HELP, MOVE, GET, DROP, and INVENTORY." << endl;
    while(x == true){
    
        }
    }
}

void help(){
    cout << "You're playing Zuul, an adventure game with more than a dozen rooms!" << endl;
    cout << endl;
    cout << "You're at the Robert D. Clark debate tournament held by the University of Oregon." << endl;
    cout << "I need you to get my pen, notebook, backpack, jacket, stopwatch, laptop, and schedule." << endl;
    cout << "Your commands are HELP, MOVE, GET, DROP, and INVENTORY." << endl;
}

void createRooms(vector<Room*> Rooms){
vector<Room*> Rooms;
char* North = (char*)("North");
char* East = (char*)("East");
char* South = (char*)("South");
char* West = (char*)("West");
map<char*, Room*> initialMap;
//Library
Room* Library = new Room("In the University of Oregon's Knight Library.");
Item* Pen = new Item("A gold Pierre Cardin pen that has barely any ink left.");
Library->setItem(*Pen);
//Law School
Room* LawSchool = new Room("In the University of Oregon's School of Law.");
//Admissions Office
Room* AdmissionsOffice = new Room("In the University of Oregon's Office of Admissions.");
//Stadium
Room* Stadium = new Room("In the University of Oregon's Autzen Stadium.");
Item* Stopwatch = new Item("A simple, cream-colored digital stopwatch.");
Stadium->setItem(*Stopwatch);
//Computer Lab
Room* ComputerLab = new Room("In the University of Oregon's Lawrence 100 Computer Lab.");
Item* Laptop = new Item("A matte black Razer Blade Stealth laptop.");
ComputerLab->setItem(*Laptop);
//Medical School
Room* MedicalSchool = new Room("In the University of Oregon's School of Medicine.");
//Chemistry Lab
Room* ChemistryLab = new Room("In one of the University of Oregon's many chemistry labs");
//Courtyard
Room* Courtyard = new Room("In the University of Oregon's Autzen Stadium.");
Item* Jacket = new Item("A puffy blue Columbia jacket.");
Courtyard->setItem(*Jacket);
//Theatre
Room* Theatre = new Room("In the University of Oregon's Miller Theatre Complex.");
//Student Center
Room* StudentCenter = new Room("In the University of Oregon's Erb Memorial Union.");
//Lecture Hall
Room* LectureHall = new Room("In the University of Oregon's Columbia Lecture Hall.");
//Business School
Room* BusinessSchool = new Room("In the University of Oregon's Lundquist College of Busines.");
//Dining Hall
Room* DiningHall = new Room("In the University of Oregon's Barnhart Lecture Hall.");

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





ComputerLab->setExit(West, LawSchool);
Rooms.push_back(Library);
Rooms.push_back(LawSchool);
Rooms.push_back(AdmissionsOffice);
Rooms.push_back(Stadium);
Rooms.push_back(ComputerLab);
Rooms.push_back(LawSchool);
Rooms.push_back(LawSchool);

}