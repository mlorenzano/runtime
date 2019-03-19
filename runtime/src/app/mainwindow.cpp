#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto exit = new QAction(QStringLiteral("Exit"));
    exit->setShortcut(QKeySequence::Quit);

    auto file = new QMenu(QStringLiteral("File"));
    file->addAction(exit);

    ui->menubar->addMenu(file);
}

MainWindow::~MainWindow()
{
    delete ui;
}
