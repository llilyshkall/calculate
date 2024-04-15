#include "mainwindow.h"
#include "editablelabel.h"
#include "lexema.h"
#include "ui_mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  EditableLabel::select = qobject_cast<EditableLabel *>(
      ui->expression->layout->itemAtPosition(1, 1)->widget());
  EditableLabel::select->setSelectStyle();
  connect(ui->pushButton_arrow_right, &QPushButton::clicked, this,
          &MainWindow::click_arrow_right);
  connect(ui->pushButton_arrow_left, &QPushButton::clicked, this,
          &MainWindow::click_arrow_left);
  connect(ui->pushButton_arrow_right_up, &QPushButton::clicked, this,
          &MainWindow::click_arrow_right_up);
  connect(ui->pushButton_arrow_right_down, &QPushButton::clicked, this,
          &MainWindow::click_arrow_right_down);
  connect(ui->pushButton_arrow_left_up, &QPushButton::clicked, this,
          &MainWindow::click_arrow_left_up);
  connect(ui->pushButton_arrow_left_down, &QPushButton::clicked, this,
          &MainWindow::click_arrow_left_down);
  connect(ui->pushButton_ret_parent, &QPushButton::clicked, this,
          &MainWindow::click_ret_parent);

  ui->pushButton_arrow_left_up->setIcon(QPixmap(":/img/left_up.png"));
  ui->pushButton_arrow_left->setIcon(QPixmap(":/img/left.png"));
  ui->pushButton_arrow_left_down->setIcon(QPixmap(":/img/left_down.png"));
  ui->pushButton_arrow_right_up->setIcon(QPixmap(":/img/right_up.png"));
  ui->pushButton_arrow_right->setIcon(QPixmap(":/img/right.png"));
  ui->pushButton_arrow_right_down->setIcon(QPixmap(":/img/right_down.png"));

  connect(ui->pushButton_0, &QPushButton::clicked, this,
          &MainWindow::addSymbol);
  connect(ui->pushButton_1, &QPushButton::clicked, this,
          &MainWindow::addSymbol);
  connect(ui->pushButton_2, &QPushButton::clicked, this,
          &MainWindow::addSymbol);
  connect(ui->pushButton_3, &QPushButton::clicked, this,
          &MainWindow::addSymbol);
  connect(ui->pushButton_4, &QPushButton::clicked, this,
          &MainWindow::addSymbol);
  connect(ui->pushButton_5, &QPushButton::clicked, this,
          &MainWindow::addSymbol);
  connect(ui->pushButton_6, &QPushButton::clicked, this,
          &MainWindow::addSymbol);
  connect(ui->pushButton_7, &QPushButton::clicked, this,
          &MainWindow::addSymbol);
  connect(ui->pushButton_8, &QPushButton::clicked, this,
          &MainWindow::addSymbol);
  connect(ui->pushButton_9, &QPushButton::clicked, this,
          &MainWindow::addSymbol);
  connect(ui->pushButton_dot, &QPushButton::clicked, this,
          &MainWindow::addSymbol);
  connect(ui->pushButton_add, &QPushButton::clicked, this,
          &MainWindow::addSymbol);
  connect(ui->pushButton_sub, &QPushButton::clicked, this,
          &MainWindow::addSymbol);
  connect(ui->pushButton_mul, &QPushButton::clicked, this,
          &MainWindow::addSymbol);
  connect(ui->pushButton_div, &QPushButton::clicked, this,
          &MainWindow::addSymbol);

  connect(ui->pushButton_del, &QPushButton::clicked, this,
          &MainWindow::delSymbol);

  connect(ui->pushButton_latex, &QPushButton::clicked, this,
          &MainWindow::makeLatex);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::click_arrow_right() {
  QGridLayout *layout = EditableLabel::select->parent_->layout;
  int row = 0, column = 0, rowSpan = 0, columnSpan = 0;
  layout->getItemPosition(layout->indexOf(EditableLabel::select), &row, &column,
                          &rowSpan, &columnSpan);
  QLayoutItem *item = layout->itemAtPosition(row, column + 3);
  if (item) {
    // элемент найден, выполняем действия с ним
    EditableLabel::select->setDefaultStyle();
    EditableLabel::select = qobject_cast<EditableLabel *>(
        layout->itemAtPosition(row, column + 3)->widget());
    EditableLabel::select->setSelectStyle();
  } else {
    // элемент не найден
    EditableLabel::select->setDefaultStyle();
    Expression *expr =
        qobject_cast<Expression *>(EditableLabel::select->parent_);
    EditableLabel *label = new EditableLabel(expr);
    label->setText("");
    layout->addWidget(label, row, column + 3);
    EditableLabel::select = label;
    EditableLabel::select->setSelectStyle();
  }
}

