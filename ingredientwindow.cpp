#include "ingredientwindow.h"
#include "ui_ingredientwindow.h"

#include <iostream>
#include <sstream>

ingredientWindow::ingredientWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::ingredientWindow) {
    ui->setupUi(this);
    mw = dynamic_cast<MainWindow*>(parent);
    setup();
}

ingredientWindow::~ingredientWindow() {
    delete ui;
}

void ingredientWindow::on_saveButton_clicked() {
    exitWindow();
}

void ingredientWindow::closeEvent(QCloseEvent *event) {
    exitWindow();
}

void ingredientWindow::exitWindow() {
    save();
    close();
    mw->show();
    mw->setup();
}

void ingredientWindow::save() {
    mw->addIngredients(allIngredients);
}

void ingredientWindow::setup() {
    allIngredients = mw->getAllIngredients();
    for (ingredient* ingrePT : allIngredients) {
        addItemToWindow(ingrePT);
    }
}

void ingredientWindow::on_addButton_clicked() {
    string name = ui->nameBox->text().toStdString();
    bool alergen = ui->alergenCheckBox->isChecked();

    if (name.empty())
        return;

    ingredient *ingre = new ingredient(name, alergen);
    allIngredients.push_back(ingre);
    addItemToWindow(ingre);

    ui->nameBox->setText("");
    ui->alergenCheckBox->setChecked(false);
}
void ingredientWindow::addItemToWindow(ingredient *ingrePT) {
    std::ostringstream ss;
    ss << ingrePT->getName() << "\t\t" << boolalpha << ingrePT->getIsAlergy();
    ui->ingredientsListWidget->addItem(QString::fromStdString(ss.str()));
}

void ingredientWindow::on_nameBox_returnPressed() {
    ui->addButton->click();
}

void ingredientWindow::on_ingredientsListWidget_itemDoubleClicked(QListWidgetItem *item) {
    QString name = item->text().first(item->text().indexOf("\t"));
    QString alergen = item->text().last(item->text().indexOf("\t"));
    bool b_alergen = alergen == "true" ? true : false;

    allIngredients.erase(allIngredients.begin() + ui->ingredientsListWidget->row(item));
    ui->ingredientsListWidget->takeItem(ui->ingredientsListWidget->row(item));

    ui->nameBox->setText(name);
    ui->alergenCheckBox->setChecked(b_alergen);
}
