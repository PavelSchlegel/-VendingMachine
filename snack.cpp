#include <iostream>
#include <string>
#include "snack.h"

Snack::Snack()
{
    m_snackName = "Snack unknown";
    m_calories = 0;
}

Snack::Snack(const std::string &snackName, int calories)
{
    m_snackName = snackName;
    m_calories = calories;
}

Snack::Snack(const std::string &snackName)
{
    m_snackName = snackName;
    m_calories = 0;
}

Snack::~Snack()
{

}

void Snack::setName(const std::string &name)
{
    m_snackName = name;
}

void Snack::setCalorie(int calorie)
{
    m_calories = calorie;
}

std::string Snack::getName() const
{
    return m_snackName;
}

int Snack::getCalorie()
{
    return m_calories;
}