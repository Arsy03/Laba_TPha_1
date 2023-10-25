#include "Creature.h"

using namespace std;

class Keeper {
private:
    int size = 0;
    Elem* head = NULL;
public:
    Keeper();         // Конструктор без параметров
    Keeper(int size); // Конструктор с параметрами
    ~Keeper();        // Деструктор

    Creature* operator[] (int id);

    int Get_Size();
    void Enter(Creature* new_data);
    void Delete(int id);
    void Save();
    void Load();
};