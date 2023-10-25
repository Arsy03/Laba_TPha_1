#include <string>
#include <fstream>
#include "Villain.h"

using namespace std;

Villain::Villain() {
    cout << "Constructor without parameters was called" << endl;
}

Villain::Villain(string Name) {
    this->Name = Name;
    cout << "Constructor with parameters was called" << endl;
}

Villain::Villain(const Villain& Villain_copy) {
    Name = Villain_copy.Name;
    Weapon = Villain_copy.Weapon;
    Charge = Villain_copy.Charge;
    Place = Villain_copy.Place;
    Skills = Villain_copy.Skills;
    cout << "Constructor of copy was called" << endl;
}

Villain::~Villain() {
    cout << "Destructor was called" << endl;
}

string Villain::Get_Name() const {return Name;}
void Villain::Set_Name(string Name_ch) {Name = Name_ch;}

string Villain::Get_Weapon() const {return Weapon;}
void Villain::Set_Weapon(string Weapon_ch) {Weapon = Weapon_ch;}

string Villain::Get_Charge() const {return Charge;}
void Villain::Set_Charge(string Charge_ch) {Charge = Charge_ch;}

string Villain::Get_Place() const {return Place;}
void Villain::Set_Place(string Place_ch) {Place = Place_ch;}

string Villain::Get_Skills() const {return Skills;}
void Villain::Set_Skills(string Skills_ch) {Skills = Skills_ch;}

void Villain::Show() {
    cout << "<<<<<<<<<<>>>>>>>>>>" << endl;
    cout << "Creature > Villain" << endl;
    cout << "Name > " << Name << endl;
    cout << "Weapon > " << Weapon << endl;
    cout << "Charge > " << Charge << endl;
    cout << "Place > " << Place << endl;
    cout << "Skills > " << Skills << endl;
    cout << "<<<<<<<<<<>>>>>>>>>>" << endl;
}

void Villain::Rewrite() {
    cout << "<<<<<<<<<<>>>>>>>>>>" << endl;
    cout << "Villain > " << endl;
    cout << "Enter new name > ";
    getline(cin, Name);
    getline(cin, Name);
    cout << "Enter new weapon > ";
    getline(cin, Weapon);
    cout << "Enter new charge > ";
    getline(cin, Charge);
    cout << "Enter new place > ";
    getline(cin, Place);
    cout << "Enter new skills > ";
    getline(cin, Skills);
    cout << "<<<<<<<<<<>>>>>>>>>>" << endl;
}

void Villain::Save_me() {
    ofstream outfile;
    string initfile = "E:\\Workspace\\Clion_Projects\\Tech_Progr_TEST\\Book.txt";
    outfile.open(initfile, ios_base::app);
    if (!outfile.is_open()) {
        cout << "Error with opening the file" << endl;
        exit(1);
    }
    else {
        outfile << 2 << endl << Name << endl << Weapon << endl << Charge << endl << Place << endl << Skills << endl;
        outfile.close();
    }
}

void Villain::Edit(int num_str, string red_str) {
    switch (num_str) {
        case 1:
            this->Name = red_str;
            break;
        case 2:
            this->Weapon = red_str;
            break;
        case 3:
            this->Charge = red_str;
            break;
        case 4:
            this->Place = red_str;
            break;
        case 5:
            this->Skills = red_str;
            break;
        default:
            cout << "Error with number of string" << endl;
            break;
    }
}