void MainWindow::click_arrow_left() {
  QGridLayout *layout = EditableLabel::select->parent_->layout;
  int row = 0, column = 0, rowSpan = 0, columnSpan = 0;
  layout->getItemPosition(layout->indexOf(EditableLabel::select), &row, &column,
                          &rowSpan, &columnSpan);
  if (column - 3 > 0) {
    QLayoutItem *item = layout->itemAtPosition(row, column - 3);
    EditableLabel::select->setDefaultStyle();
    EditableLabel::select = qobject_cast<EditableLabel *>(item->widget());
    EditableLabel::select->setSelectStyle();
  }
}

void MainWindow::click_arrow_right_up() {
  QGridLayout *layout = EditableLabel::select->parent_->layout;
  int row = 0, column = 0, rowSpan = 0, columnSpan = 0;
  layout->getItemPosition(layout->indexOf(EditableLabel::select), &row, &column,
                          &rowSpan, &columnSpan);
  QLayoutItem *item = layout->itemAtPosition(row - 1, column + 1);
  qDebug() << "right_up";
  if (item) {
    qDebug() << "search";
    EditableLabel::select->setDefaultStyle();
    Expression *new_expression = qobject_cast<Expression *>(
        layout->itemAtPosition(row - 1, column + 1)->widget());
    EditableLabel::select = qobject_cast<EditableLabel *>(
        new_expression->layout->itemAtPosition(1, 1)->widget());
    EditableLabel::select->setSelectStyle();
  } else {
    // элемент не найден
    qDebug() << "not";
    EditableLabel::select->setDefaultStyle();
    Expression *new_expression =
        new Expression(EditableLabel::select->parent_,
                       EditableLabel::select->parent_->nesting() + 1);
    new_expression->setStyleSheet("padding:0px; margin:0px;");
    //        QGridLayout* layout = EditableLabel::select->parent_;
    layout->addWidget(new_expression, row - 1, column + 1);
    EditableLabel::select = qobject_cast<EditableLabel *>(
        new_expression->layout->itemAtPosition(1, 1)->widget());
    EditableLabel::select->setSelectStyle();
  }
}

void MainWindow::click_arrow_right_down() {
  QGridLayout *layout = EditableLabel::select->parent_->layout;
  int row = 0, column = 0, rowSpan = 0, columnSpan = 0;
  layout->getItemPosition(layout->indexOf(EditableLabel::select), &row, &column,
                          &rowSpan, &columnSpan);
  QLayoutItem *item = layout->itemAtPosition(row + 1, column + 1);
  qDebug() << "right_up";
  if (item) {
    qDebug() << "search";
    EditableLabel::select->setDefaultStyle();
    Expression *new_expression = qobject_cast<Expression *>(
        layout->itemAtPosition(row + 1, column + 1)->widget());
    EditableLabel::select = qobject_cast<EditableLabel *>(
        new_expression->layout->itemAtPosition(1, 1)->widget());
    EditableLabel::select->setSelectStyle();
  } else {
    // элемент не найден
    qDebug() << "not";
    EditableLabel::select->setDefaultStyle();
    Expression *new_expression =
        new Expression(EditableLabel::select->parent_,
                       EditableLabel::select->parent_->nesting() + 1);
    //        QGridLayout* layout = EditableLabel::select->parent_;
    layout->addWidget(new_expression, row + 1, column + 1);
    EditableLabel::select = qobject_cast<EditableLabel *>(
        new_expression->layout->itemAtPosition(1, 1)->widget());
    EditableLabel::select->setSelectStyle();
  }
}

