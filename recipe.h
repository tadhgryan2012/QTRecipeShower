#ifndef RECIPE_H
#define RECIPE_H

#include "ingredient.h"
#include <string>
#include <list>

using namespace std;

class recipe {
private:
    string steps;
    list<ingredient> ingredients;
    list<double> ratio;
    bool isForTin;
    string name;
public:
    recipe(string, string, list<ingredient>, list<double>, bool);
    recipe();
    string getName();
    void setName(string);
    void setSteps(string);
    void setIngredients(list<ingredient>);
    void setRatio(list<double>);
    void addIngredient(ingredient);
    void setIsForTin(bool);
};

#endif // RECIPE_H
