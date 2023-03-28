#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <string>
#include <iostream>
#include <QString>
#include "recipewindow.h"
#include "ingredientwindow.h"
#include <QDesktopServices>

using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setup();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setup() {
    // Get all recipes and ingredients from csv
    for (recipe rec : recipes) {
        ui->recipeDisplayBox->addItem(QString::fromStdString(rec.getName()));
    }
}

void MainWindow::on_newRecipeButton_clicked() {
    hide();
    rw = new RecipeWindow(this);
    rw->show();
}

list<ingredient> MainWindow::getAllIngredients() {
    return ingredients;
}

void MainWindow::addRecipe(recipe rec) {
    recipes.push_back(rec);
}

void MainWindow::addIngredients(list<ingredient> toAdd) {
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

void MainWindow::exitWindow() {
//    save();
    close();
}

