#include <iostream>
#include <string>
#include "snack.h"
#include "slot.h"
#include "vedingmachine.h"

int main()
{

    Snack *bounty = new Snack("Bounty", 20);
    Snack *snickers = new Snack("Snickers", 80);
    Snack *cola = new Snack("Cola", 50);
    SnackSlot *slot = new SnackSlot(10/*количество батончиков, которые помещаются в слот*/);
    
    slot->addSnack(bounty); //Добавляем батончик в слот
    slot->addSnack(snickers);
    slot->addSnack(cola);
    VendingMachine *machine = new VendingMachine(10/*slotCount Количество слотов для снеков*/);
    machine->addSlot(slot); //Помещаем слот обратно в аппарат
    
    std::cout << machine->getEmptySlotsCount() << std::endl; //Должно выводить количество пустых слотов для снеков
    std::cout << machine->getSlotCalorie() << std::endl;
    delete machine;
    delete slot; 
    
    delete snickers;
    delete bounty;
    delete cola;
    return 0;
}