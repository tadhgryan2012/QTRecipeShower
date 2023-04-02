#ifndef INGREDIENTWINDOW_H
#define INGREDIENTWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include "mainwindow.h"
#include "ingredient.h"
#include <vector>

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
    void on_ingredientsListWidget_itemDoubleClicked(QListWidgetItem*);
    void on_nameBox_returnPressed();

private:
    vector<ingredient*> allIngredients;
    Ui::ingredientWindow *ui;
    MainWindow *mw;
    void closeEvent(QCloseEvent*);
    void addItemToWindow(ingredient*);
    void exitWindow();
    void save();
    void setup();
};

#endif // INGREDIENTWINDOW_H
