#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "recipewindow.h"
#include "ingredientwindow.h"
#include "showoffwindow.h"
#include "csvreader.h"
#include <string>
#include <iostream>
#include <QString>
#include <QDesktopServices>
#include <QStringList>
#include <QList>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    initialSetup();
}

MainWindow::~MainWindow() {
    delete ui;
}

bool MainWindow::stob(string str) {
    return str == "1" ? true : false;
}

void MainWindow::setup() {
    ui->recipeDisplayBox->clear();
    ui->ingredientListWidget->clear();
    for (recipe* recipePT : recipes) {
        string name = recipePT->getName();
        ui->recipeDisplayBox->addItem(QString::fromStdString(name));

        string ingres = "";
        vector<ingredient*> ingredients = recipePT->getIngredients();
        for (int i=0; i<ingredients.size()-1; i++)
            ingres += ingredients.at(i)->getName() + ": " + to_string(ingredients.at(i)->getAmount()) + ", ";
        ingres += ingredients.at(ingredients.size()-1)->getName() + ": " + to_string(ingredients.at(ingredients.size()-1)->getAmount());
        ui->ingredientListWidget->addItem(QString::fromStdString(ingres));
    }
}

void MainWindow::initialSetup() {
    string ingredientsCSVFolder = "ingredients.csv";
    string recipesCSVFolder = "recipes.csv";

    Util::csvReader ingredientsCSV = Util::csvReader(ingredientsCSVFolder);
    ingredientsCSV.readFile();
    QList<QStringList> ingredientsData = ingredientsCSV.getData();
    if (!ingredientsData.empty()) {
        for (QStringList& row : ingredientsData)
            ingredients.push_back(new ingredient(row.at(0).toStdString(), stob(row.at(1).toStdString())));
    }

    Util::csvReader recipesCSV = Util::csvReader(recipesCSVFolder);
    recipesCSV.readFile();
    QList<QStringList> recipesData = recipesCSV.getData();
    for (QStringList& row : recipesData) {
        vector<ingredient*> ingres;
        if (row.size() > 5) {
            for (int i=3; i<row.size(); i+=3) {
                string name = row.at(i).toStdString();
                int amount = stoi(row.at(i+1).toStdString());
                bool isAlergen = stob(row.at(i+2).toStdString());
                ingres.push_back(new ingredient(name, amount, isAlergen));
            }
        }
        recipes.push_back(new recipe(row.at(0).toStdString(), row.at(1).toStdString(), ingres, stob(row.at(2).toStdString())));
    }

    setup();
}

void MainWindow::save() {
    string ingredientsCSVFolder = "ingredients.csv";
    string recipesCSVFolder = "recipes.csv";

    Util::csvReader ingredientsCSV = Util::csvReader(ingredientsCSVFolder);
    QList<QStringList> newData;

    for (ingredient* ingre : ingredients) {
        QStringList row;
        row.append(QString::fromStdString(ingre->getName()));
        row.append(QString::fromStdString(to_string(ingre->getIsAlergy())));
        newData.append(row);
    }
    ingredientsCSV.writeData(newData);

    newData.clear();

    Util::csvReader recipesCSV = Util::csvReader(recipesCSVFolder);
    for (recipe* rec : recipes) {
        QStringList row;
        row.append(QString::fromStdString(rec->getName()));
        row.append(QString::fromStdString(rec->getSteps()));
        row.append(QString::fromStdString(to_string(rec->getIsForTin())));

        for (ingredient* ingre : rec->getIngredients()) {
            row.append(QString::fromStdString(ingre->getName()));
            row.append(QString::fromStdString(to_string(ingre->getAmount())));
            row.append(QString::fromStdString(to_string(ingre->getIsAlergy())));
        }

        newData.append(row);
    }
    recipesCSV.writeData(newData);
}

void MainWindow::on_newRecipeButton_clicked() {
    hide();
    rw = new RecipeWindow(this);
    rw->show();
}

vector<ingredient*> MainWindow::getAllIngredients() {
    return ingredients;
}

void MainWindow::addRecipe(recipe *rec) {
    recipes.push_back(rec);
}

void MainWindow::addIngredients(vector<ingredient*> toAdd) {
    ingredients = toAdd;
}

void MainWindow::on_pushButton_clicked() {
    hide();
    iw = new ingredientWindow(this);
    iw->show();
}

void MainWindow::on_actionGithub_triggered() {
    QDesktopServices::openUrl(QUrl(QString::fromStdString("http://www.github.com/tadhgryan2012")));
}

void MainWindow::closeEvent(QCloseEvent *event) {
    exitWindow();
}

void MainWindow::on_actionQuit_triggered() {
    exitWindow();
}

void MainWindow::on_exitButton_clicked() {
    exitWindow();
}

void MainWindow::exitWindow() {
    save();
    close();
}

void MainWindow::editRecipe(QListWidgetItem *item) {
    string name = item->text().toStdString();
    recipe* rec;
    bool isFound = false;

    for (recipe* recipePT : recipes) {
        if (name.compare(recipePT->getName()) == 0) {
            rec = recipePT;
            isFound = true;
            break;
        }
    }
    if (!isFound)
        return;

    recipes.erase(recipes.begin() + ui->recipeDisplayBox->row(item));

    hide();
    rw = new RecipeWindow(this, rec);
    rw->show();
}

void MainWindow::on_recipeDisplayBox_itemDoubleClicked(QListWidgetItem *item) {
    editRecipe(item);
}

void MainWindow::on_funButton_clicked() {
    hide();
    sow = new showOffWindow(this);
    sow->show();
}

