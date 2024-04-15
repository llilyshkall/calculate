#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lexema.h"
#include "editablelabel.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    EditableLabel::select = qobject_cast<EditableLabel*>(ui->widget->layout->itemAtPosition(1,1)->widget());
    EditableLabel::select->setStyleSheet(STYLE_SELECT);
    connect(ui->pushButton_arrow_right, &QPushButton::clicked, this, &MainWindow::click_arrow_right);
    connect(ui->pushButton_arrow_left, &QPushButton::clicked, this, &MainWindow::click_arrow_left);

    connect(ui->pushButton_arrow_right_up, &QPushButton::clicked, this, &MainWindow::click_arrow_right_up);
    connect(ui->pushButton_arrow_right_down, &QPushButton::clicked, this, &MainWindow::click_arrow_right_down);


    connect(ui->pushButton_arrow_left_up, &QPushButton::clicked, this, &MainWindow::click_arrow_left_up);
    connect(ui->pushButton_arrow_left_down, &QPushButton::clicked, this, &MainWindow::click_arrow_left_down);

    connect(ui->pushButton_ret_parent, &QPushButton::clicked, this, &MainWindow::click_ret_parent);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::click_arrow_right() {
    QGridLayout* layout = EditableLabel::select->parent_->layout;
    int row = 0, column = 0, rowSpan = 0, columnSpan = 0;
    layout->getItemPosition(layout->indexOf(EditableLabel::select), &row, &column, &rowSpan, &columnSpan);
    QLayoutItem *item = layout->itemAtPosition(row, column + 3);
    if (item) {
        // элемент найден, выполняем действия с ним
        EditableLabel::select->setStyleSheet(STYLE_NOT_SELECT);
        EditableLabel::select = qobject_cast<EditableLabel*>(layout->itemAtPosition(row, column + 3)->widget());
        EditableLabel::select->setStyleSheet(STYLE_SELECT);
    } else {
        // элемент не найден
        EditableLabel::select->setStyleSheet(STYLE_NOT_SELECT);
        Expression* expr = qobject_cast<Expression*>(EditableLabel::select->parent_);
        EditableLabel *label = new EditableLabel(expr);
        label->setText("");
        layout->addWidget(label, row, column + 3);
        EditableLabel::select = label;
        EditableLabel::select->setStyleSheet(STYLE_SELECT);
    }
}

void MainWindow::click_arrow_left() {
    QGridLayout* layout = EditableLabel::select->parent_->layout;
    int row = 0, column = 0, rowSpan = 0, columnSpan = 0;
    layout->getItemPosition(layout->indexOf(EditableLabel::select), &row, &column, &rowSpan, &columnSpan);
    if (column - 3 > 0) {
        QLayoutItem *item = layout->itemAtPosition(row, column - 3);
        EditableLabel::select->setStyleSheet(STYLE_NOT_SELECT);
        EditableLabel::select = qobject_cast<EditableLabel*>(item->widget());
        EditableLabel::select->setStyleSheet(STYLE_SELECT);
    }
}

void MainWindow::click_arrow_right_up() {
    QGridLayout* layout = EditableLabel::select->parent_->layout;
    int row = 0, column = 0, rowSpan = 0, columnSpan = 0;
    layout->getItemPosition(layout->indexOf(EditableLabel::select), &row, &column, &rowSpan, &columnSpan);
    QLayoutItem *item = layout->itemAtPosition(row-1, column + 1);
    qDebug() << "right_up";
    if (item) {
        qDebug() << "search";
        EditableLabel::select->setStyleSheet(STYLE_NOT_SELECT);
        Expression* new_expression = qobject_cast<Expression*>(layout->itemAtPosition(row-1, column + 1)->widget());
        EditableLabel::select = qobject_cast<EditableLabel*>(new_expression->layout->itemAtPosition(1, 1)->widget());
        EditableLabel::select->setStyleSheet(STYLE_SELECT);
    } else {
        // элемент не найден
        qDebug() << "not";
        EditableLabel::select->setStyleSheet(STYLE_NOT_SELECT);
        Expression* new_expression = new Expression(EditableLabel::select->parent_,
                                                    EditableLabel::select->parent_->nesting() + 1);
//        QGridLayout* layout = EditableLabel::select->parent_;
        layout->addWidget(new_expression, row-1, column+1);
        EditableLabel::select = qobject_cast<EditableLabel*>(new_expression->layout->itemAtPosition(1, 1)->widget());
        EditableLabel::select->setStyleSheet(STYLE_SELECT);
    }
}

