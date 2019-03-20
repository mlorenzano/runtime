#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <Loader.hpp>

#include <QFileDialog>
#include <QStandardPaths>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this->ui->actionExit, &QAction::triggered,
            this, [&](){ QApplication::quit(); });

    connect(this->ui->actionOpen, &QAction::triggered,
            this, [&](){
                auto l = QStandardPaths::locate(QStandardPaths::DesktopLocation,
                                                "");
                auto f = QFileDialog::getOpenFileName(this, "Open File", l,
                                                      "Runtime (*.xlsx *.xls "
                                                      "*.csv)");
                if (f.isEmpty()) {
                    return;
                }
                Loader().load(f.toStdString());
            });
}

MainWindow::~MainWindow()
{
    delete ui;
}
