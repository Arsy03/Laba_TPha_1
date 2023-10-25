#include "Creature.h"

using namespace std;

class Villain : public Creature {
private:
    string Name;
    string Weapon;
    string Charge;
    string Place;
    string Skills;
public:
    Villain();
    Villain(string Name);
    Villain(const Villain& Villain_copy);
    ~Villain();

    string Get_Name() const;
    void Set_Name(string Name_ch);

    string Get_Weapon() const;
    void Set_Weapon(string Weapon_ch);

    string Get_Charge() const;
    void Set_Charge(string Charge_ch);

    string Get_Place() const;
    void Set_Place(string Place_ch);

    string Get_Skills() const;
    void Set_Skills(string Skills_ch);

    virtual void Show();                               // Вывод данных
    virtual void Rewrite();                            // Изменение данных
    virtual void Save_me();                            // Сохранение данных
    virtual void Edit(int num_str, string red_str);    // Изменение полей

};