#ifndef BASEINGREDIENT_H
#define BASEINGREDIENT_H

#include <string>

class BaseIngredient {
protected:
    std::string name;
    bool isAlergen;

public:
    virtual std::string getName() = 0;
    virtual bool getIsAlergy() = 0;
};

#endif // BASEINGREDIENT_H
