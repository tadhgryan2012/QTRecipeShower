#ifndef INGREDIENTWINDOW_H
#define INGREDIENTWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include "mainwindow.h"
#include "ingredient.h"
#include <sstream>

namespace Ui {
class ingredientWindow;
}

class ingredientWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit ingredientWindow(QWidget *parent = nullptr);
    ~ingredientWindow();

private slots:
    void on_saveButton_clicked();

    void on_addButton_clicked();

    void on_ingredientsListWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_nameBox_returnPressed();

private:
    list<ingredient> allIngredients;
    Ui::ingredientWindow *ui;
    MainWindow *mw;
    std::stringstream ss;
    void closeEvent(QCloseEvent*);
    void exitWindow();
    void save();
    void setup();
};

#endif // INGREDIENTWINDOW_H