void MainWindow::click_arrow_right_down() {
    QGridLayout* layout = EditableLabel::select->parent_->layout;
    int row = 0, column = 0, rowSpan = 0, columnSpan = 0;
    layout->getItemPosition(layout->indexOf(EditableLabel::select), &row, &column, &rowSpan, &columnSpan);
    QLayoutItem *item = layout->itemAtPosition(row+1, column + 1);
    qDebug() << "right_up";
    if (item) {
        qDebug() << "search";
        EditableLabel::select->setStyleSheet(STYLE_NOT_SELECT);
        Expression* new_expression = qobject_cast<Expression*>(layout->itemAtPosition(row+1, column + 1)->widget());
        EditableLabel::select = qobject_cast<EditableLabel*>(new_expression->layout->itemAtPosition(1, 1)->widget());
        EditableLabel::select->setStyleSheet(STYLE_SELECT);
    } else {
        // элемент не найден
        qDebug() << "not";
        EditableLabel::select->setStyleSheet(STYLE_NOT_SELECT);
        Expression* new_expression = new Expression(EditableLabel::select->parent_,
                                                    EditableLabel::select->parent_->nesting() + 1);
//        QGridLayout* layout = EditableLabel::select->parent_;
        layout->addWidget(new_expression, row+1, column+1);
        EditableLabel::select = qobject_cast<EditableLabel*>(new_expression->layout->itemAtPosition(1, 1)->widget());
        EditableLabel::select->setStyleSheet(STYLE_SELECT);
    }
}

void MainWindow::click_arrow_left_up() {
    QGridLayout* layout = EditableLabel::select->parent_->layout;
    int row = 0, column = 0, rowSpan = 0, columnSpan = 0;
    layout->getItemPosition(layout->indexOf(EditableLabel::select), &row, &column, &rowSpan, &columnSpan);
    QLayoutItem *item = layout->itemAtPosition(row-1, column - 1);
    qDebug() << "right_up";
    if (item) {
        qDebug() << "search";
        EditableLabel::select->setStyleSheet(STYLE_NOT_SELECT);
        Expression* new_expression = qobject_cast<Expression*>(layout->itemAtPosition(row-1, column - 1)->widget());
        EditableLabel::select = qobject_cast<EditableLabel*>(new_expression->layout->itemAtPosition(1, 1)->widget());
        EditableLabel::select->setStyleSheet(STYLE_SELECT);
    } else {
        // элемент не найден
        qDebug() << "not";
        EditableLabel::select->setStyleSheet(STYLE_NOT_SELECT);
        Expression* new_expression = new Expression(EditableLabel::select->parent_,
                                                    EditableLabel::select->parent_->nesting() + 1);
//        QGridLayout* layout = EditableLabel::select->parent_;
        layout->addWidget(new_expression, row-1, column-1);
        EditableLabel::select = qobject_cast<EditableLabel*>(new_expression->layout->itemAtPosition(1, 1)->widget());
        EditableLabel::select->setStyleSheet(STYLE_SELECT);
    }
}

void MainWindow::click_arrow_left_down() {
    QGridLayout* layout = EditableLabel::select->parent_->layout;
    int row = 0, column = 0, rowSpan = 0, columnSpan = 0;
    layout->getItemPosition(layout->indexOf(EditableLabel::select), &row, &column, &rowSpan, &columnSpan);
    QLayoutItem *item = layout->itemAtPosition(row+1, column - 1);
    qDebug() << "right_up";
    if (item) {
        qDebug() << "search";
        EditableLabel::select->setStyleSheet(STYLE_NOT_SELECT);
        Expression* new_expression = qobject_cast<Expression*>(layout->itemAtPosition(row+1, column - 1)->widget());
        EditableLabel::select = qobject_cast<EditableLabel*>(new_expression->layout->itemAtPosition(1, 1)->widget());
        EditableLabel::select->setStyleSheet(STYLE_SELECT);
    } else {
        // элемент не найден
        qDebug() << "not";
        EditableLabel::select->setStyleSheet(STYLE_NOT_SELECT);
        Expression* new_expression = new Expression(EditableLabel::select->parent_,
                                                    EditableLabel::select->parent_->nesting() + 1);
//        QGridLayout* layout = EditableLabel::select->parent_;
        layout->addWidget(new_expression, row+1, column-1);
        EditableLabel::select = qobject_cast<EditableLabel*>(new_expression->layout->itemAtPosition(1, 1)->widget());
        EditableLabel::select->setStyleSheet(STYLE_SELECT);
    }
}

void MainWindow::click_ret_parent() {
    Expression* select_expr = EditableLabel::select->parent_->parent;
    EditableLabel::select->setStyleSheet(STYLE_NOT_SELECT);
    EditableLabel::select = qobject_cast<EditableLabel*>(select_expr->layout->itemAtPosition(1, 1)->widget());
    EditableLabel::select->setStyleSheet(STYLE_SELECT);
}
