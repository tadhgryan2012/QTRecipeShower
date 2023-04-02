#include "recipewindow.h"
#include "ui_recipewindow.h"
#include "ingredient.h"
#include <algorithm>
#include <iostream>

RecipeWindow::RecipeWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::RecipeWindow) {
    ui->setupUi(this);
    mw = dynamic_cast<MainWindow*>(parent);
    setup();
}
RecipeWindow::RecipeWindow(QWidget *parent, recipe *rec) : QMainWindow(parent), ui(new Ui::RecipeWindow) {
    ui->setupUi(this);
    mw = dynamic_cast<MainWindow*>(parent);

    ui->nameBox->setText(QString::fromStdString(rec->getName()));
    ui->stepsTextEdit->setPlainText(QString::fromStdString(rec->getSteps()));
    ingresOn = rec->getIngredients();
    ui->tinRadioButton->setChecked(rec->getIsForTin());
    setup();
    show();
}
RecipeWindow::~RecipeWindow() {
    delete ui;
}

ingredient* RecipeWindow::getElement(vector<ingredient*> &myList, string target) {
    for (ingredient* elem : myList) {
        if (elem->getName().compare(target) == 0)
            return elem;
    }
    return new ingredient("", false);
}

void RecipeWindow::enterIngredient() {
    string name = ui->ingredientBox->currentText().toStdString();
    int amount = ui->amountSpinBox->value();

    if (amount <= 0)
        return;

    ingredient* ingre = getElement(allIngredients, name);
    ingre->setAmount(amount);

    ingresOn.push_back(ingre);
    ui->ingredientList->addItem(QString::fromStdString(name));
    ui->amountList->addItem(QString::number(amount));
}

void RecipeWindow::on_enterButton_clicked() {
    enterIngredient();
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

void RecipeWindow::save() {
    string name = ui->nameBox->text().toStdString();
    string steps = ui->stepsTextEdit->toPlainText().toStdString();
    bool isTin = ui->tinRadioButton->isChecked();

    if (name.empty())
        return;

    recipe *newRec = new recipe(name, steps, ingresOn, isTin);

    mw->addRecipe(newRec);
}

void RecipeWindow::setup() {
    allIngredients = mw->getAllIngredients();
    for (ingredient* ingrePT : allIngredients) {
        ui->ingredientBox->addItem(QString::fromStdString(ingrePT->getName()));
    }
    ui->tinRadioButton->click();

    for (ingredient *ingre : ingresOn) {
        string name = ingre->getName();
        int amount = ingre->getAmount();
        ui->ingredientList->addItem(QString::fromStdString(name));
        ui->amountList->addItem(QString::number(amount));
    }
}

void RecipeWindow::on_ingredientList_itemDoubleClicked(QListWidgetItem *item) {
    string name = item->text().toStdString();

    ingredient* ingre;
    int i;
    bool isFound = false;
    for (i=0; i<ingresOn.size(); i++) {
        if (name == ingresOn.at(i)->getName()) {
            ingre = ingresOn.at(i);
            isFound = true;
            break;
        }
    }
    if (!isFound)
        return;

    ui->ingredientBox->setCurrentIndex(i);
    ui->amountSpinBox->setValue(ingre->getAmount());

    int index = ui->ingredientList->row(item);

    std::cout << "Index: " << index << std::endl;

    ingresOn.erase(ingresOn.begin() + index);
    ui->ingredientList->takeItem(index);
    ui->amountList->takeItem(index);
}