void MainWindow::click_arrow_left_up() {
  QGridLayout *layout = EditableLabel::select->parent_->layout;
  int row = 0, column = 0, rowSpan = 0, columnSpan = 0;
  layout->getItemPosition(layout->indexOf(EditableLabel::select), &row, &column,
                          &rowSpan, &columnSpan);
  QLayoutItem *item = layout->itemAtPosition(row - 1, column - 1);
  qDebug() << "right_up";
  if (item) {
    qDebug() << "search";
    EditableLabel::select->setDefaultStyle();
    Expression *new_expression = qobject_cast<Expression *>(
        layout->itemAtPosition(row - 1, column - 1)->widget());
    EditableLabel::select = qobject_cast<EditableLabel *>(
        new_expression->layout->itemAtPosition(1, 1)->widget());
    EditableLabel::select->setSelectStyle();
  } else {
    // элемент не найден
    qDebug() << "not";
    EditableLabel::select->setDefaultStyle();
    Expression *new_expression =
        new Expression(EditableLabel::select->parent_,
                       EditableLabel::select->parent_->nesting() + 1);
    //        QGridLayout* layout = EditableLabel::select->parent_;
    layout->addWidget(new_expression, row - 1, column - 1);
    EditableLabel::select = qobject_cast<EditableLabel *>(
        new_expression->layout->itemAtPosition(1, 1)->widget());
    EditableLabel::select->setSelectStyle();
  }
}

void MainWindow::click_arrow_left_down() {
  QGridLayout *layout = EditableLabel::select->parent_->layout;
  int row = 0, column = 0, rowSpan = 0, columnSpan = 0;
  layout->getItemPosition(layout->indexOf(EditableLabel::select), &row, &column,
                          &rowSpan, &columnSpan);
  QLayoutItem *item = layout->itemAtPosition(row + 1, column - 1);
  qDebug() << "right_up";
  if (item) {
    qDebug() << "search";
    EditableLabel::select->setDefaultStyle();
    Expression *new_expression = qobject_cast<Expression *>(
        layout->itemAtPosition(row + 1, column - 1)->widget());
    EditableLabel::select = qobject_cast<EditableLabel *>(
        new_expression->layout->itemAtPosition(1, 1)->widget());
    EditableLabel::select->setSelectStyle();
  } else {
    // элемент не найден
    qDebug() << "not";
    EditableLabel::select->setDefaultStyle();
    Expression *new_expression =
        new Expression(EditableLabel::select->parent_,
                       EditableLabel::select->parent_->nesting() + 1);
    //        QGridLayout* layout = EditableLabel::select->parent_;
    layout->addWidget(new_expression, row + 1, column - 1);
    EditableLabel::select = qobject_cast<EditableLabel *>(
        new_expression->layout->itemAtPosition(1, 1)->widget());
    EditableLabel::select->setSelectStyle();
  }
}

void MainWindow::click_ret_parent() {
  Expression *select_expr = EditableLabel::select->parent_->parent;
  if (select_expr) {
    EditableLabel::select->setDefaultStyle();
    EditableLabel::select = qobject_cast<EditableLabel *>(
        select_expr->layout->itemAtPosition(1, 1)->widget());
    EditableLabel::select->setSelectStyle();
  }
}

void MainWindow::addSymbol() {
  QPushButton *button = (QPushButton *)sender();
  EditableLabel::select->setText(EditableLabel::select->text() +
                                 button->text());
}

void MainWindow::delSymbol() {
  QString labelText = EditableLabel::select->text();
  // Удаление последнего символа из строки
  labelText.chop(1);
  // Установка нового текста метки
  EditableLabel::select->setText(labelText);
}

void MainWindow::makeLatex() {
  ui->label_latex->setTextInteractionFlags(Qt::TextSelectableByMouse);
  QString str = ui->expression->toString();
  ui->label_latex->setText(str);
  QClipboard *clipboard = QGuiApplication::clipboard();

  // Копирование текста в буфер обмена
  clipboard->setText(str);
}
