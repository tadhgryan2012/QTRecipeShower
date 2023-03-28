#ifndef RECIPEWINDOW_H
#define RECIPEWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"
#include "recipe.h"

namespace Ui {
    class RecipeWindow;
}

class RecipeWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit RecipeWindow(QWidget *parent = nullptr);
    ~RecipeWindow();

private slots:
    void on_saveButton_clicked();
    void on_enterButton_clicked();
    void on_exitButton_clicked();
private:
    list<ingredient> allIngredients;
    list<ingredient> ingresOn;
    Ui::RecipeWindow *ui;
    MainWindow *mw;
    void closeEvent(QCloseEvent*);
    void exitWindow();
    void save();
    void setup();
    list<double> getRatios(list<ingredient>&);
    ingredient getElement(list<ingredient>, string);
};

#endif // RECIPEWINDOW_H
