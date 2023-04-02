#ifndef INGREDIANT_H
#define INGREDIANT_H

#include <string>
#include "baseingredient.h"
#include "IngredientAmount.h"

using namespace std;

class ingredient : BaseIngredient, IngredientAmount {
private:
    string name;
    int amount;
    bool isAlergy;

public:
    ingredient(string, bool);
    ingredient(string, int, bool);
    ingredient(ingredient&);
    string getName();
    int getAmount();
    bool getIsAlergy();
    void setAmount(int);

    friend ostream& operator<<(ostream&, const ingredient&);
    friend bool operator==(const ingredient&, const ingredient&);
};

#endif // INGREDIANT_H
