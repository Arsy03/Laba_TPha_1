#pragma once
#include <iostream>

using namespace std;

class Creature { // Определение базового абстрактного класса
public:
    Creature() {};
    virtual ~Creature() {};

    virtual void Show() = 0;                                   // Вывод данных
    virtual void Rewrite() = 0;                                // Изменение данных
    virtual void Save_me() = 0;                                // Сохранение данных
    virtual void Edit(int num_str, string red_str) = 0;        // Изменение полей
};

typedef struct Elem {
    Creature *data;
    Elem* next;
} Elem;