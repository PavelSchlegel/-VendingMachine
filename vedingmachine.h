#include <iostream>
#include <string>
#pragma once
#include "slot.h"


class VendingMachine
{
private:

    SnackSlot **m_slot;
    int m_size;
    int m_full;

public:

    VendingMachine();
    VendingMachine(int lenght);
    ~VendingMachine();
    int getSlotCalorie() const;
    int getSize() const;
    int getFullSlot() const;
    void addSlot(SnackSlot *newslot);
    int getEmptySlotsCount() const; //для всех слотов

};