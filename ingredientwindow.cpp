#include "ingredientwindow.h"
#include "ui_ingredientwindow.h"

ingredientWindow::ingredientWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ingredientWindow) {
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
    for (ingredient ingre : allIngredients) {
        ss << ingre;
        ui->ingredientsListWidget->addItem(QString::fromStdString(ss.str()));
        ss.str("");
    }
}

void ingredientWindow::on_addButton_clicked() {
    string name = ui->nameBox->text().toStdString();
    bool alergen = ui->alergenCheckBox->isChecked();

    ingredient ingre = ingredient(name, alergen);
    ss << ingre;
    allIngredients.push_back(ingre);
    ui->ingredientsListWidget->addItem(QString::fromStdString(ss.str()));
    ss.str("");

    ui->nameBox->setText("");
    ui->alergenCheckBox->setChecked(false);
}
void ingredientWindow::on_nameBox_returnPressed() {
    ui->addButton->click();
}

void ingredientWindow::on_ingredientsListWidget_itemDoubleClicked(QListWidgetItem *item) {
    QString name = item->text().first(item->text().indexOf("\t"));
    QString alergen = item->text().last(item->text().indexOf("\t"));
    bool b_alergen = alergen == "true" ? true : false;

    ui->ingredientsListWidget->takeItem(ui->ingredientsListWidget->row(item));
    allIngredients.remove(ingredient(name.toStdString(), b_alergen));

    ui->nameBox->setText(name);
    ui->alergenCheckBox->setChecked(b_alergen);
}
