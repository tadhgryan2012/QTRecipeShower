#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <list>
#include "recipe.h"
#include "ingredient.h"

class RecipeWindow;
class ingredientWindow;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    list<ingredient> getAllIngredients();
    void addRecipe(recipe);
    void addIngredients(list<ingredient>);
    void setup();

private slots:
    void on_newRecipeButton_clicked();
    void on_actionGithub_triggered();
    void on_pushButton_clicked();
    void closeEvent(QCloseEvent *);
    void on_actionQuit_triggered();

private:
    list<recipe> recipes;
    list<ingredient> ingredients;
    Ui::MainWindow *ui;
    RecipeWindow *rw;
    ingredientWindow *iw;
    void exitWindow();
};
#endif // MAINWINDOW_H
