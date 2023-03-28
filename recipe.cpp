#include "recipe.h"

recipe::recipe(string name, string steps, list<ingredient> ingredients, list<double> ratio, bool isForTin) {
    this->name = name;
    this->steps = steps;
    this->ingredients = ingredients;
    this->ratio = ratio;
    this->isForTin = isForTin;
}
recipe::recipe() {

}

string recipe::getName() {
    return name;
}

void recipe::setName(string name) {
    this->name = name;
}
void recipe::setSteps(string steps) {
    this->steps = steps;
}
void recipe::setIngredients(list<ingredient> ingredients) {
    this->ingredients = ingredients;
}
void recipe::setRatio(list<double> ratio) {
    this->ratio = ratio;
}
void recipe::addIngredient(ingredient ingre) {
    ingredients.push_back(ingre);
}
void recipe::setIsForTin(bool isForTin) {
    this->isForTin = isForTin;
}
