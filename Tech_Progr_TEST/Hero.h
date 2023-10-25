#include "Creature.h"

using namespace std;

class Hero : public Creature {
private:
    string Name;
    string Weapon;
    string Skills;
public:
    Hero();
    Hero(string Name);
    Hero(const Hero& Hero_copy);
    ~Hero();

    string Get_Name() const;
    void Set_Name(string Name_ch);

    string Get_Weapon() const;
    void Set_Weapon(string Weapon_ch);

    string Get_Skills() const;
    void Set_Skills(string Skills_ch);

    virtual void Show();                            // Вывод данных
    virtual void Rewrite();                         // Изменение данных
    virtual void Save_me();                            // Сохранение данных
    virtual void Edit(int num_str, string red_str); // Изменение полей
};