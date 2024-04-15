#include "editablelabel.h"
#include "expression.h"

EditableLabel *EditableLabel::select = nullptr;

EditableLabel::EditableLabel(QWidget *parent) : QLabel(parent) {}

EditableLabel::EditableLabel(Expression *parent)
    : QLabel(nullptr), parent_(parent) {
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  setDefaultStyle();
  setAlignment(Qt::AlignCenter);
  QFont font;
  font.setPointSize(40 / parent_->nesting()); // Устанавливаем размер шрифта 16

  // Устанавливаем шрифт для метки
  setFont(font);
}

void EditableLabel::mousePressEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton) {
    select->setDefaultStyle();
    select = this;
    setSelectStyle();
    // Создаем QLineEdit и устанавливаем его геометрию
    lineEdit = new MyLineEdit(qobject_cast<QWidget *>(parent()));

    lineEdit->setText(text());
    lineEdit->setGeometry(geometry());
    lineEdit->setFont(font());
    lineEdit->selectAll();
    lineEdit->show();
    // Устанавливаем фокус на QLineEdit
    lineEdit->setFocus();
    lineEdit->adjustSize();

    // Подключаем слоты для завершения редактирования
    connect(lineEdit, &MyLineEdit::editingFinished, this,
            &EditableLabel::finishEditing);
    connect(lineEdit, &MyLineEdit::returnPressed, this,
            &EditableLabel::finishEditing);
    connect(lineEdit, &QLineEdit::textChanged, this, &EditableLabel::change);

    // Скрываем QLabel
    //            setHidden(true);
  }
}

void EditableLabel::change() {
  QString newText = lineEdit->text();
  setText(newText);
  QFontMetrics metrics(font());
  int textWidth = metrics.horizontalAdvance(text());
  setFixedWidth(textWidth + 5); // Add some padding for better appearance
  //        qobject_cast<QWidget*>(parent())->setMinimumSize(300, 300);
}
void EditableLabel::finishEditing() {
  if (lineEdit) {
    // Удаляем QLineEdit
    lineEdit->setParent(nullptr);
    //            delete lineEdit;
    setSelectStyle();
    // Показываем QLabel снова
    //            setHidden(false);
  }
}

void EditableLabel::setSelectStyle() {
  setStyleSheet("border: 1px solid rgb(134,  27,  227); color: white; padding: "
                "0px; border-radius: 5px; margin: 1px;");
}

void EditableLabel::setDefaultStyle() {
  if (text().isEmpty()) {
    setStyleSheet(
        "color: white; border: 1px dashed white; padding: 0px; margin: 1px;");

  } else {
    setStyleSheet("color: white; border: 1px solid transparent; padding: 0px; "
                  "margin: 1px;");
  }
}
