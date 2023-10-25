#include <string>
#include <fstream>
#include "Monster.h"

using namespace std;

Monster::Monster() {
    cout << "Constructor without parameters was called" << endl;
}

Monster::Monster(string Name) {
    this->Name = Name;
    cout << "Constructor with parameters was called" << endl;
}

Monster::Monster(const Monster& Monster_copy) {
    Name = Monster_copy.Name;
    Signs = Monster_copy.Signs;
    cout << "Constructor of copy was called" << endl;
}

Monster::~Monster() {
    cout << "Destructor was called" << endl;
}

string Monster::Get_Name() const {return Name;}
void Monster::Set_Name(string Name_ch) {Name = Name_ch;}

string Monster::Get_Signs() const {return Signs;}
void Monster::Set_Signs(string Signs_ch) {Signs = Signs_ch;}

void Monster::Show() {
    cout << "<<<<<<<<<<>>>>>>>>>>" << endl;
    cout << "Creature > Monster" << endl;
    cout << "Name > " << Name << endl;
    cout << "Signs > " << Signs << endl;
    cout << "<<<<<<<<<<>>>>>>>>>>" << endl;
}

void Monster::Rewrite() {
    cout << "<<<<<<<<<<>>>>>>>>>>" << endl;
    cout << "Monster > " << endl;
    cout << "Enter new name > ";
    getline(cin, Name);
    getline(cin, Name);
    cout << "Enter new Signs > ";
    getline(cin, Signs);
    cout << "<<<<<<<<<<>>>>>>>>>>" << endl;
}

void Monster::Save_me() {
    ofstream outfile;
    string initfile = "E:\\Workspace\\Clion_Projects\\Tech_Progr_TEST\\Book.txt";
    outfile.open(initfile, ios_base::app);
    if (!outfile.is_open()) {
        cout << "Error with opening the file" << endl;
        exit(1);
    }
    else {
        outfile << 3 << endl << Name << endl << Signs << endl;
        outfile.close();
    }
}

void Monster::Edit(int num_str, string red_str) {
    switch (num_str) {
        case 1:
            this->Name = red_str;
            break;
        case 2:
            this->Signs = red_str;
            break;
        default:
            cout << "Error with number of string" << endl;
            break;
    }
}