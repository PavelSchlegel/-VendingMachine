#include <iostream>
#include "snack.h"
#pragma once

class SnackSlot
{
private:

    Snack **m_slot;
    int m_size;                     //создано
    int m_occupied;                 //занято

public:

    SnackSlot(const SnackSlot& slot);
    SnackSlot();
    SnackSlot(int lenght);
    ~SnackSlot();
    int freeSlot() const;           // возврат пустых слотов(кол.)
    int getSlotSize() const;        //возврат длины лотка
    int getSlotOccupied() const;    //возврат кол. занятых слотов
    void addSnack(Snack *snack);    //добавление снека указатель
    int getSlotCalorie() const;     //подсчет каллорий в лотке

};