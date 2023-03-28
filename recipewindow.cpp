#include "recipewindow.h"
#include "ui_recipewindow.h"
#include "ingredient.h"
#include <algorithm>

RecipeWindow::RecipeWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::RecipeWindow) {
    ui->setupUi(this);
    mw = dynamic_cast<MainWindow*>(parent);
    setup();
}

RecipeWindow::~RecipeWindow() {
    delete ui;
}

ingredient RecipeWindow::getElement(list<ingredient> myList, string target) {
    for (auto elem : myList) {
        if (elem.getName() == target)
            return elem;
    }
    return ingredient("", false);
}

void RecipeWindow::on_enterButton_clicked() {
    string name = ui->ingredientBox->currentText().toStdString();
    double amount = ui->amountSpinBox->value();

    if (amount <= 0)
        return;

    ingresOn.push_back(getElement(allIngredients, name));
    ui->ingredientList->addItem(QString::fromStdString(name));
    ui->amountList->addItem(QString::number(amount));
}

void RecipeWindow::on_exitButton_clicked() {
    exitWindow();
}

void RecipeWindow::on_saveButton_clicked() {
    save();
    exitWindow();
}

void RecipeWindow::closeEvent(QCloseEvent *event) {
    exitWindow();
}

void RecipeWindow::exitWindow() {
    close();
    mw->show();
    mw->setup();
}

list<double> RecipeWindow::getRatios(list<ingredient> &ingres) {
    list<double> ratios;
    double total = 0;
    for (ingredient ingre : ingres) {
        total += ingre.getAmount();
    }
    for (ingredient ingre : ingres) {
        ratios.push_back(ingre.getAmount() / total);
    }
    return ratios;
}

void RecipeWindow::save() {
    string name = ui->nameBox->text().toStdString();
    string steps = ui->stepsTextEdit->toPlainText().toStdString();
    list<ingredient> ingres = ingresOn;
    list<double> ratios = getRatios(ingres);
    bool isTin = ui->tinRadioButton->isChecked();

    if (name.empty())
        return;

    recipe newRec = recipe(name, steps, ingres, ratios, isTin);
    mw->addRecipe(newRec);
}

void RecipeWindow::setup() {
    allIngredients = mw->getAllIngredients();
//    allIngredients.push_back(ingredient("Sugar", false));
//    allIngredients.push_back(ingredient("Flour", false));
//    allIngredients.push_back(ingredient("Baking Soda", false));
    for (ingredient ingre : allIngredients) {
        ui->ingredientBox->addItem(QString::fromStdString(ingre.getName()));
    }
    ui->tinRadioButton->click();
}
