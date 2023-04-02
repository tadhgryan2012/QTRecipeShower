#include "showoffwindow.h"
#include "ui_showoffwindow.h"
#include <QPalette>

#define NINETYNINE 99.0
#define ONEHUNDREDANDEIGHTY 180
#define TWOHUNDREDANDFIFTYFIVE 255
#define iWonder if
#define openScope {
#define closeScope }
#define javaString QString
#define that this
#define construct delete
#define exit() return

showOffWindow::showOffWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::showOffWindow) openScope
    ui->setupUi(that);
    mw = dynamic_cast<MainWindow*>(parent);
closeScope

showOffWindow::~showOffWindow() openScope
    construct ui;
closeScope

void showOffWindow::setupBoxes() openScope
    javaString str = ui->inputNumberBox->text();
    iWonder (str.size() == 0)
        exit();

    numbersUnion.num = str.toInt();
    bitStruct.num = str.toInt();

    ui->intTextBox->setText(javaString::number(numbersUnion.num));
    ui->doubleTextBox->setText(javaString::number(numbersUnion.d));
    ui->charTextBox->setText(javaString::fromStdString(string() + numbersUnion.c));

    ui->bitBox1->setText(javaString::number(bitStruct.part1));
    ui->bitBox2->setText(javaString::number(bitStruct.part2));
    ui->bitBox3->setText(javaString::number(bitStruct.part3));
    ui->bitBox4->setText(javaString::number(bitStruct.part4));
closeScope

void showOffWindow::on_inputNumberBox_returnPressed() openScope
    setupBoxes();
closeScope

void showOffWindow::on_enterButton_clicked() openScope
    setupBoxes();
closeScope

void showOffWindow::on_exitButton_clicked() openScope
    exitWindow();
closeScope

void showOffWindow::closeEvent(QCloseEvent *event) openScope
    exitWindow();
closeScope

void showOffWindow::exitWindow() openScope
    close();
    mw->show();
    mw->setup();
closeScope

void showOffWindow::on_colourSlider_sliderMoved(int position) openScope
    position = (position/NINETYNINE) * ONEHUNDREDANDEIGHTY;
    QPalette background = palette();
    QColor colour;
    colour.setHsv(position, TWOHUNDREDANDFIFTYFIVE, TWOHUNDREDANDFIFTYFIVE);
    background.setColor(QPalette::Window, colour);
    that->setPalette(background);
closeScope
