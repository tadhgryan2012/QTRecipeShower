#include "ingredient.h"
#include <ostream>

ingredient::ingredient(string name, bool isAlergy)
    : amount(0) {
    this->name = name;
    this->isAlergy = isAlergy;
}
ingredient::ingredient(string name, int amount, bool isAlergy) {
    this->name = name;
    this->amount = amount;
    this->isAlergy = isAlergy;
}
ingredient::ingredient(ingredient &ingre) {
    name = ingre.name;
    amount = ingre.amount;
    isAlergy = ingre.isAlergy;
}
string ingredient::getName() {
    return name;
}
int ingredient::getAmount() {
    return amount;
}
bool ingredient::getIsAlergy() {
    return isAlergy;
}
void ingredient::setAmount(int amount) {
    this->amount = amount;
}
ostream& operator<<(ostream& os, const ingredient& ingre) {
    if (ingre.amount > 0)
        os << ingre.name << "\t" << ingre.amount << "\t"<< std::boolalpha << ingre.isAlergy;
    else os << ingre.name << "\t" << std::boolalpha << ingre.isAlergy;
    return os;
}
bool operator==(const ingredient& ingre1, const ingredient& ingre2) {
    if (ingre1.name == ingre2.name &&
            ingre1.isAlergy == ingre2.isAlergy)
        return true;
    else return false;
}
