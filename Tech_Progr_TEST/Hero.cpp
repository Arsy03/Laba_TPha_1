#include <string>
#include <fstream>
#include "Hero.h"

using namespace std;

Hero::Hero() {
    cout << "Constructor without parameters was called" << endl;
}

Hero::Hero(string Name) {
    this->Name = Name;
    cout << "Constructor with parameters was called" << endl;
}

Hero::Hero(const Hero& Hero_copy) {
    Name = Hero_copy.Name;
    Weapon = Hero_copy.Weapon;
    Skills = Hero_copy.Skills;
    cout << "Constructor of copy was called" << endl;
}

Hero::~Hero() {
    cout << "Destructor was called" << endl;
}

string Hero::Get_Name() const {return Name;}
void Hero::Set_Name(string Name_ch) {Name = Name_ch;}

string Hero::Get_Weapon() const {return Weapon;}
void Hero::Set_Weapon(string Weapon_ch) {Weapon = Weapon_ch;}

string Hero::Get_Skills() const {return Skills;}
void Hero::Set_Skills(string Skills_ch) {Skills = Skills_ch;}

void Hero::Show() {
    cout << "<<<<<<<<<<>>>>>>>>>>" << endl;
    cout << "Creature > Hero" << endl;
    cout << "Name > " << Name << endl;
    cout << "Weapon > " << Weapon << endl;
    cout << "Skills > " << Skills << endl;
    cout << "<<<<<<<<<<>>>>>>>>>>" << endl;
}

void Hero::Rewrite() {
    cout << "<<<<<<<<<<>>>>>>>>>>" << endl;
    cout << "Hero > " << endl;
    cout << "Enter new name > ";
    getline(cin, Name);
    getline(cin, Name);
    cout << "Enter new weapon > ";
    getline(cin, Weapon);
    cout << "Enter new skills > ";
    getline(cin, Skills);
    cout << "<<<<<<<<<<>>>>>>>>>>" << endl;
}

void Hero::Save_me() {
    ofstream outfile;
    string initfile = "E:\\Workspace\\Clion_Projects\\Tech_Progr_TEST\\Book.txt";
    outfile.open(initfile, ios_base::app);
    if (!outfile.is_open()) {
        cout << "Error with opening the file" << endl;
        exit(1);
    }
    else {
        outfile << 1 << endl << Name << endl << Weapon << endl << Skills << endl;
        outfile.close();
    }
}

void Hero::Edit(int num_str, string red_str) {
    switch (num_str) {
        case 1:
            this->Name = red_str;
            break;
        case 2:
            this->Weapon = red_str;
            break;
        case 3:
            this->Skills = red_str;
            break;
        default:
            cout << "Error with number of string" << endl;
            break;
    }
}