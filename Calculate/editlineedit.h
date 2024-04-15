#ifndef EDITLINEEDIT_H
#define EDITLINEEDIT_H

#include <QWidget>
#include <QtWidgets>

class EditLineEdit : public QLineEdit {
  Q_OBJECT
public:
  EditLineEdit(QWidget *parent = nullptr) : QLineEdit(parent) {
    connect(this, &QLineEdit::textChanged, this, &EditLineEdit::adjustSize);
    adjustSize();
  }

protected:
  void adjustSize() {
    QFontMetrics metrics(font());
    int textWidth = metrics.horizontalAdvance(text());
    setFixedWidth(textWidth + 10); // Add some padding for better appearance
  }
};

#endif // EDITLINEEDIT_H
