#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QLineEdit>
#include <QWidget>

class MyLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    MyLineEdit(QWidget *parent = nullptr) : QLineEdit(parent) {
        connect(this, &QLineEdit::textChanged, this, &MyLineEdit::adjustSize);
        adjustSize();
    }
protected:
    void adjustSize() {
        QFontMetrics metrics(font());
        int textWidth = metrics.horizontalAdvance(text());
        setFixedWidth(textWidth + 10); // Add some padding for better appearance
    }
};

#endif // MYLINEEDIT_H
