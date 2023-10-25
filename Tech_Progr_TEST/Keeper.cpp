#include <string>
#include <fstream>
#include "Keeper.h"
#include "Hero.h"
#include "Villain.h"
#include "Monster.h"

using namespace std;

Keeper::Keeper() : size(0), head(nullptr) {}
Keeper::Keeper(int size) : head(nullptr) {
    this->size = size;
}
Keeper::~Keeper() {
    if (head != NULL) {
        Elem* buffer;
        while (head->next != NULL) {
            buffer = head;
            head = head->next;
            buffer->data->~Creature();
            delete(buffer);
        }
        head->data->~Creature();
        delete(head);
    }
}

Creature* Keeper::operator[] (const int id) {
    if ((id >= size) || id < 0) {
        cout << "Wrong index" << endl;
        exit(1);
    }
    else {
        Elem* buffer = head;
        for (int i = 0; i < size - id - 1; i++) {
            buffer = buffer->next;
        }
        return (buffer->data);
    }
}

int Keeper::Get_Size() {
    return size;
}

void Keeper::Enter(Creature *new_data) {
    Elem* tmp;
    tmp = new Elem;
    if (size == 0) {
        tmp->data = new_data;
        tmp->next = 0;
        ++size;
    }
    else {
        tmp->data = new_data;
        tmp->next = head;
        ++size;
    }
    head = tmp;
}

void Keeper::Delete(int id) {
    if ((head != NULL) && (id < size) && (id >= 0)) {
        Elem* temp = head, * temp2 = head;
        for (int i = 0; i < id; i++) {
            temp2 = temp;
            temp = temp->next;
        }

        if (temp == head) {
            head = temp->next;
        }
        else {
            temp2->next = temp->next;
        }
        temp->data->~Creature();
        delete(temp);
        size--;
    }
}

void Keeper::Save() {
    ofstream outfile;
    string initfile = "E:\\Workspace\\Clion_Projects\\Tech_Progr_TEST\\Book.txt";
    outfile.open(initfile);
    if (!outfile.is_open()) {
        cout << "Error with opening the file" << endl;
        exit(1);
    }
    else {
        outfile << size << endl;
        //outfile.close();
    }

    Elem* buffer = head;
    for (int i = 0; i < size; i++) {
        buffer->data->Save_me();
        buffer = buffer->next;
    }
}

void Keeper::Load() {
    if (size != 0) {
        Elem* buffer;
        while (head->next != NULL) {
            buffer = head;
            head = head->next;
            buffer->data->~Creature();
            delete(buffer);
        }
    }

    ifstream infile;
    int read_size, order;
    string One, Two, Three, Four, Five;
    string initfile = "E:\\Workspace\\Clion_Projects\\Tech_Progr_TEST\\Book.txt";
    Creature* creatures;

    infile.open(initfile, ios_base::in);
    if (!infile.is_open()) {
        cout << "Error with opening the file" << endl;
        exit(1);
    }

    infile >> read_size;

    for (int i = 0; i < read_size; i++) {
        infile >> order;
        infile.ignore(1000, '\n');

        if (order == 1) {
            getline(infile, One);
            getline(infile, Two);
            getline(infile, Three);

            Hero* hero;
            hero = new Hero;
            hero->Set_Name(One);
            hero->Set_Weapon(Two);
            hero->Set_Skills(Three);
            creatures = hero;
            Enter(creatures);
        }
        if (order == 2) {
            getline(infile, One);
            getline(infile, Two);
            getline(infile, Three);
            getline(infile, Four);
            getline(infile, Five);

            Villain* villain;
            villain = new Villain;
            villain->Set_Name(One);
            villain->Set_Weapon(Two);
            villain->Set_Charge(Three);
            villain->Set_Place(Four);
            villain->Set_Skills(Five);
            creatures = villain;
            Enter(creatures);
        }
        if (order == 3) {
            getline(infile, One);
            getline(infile, Two);

            Monster* monster;
            monster = new Monster;
            monster->Set_Name(One);
            monster->Set_Signs(Two);
            creatures = monster;
            Enter(creatures);
        }
    }
}