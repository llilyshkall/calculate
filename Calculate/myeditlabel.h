#ifndef MYEDITLABEL_H
#define MYEDITLABEL_H

#include <QLineEdit>
#include <QWidget>

class MyEditLabel : public QLineEdit {
  Q_OBJECT
public:
  MyEditLabel(QWidget *parent = nullptr) : QLineEdit(parent) {
    connect(this, &QLineEdit::textChanged, this, &MyEditLabel::adjustSize);
    adjustSize();
  }

protected:
  void adjustSize() {
    QFontMetrics metrics(font());
    int textWidth = metrics.horizontalAdvance(text());
    setFixedWidth(textWidth + 10); // Add some padding for better appearance
  }
};

#endif // MYEDITLABEL_H
