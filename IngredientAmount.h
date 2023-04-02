#ifndef INGREDIENTAMOUNT_H
#define INGREDIENTAMOUNT_H

class IngredientAmount {
protected:
    int amount;

public:
    virtual int getAmount() = 0;
    virtual void setAmount(int) = 0;
};

#endif // INGREDIENTAMOUNT_H
