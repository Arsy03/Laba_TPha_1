#include <string>
#include "Menu.h"
#include "Hero.h"
#include "Villain.h"
#include "Monster.h"

using namespace std;

void Menu::Main_options() {
    while (exit == 1) {
        switch (Switcher()) {
            case 1:
                Show_All();
                break;
            case 2:
                Edit_smth();
                break;
            case 3:
                Add_smth();
                break;
            case 4:
                Save_to_File();
                break;
            case 5:
                Load_from_File();
                break;
            case 6:
                Erase();
                break;
            default:
                Eject();
                break;
        }
    }
}

int Menu::Switcher() {
    int Simv_1;
    cout << "\nDo you want to use the power of the universe?" << endl;
    cout << "1 - Show all creatures" << endl;
    cout << "2 - Edit something" << endl;
    cout << "3 - Add something" << endl;
    cout << "4 - Save to file" << endl;
    cout << "5 - Load from file" << endl;
    cout << "6 - Erase" << endl;
    cout << "0 - Exit" << endl;
    cout << "> " << endl;
    cin >> Simv_1;
    return Simv_1;
}

void Menu::Show_All() {
    try {
        if (list.Get_Size() == 0) {
            throw "This dimension is empty...";
        }
        for (int i = 0; i < list.Get_Size(); i++) {
            cout << "_" << endl;
            cout << i + 1 << "|";
            list[i]->Show();
        }
    }
    catch (const char* ex) {cout << ex << endl;}
}

void Menu::Edit_smth() {
    int Simv_2, Simv_3;
    try {
        cout << "Whose fate will we change?" << endl;
        cin >> Simv_2;

        if ((Simv_2 < 1) || (Simv_2 > list.Get_Size())) {
            throw "Something went wrong...";
        }

        list[Simv_2 - 1]->Show();
        cout << "What we will change?" << endl;
        cout << "> ";
        cin >> Simv_3;
        cin.ignore(1000, '\n');
        cout << "What we will change exactly?" << endl;
        cout << "> ";
        if (Simv_3 == 5) {
            bool fl = false;
            while (fl == false) {
                try {
                    getline(cin, redact);
                    fl = true;
                }
                catch (...) {
                    cout << "Enter the number" << endl;
                }
            }
            list[Simv_2 - 1]->Edit(Simv_3, redact);
        }
        else {
            getline(cin, redact);
            list[Simv_2 - 1]->Edit(Simv_3, redact);
            cout << "Destiny changed" << endl;
        }
    }
    catch (const char* ex) {cout << ex << endl;}
}

void Menu::Add_smth() {
    int Simv_2;
    cout << "Who should be added to this dimension?" << endl;
    cout << "1 - Hero" << endl;
    cout << "2 - Villain" << endl;
    cout << "3 - Monster" << endl;
    cout << "0 - I haven't decided yet" << endl;
    cout << "> " << endl;
    cin >> Simv_2;

    switch (Simv_2) {
        case 1:
            Hero * hero;
            hero = new Hero;
            creatures = hero;
            hero->Rewrite();
            list.Enter(creatures);
            cout << "The hero is summoned to this dimension!" << endl;
            break;
        case 2:
            Villain * villain;
            villain = new Villain;
            creatures = villain;
            villain->Rewrite();
            list.Enter(creatures);
            cout << "The villain is beginning to invade this dimension..." << endl;
            break;
        case 3:
            Monster * monster;
            monster = new Monster;
            creatures = monster;
            monster->Rewrite();
            list.Enter(creatures);
            cout << "A new type of monster has been spotted in this dimension..." << endl;
            break;
        default:
            break;
    }
}

void Menu::Save_to_File() {
    try {
        if (list.Get_Size() == 0) {
            throw "This dimension is empty to be saved";
        }
        list.Save();
        cout << "This dimension was saved to the file" << endl;
    }
    catch (const char* ex) {cout << ex << endl;}
}

void Menu::Load_from_File() {
    try {
        list.Load();
        cout << "Dimension was restored from file" << endl;
    }
    catch (const char* ex) {cout << ex << endl;}
}

void Menu::Erase() {
    int Simv_2;
    cout << "Whose fate will we erase?" << endl;
    for (int i = 0; i < list.Get_Size(); i++) {
        cout << "_" << endl;
        cout << i + 1 << "|";
        list[i]->Show();
    }
    cout << "> ";
    cin >> Simv_2;
    Simv_2 = list.Get_Size() - Simv_2 + 1;
    try {
        if ((Simv_2 < 1) || (Simv_2 > list.Get_Size())) {
            throw "Something went wrong...";
        }
        list.Delete(Simv_2 - 1);
        cout << "This poor soul has been erased from this dimension..." << endl;
    }
    catch (const char* i) {cout << i << endl;}
}

void Menu::Eject() {
    exit = 0;
}