#include "Keeper.h"

using namespace std;

class Menu {
protected:
    Keeper list;
    Creature* creatures;
    string redact;
    int exit = 1;
public:
    void Main_options();
    int Switcher();
    void Show_All();
    void Edit_smth();
    void Add_smth();
    void Save_to_File();
    void Load_from_File();
    void Erase();
    void Eject();
};