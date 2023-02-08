#include <iostream>
#include "snack.h"
#include "slot.h"
#include <assert.h>

SnackSlot::SnackSlot(const SnackSlot& slot)
: m_slot(new Snack*[slot.getSlotSize()])
, m_size(slot.getSlotSize())
, m_occupied(slot.getSlotOccupied())
{
    for(std::size_t i = 0; i < m_occupied; ++i)
    {
        m_slot[i] = new Snack(*slot.m_slot[i]);
    }
}

SnackSlot::SnackSlot() :
m_slot(nullptr),
m_size(0),
m_occupied(0)

{

}

SnackSlot::SnackSlot(int lenght)
{
    assert(lenght != 0);

    m_slot = new Snack*[lenght];  //с мусором
    for(int i = 0; i < lenght; ++i)
    {
        m_slot[i] = nullptr;
    }                           // с nullptr

    m_size = lenght;
}

SnackSlot::~SnackSlot() //delete
{
    for(int i = 0; i < m_size; ++i)
    {
        delete m_slot[i];         // возвращаем указатели на снек
    }

    delete [] m_slot;              // вернём сам слот
}

int SnackSlot::getSlotSize() const
{
    return m_size;
}

int SnackSlot::getSlotOccupied() const
{
    return m_occupied;
}

void SnackSlot::addSnack(Snack *snack)
{
    if(m_slot)
    {
        if(m_occupied != m_size)
        {
            m_slot[m_occupied] = new Snack(snack->getName(), snack->getCalorie());
            ++m_occupied;
        }
        else
        {
            std::cout << "SnackSlot is full!" << std::endl;
        }
    }
}

int SnackSlot::getSlotCalorie() const 
{
    int getCalorie = 0;

    for(int i = 0; i < m_occupied; ++i)
    {

        getCalorie += m_slot[i]->getCalorie();

    }

    return getCalorie;
}

int SnackSlot::freeSlot() const
{
    return m_size - m_occupied;
}