#include <iostream>
#pragma once

class Snack
{
private:

    std::string m_snackName;
    int m_calories;
    
public:

    Snack(const Snack&) = default;
    Snack();
    Snack(const std::string &snackName, int calories);
    Snack(const std::string &snackName);
    ~Snack();
    void setName(const std::string &name);
    void setCalorie(int calorie);
    std::string getName() const;
    int getCalorie();
};