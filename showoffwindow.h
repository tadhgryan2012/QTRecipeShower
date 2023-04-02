#ifndef SHOWOFFWINDOW_H
#define SHOWOFFWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"

namespace Ui {
class showOffWindow;
}

class showOffWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit showOffWindow(QWidget *parent = nullptr);
    ~showOffWindow();

private slots:
    void on_inputNumberBox_returnPressed();
    void on_exitButton_clicked();
    void closeEvent(QCloseEvent *event);
    void exitWindow();
    void on_colourSlider_sliderMoved(int position);

    void on_enterButton_clicked();

private:
    Ui::showOffWindow *ui;
    MainWindow *mw;

    union NumbersUnion {
        uint8_t num;
        float d;
        char c;
    } numbersUnion;

    union BitStruct {
        unsigned int num : 16;
        struct {
            unsigned int part1 : 4;
            unsigned int part2 : 4;
            unsigned int part3 : 4;
            unsigned int part4 : 4;
        };
    } bitStruct;

    void setupBoxes();
};

#endif // SHOWOFFWINDOW_H
