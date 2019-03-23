#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <Loader.hpp>
#include <resources.h>

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
                                                      "Runtime (*.xlsx *.csv)");

                if (f.isEmpty()) {
                    return;
                }
                Resources::get_instance().clear();
                Loader().load(f.toStdString());
                emit graphic_update();
            });

    connect(this, &MainWindow::request_graphic_update,
            this, &MainWindow::graphic_update);

    graphic_init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::graphic_init()
{
    ui->di_gb->setLayout(new QGridLayout());
    ui->do_gb->setLayout(new QGridLayout());
    ui->di_gb->setVisible(false);
    ui->do_gb->setVisible(false);
}

void MainWindow::graphic_update()
{
    decltype (auto) r = Resources::get_instance();
    auto di_layout = static_cast<QGridLayout*>(ui->di_gb->layout());
    auto do_layout = static_cast<QGridLayout*>(ui->do_gb->layout());

    qDeleteAll(di_layout->children());
    qDeleteAll(do_layout->children());
    qDeleteAll(di_buttons.begin(), di_buttons.end());
    qDeleteAll(do_buttons.begin(), do_buttons.end());

    di_buttons.clear();
    do_buttons.clear();

    for (size_t i = 0; i < r.digital_inputs.size(); i++) {
        auto layout_row = i / 16;
        auto layout_col = layout_row == 0 ? i : (i - layout_row * 16);

        di_buttons.append(new QPushButton(QString::fromStdString(r.digital_inputs.at(i).label)));

        const auto index = static_cast<int>(i);

        QString color;

        if (r.digital_inputs.at(i).get_default_value())
            color = "background-color: rgb(0,255,0);";
        else
            color = "background-color: rgb(255,0,0);";

        di_buttons.at(index)->setStyleSheet(color);
        di_buttons.at(index)->setSizePolicy(QSizePolicy::Expanding,
                                            QSizePolicy::Expanding);
        di_buttons.at(index)->setMaximumSize(150, 50);
        di_layout->addWidget(di_buttons.at(index),
                             static_cast<int>(layout_row),
                             static_cast<int>(layout_col));
    }

    for (size_t i = 0; i < r.digital_outputs.size(); i++) {
        size_t layout_row = i / 16;
        size_t layout_col = layout_row == 0 ? i : (i - layout_row * 16);

        do_buttons.append(new QPushButton(QString::fromStdString(r.digital_outputs.at(i).label)));

        const auto index = static_cast<int>(i);

        QString color;

        if (r.digital_outputs.at(i).get_default_value())
            color = "background-color: rgb(0,255,0);";
        else
            color = "background-color: rgb(255,0,0);";

        do_buttons.at(index)->setStyleSheet(color);
        do_buttons.at(index)->setSizePolicy(QSizePolicy::Expanding,
                                            QSizePolicy::Expanding);
        do_buttons.at(index)->setMaximumSize(150, 50);
        do_buttons.at(index)->setEnabled(false);

        do_layout->addWidget(di_buttons.at(index),
                             static_cast<int>(layout_row),
                             static_cast<int>(layout_col));

    }

    ui->di_gb->setVisible(true);
    ui->do_gb->setVisible(true);
}

