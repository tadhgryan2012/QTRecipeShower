#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "recipe.h"
#include "ingredient.h"
#include <QListWidgetItem>
#include <vector>

class RecipeWindow;
class ingredientWindow;
class showOffWindow;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    vector<ingredient*> getAllIngredients();
    void addRecipe(recipe*);
    void addIngredients(vector<ingredient*>);
    void setup();

private slots:
    void on_newRecipeButton_clicked();
    void on_actionGithub_triggered();
    void on_pushButton_clicked();
    void closeEvent(QCloseEvent *);
    void on_actionQuit_triggered();
    void on_recipeDisplayBox_itemDoubleClicked(QListWidgetItem *item);
    void on_exitButton_clicked();
    void on_funButton_clicked();

private:
    vector<recipe*> recipes;
    vector<ingredient*> ingredients;
    Ui::MainWindow *ui;
    RecipeWindow *rw;
    ingredientWindow *iw;
    showOffWindow *sow;
    void exitWindow();
    void initialSetup();
    void save();
    bool stob(string);
    void editRecipe(QListWidgetItem*);
};
#endif // MAINWINDOW_H
