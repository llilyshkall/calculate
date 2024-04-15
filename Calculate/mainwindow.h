#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void click_arrow_right();
    void click_arrow_left();
    void click_arrow_right_up();
    void click_arrow_right_down();
    void click_arrow_left_up();
    void click_arrow_left_down();
    void click_ret_parent();

    void addSymbol();
    void delSymbol();

    void makeLatex();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
