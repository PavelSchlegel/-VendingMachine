#include <iostream>
#include <string>
#include "assert.h"
#include "slot.h"
#include "vedingmachine.h"

VendingMachine::VendingMachine() :
m_slot(nullptr),
m_size(0),  //сколько слотов в машине будет
m_full(0)   //сколько слотов есть физически
{

}

VendingMachine::VendingMachine(int lenght)
{
    assert(lenght != 0);

    m_slot = new SnackSlot*[lenght];  //с мусором
    for(int i = 0; i < lenght; ++i)
    {
        m_slot[i] = nullptr;
    }                           // с nullptr

    m_size = lenght;
}

VendingMachine::~VendingMachine()
{
    for(int i = 0; i < m_size; ++i)
    {
        delete m_slot[i];         
    }

    delete[] m_slot;    
}

void VendingMachine::addSlot(SnackSlot *newslot)
{
    if(m_slot)
    {
        if(m_full != m_size)
        {
            m_slot[m_full] = new SnackSlot(*newslot); 
            ++m_full;
        }
        else
        {
            std::cout << "Machine is full!" << std::endl;
        }
    }
}

int VendingMachine::getSize() const
{
    return m_size;
}

int VendingMachine::getFullSlot() const
{
    return m_full;
}

int VendingMachine::getEmptySlotsCount() const //для всех слотов
{
    int freeSlots = 0;
    for(int i = 0; i < m_full; ++i)
    {
        freeSlots += m_slot[i]->freeSlot();
    }
    
    return freeSlots;
}

int VendingMachine::getSlotCalorie() const 
{
    int getCalorie = 0;

    for(int i = 0; i < m_full; ++i)
    {

        getCalorie += m_slot[i]->getSlotCalorie();

    }

    return getCalorie;
}