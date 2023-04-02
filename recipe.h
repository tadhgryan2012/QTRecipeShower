#ifndef RECIPE_H
#define RECIPE_H

#include "ingredient.h"
#include <string>
#include <vector>

using std::string;

class recipe {
private:
    string name;
    string steps;
    vector<ingredient*> ingredients;
    bool isForTin;
public:
    recipe(string, string, vector<ingredient*>, bool);
    recipe(string);
    recipe(recipe&);
    string getName();
    string getSteps();
    vector<ingredient*> getIngredients();
    bool getIsForTin();
    void setName(string);
    void setSteps(string);
    void setIngredients(vector<ingredient*>);
    void addIngredient(ingredient*);
    void setIsForTin(bool);
    friend bool operator==(const recipe&, const recipe&);
};

#endif // RECIPE_H
