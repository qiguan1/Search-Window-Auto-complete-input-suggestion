#include "mainwindow.h"
#include "wordlist.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    WordList *list = centralWidget()->findChild<WordList *>("listWidget");
    MyLineEdit *lineEdit = centralWidget()->
                           findChild<MyLineEdit *>("lineEdit");
    QPushButton *pushButton = centralWidget()->
                              findChild<QPushButton *>("pushButton");
    connect(pushButton, SIGNAL(clicked(bool)),
            lineEdit, SLOT(clearTextBox()));
    list->setVisible(false);
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event);
    QWidget *central = centralWidget();
    QWidget *layoutContainer = central->findChild<QWidget *>("layoutContainer");
    layoutContainer->move(QPoint((central->width() - layoutContainer->width()) / 2,
                                 (central->height() - layoutContainer->height()) / 2));
}

MainWindow::~MainWindow()
{
    delete ui;
}
