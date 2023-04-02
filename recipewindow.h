#ifndef RECIPEWINDOW_H
#define RECIPEWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"
#include "recipe.h"
#include <vector>

namespace Ui {
    class RecipeWindow;
}

class RecipeWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit RecipeWindow(QWidget *parent = nullptr);
    RecipeWindow(QWidget *parent, recipe*);
    ~RecipeWindow();

private slots:
    void on_saveButton_clicked();
    void on_enterButton_clicked();
    void on_exitButton_clicked();
    void on_ingredientList_itemDoubleClicked(QListWidgetItem *item);

private:
    vector<ingredient*> allIngredients;
    vector<ingredient*> ingresOn;
    Ui::RecipeWindow *ui;
    MainWindow *mw;
    void closeEvent(QCloseEvent*);
    void exitWindow();
    void save();
    void setup();
    void enterIngredient();
    ingredient* getElement(vector<ingredient*>&, string);
};

#endif // RECIPEWINDOW_H
