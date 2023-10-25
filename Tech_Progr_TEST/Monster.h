#include "Creature.h"

using namespace std;

class Monster : public Creature {
private:
    string Name;
    string Signs;
public:
    Monster();
    Monster(string Name);
    Monster(const Monster& Monster_copy);
    ~Monster();

    string Get_Name() const;
    void Set_Name(string Name_ch);

    string Get_Signs() const;
    void Set_Signs(string Signs_ch);

    virtual void Show();                               // Вывод данных
    virtual void Rewrite();                            // Изменение данных
    virtual void Save_me();                            // Сохранение данных
    virtual void Edit(int num_str, string red_str);    // Изменение полей
};