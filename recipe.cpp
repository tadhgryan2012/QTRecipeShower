#include "recipe.h"

recipe::recipe(string name, string steps, vector<ingredient*> ingredients, bool isForTin) {
    this->name = name;
    this->steps = steps;
    this->ingredients = ingredients;
    this->isForTin = isForTin;
}
recipe::recipe(string name) {
    this->name = name;
}
recipe::recipe(recipe &rec) {
    name = rec.name;
    steps = rec.steps;
    ingredients = rec.ingredients;
    isForTin = rec.isForTin;
}
string recipe::getName() {
    return name;
}
string recipe::getSteps() {
    return steps;
}
vector<ingredient*> recipe::getIngredients() {
    return ingredients;
}
bool recipe::getIsForTin() {
    return isForTin;
}

void recipe::setName(string name) {
    this->name = name;
}
void recipe::setSteps(string steps) {
    this->steps = steps;
}
void recipe::setIngredients(vector<ingredient*> ingredients) {
    this->ingredients = ingredients;
}
void recipe::addIngredient(ingredient* ingre) {
    ingredients.push_back(ingre);
}
void recipe::setIsForTin(bool isForTin) {
    this->isForTin = isForTin;
}

bool operator==(const recipe& recipe1, const recipe& recipe2) {
    if (recipe1.name == recipe2.name)
        return true;
    else return false;
}
