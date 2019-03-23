#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVector>

namespace Ui {
class MainWindow;
} // namespace Ui

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() final;

signals:
    void request_graphic_update();

private slots:
    void graphic_update();

private:
    Ui::MainWindow *ui;

    QVector<QPushButton*>di_buttons;
    QVector<QPushButton*>do_buttons;

    void graphic_init();
};

#endif // MAINWINDOW_H
