#ifndef EDITABLELABEL_H
#define EDITABLELABEL_H

#include <QObject>
#include <QtWidgets>
#include "mylineedit.h"

class EditableLabel : public QLabel {
    Q_OBJECT
public:
    explicit EditableLabel(QWidget *parent = nullptr, int nesting = 1) : QLabel(parent) , nesting_(nesting) {
        setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        setStyleSheet("border: 1px solid black; color: white;");
        setAlignment(Qt::AlignCenter);
        QFont font;
        font.setPointSize(40 / nesting); // Устанавливаем размер шрифта 16

        // Устанавливаем шрифт для метки
        setFont(font);
    }

signals:
    void editingFinished(const QString &text);

protected:
    void mousePressEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) {

            // Создаем QLineEdit и устанавливаем его геометрию
            lineEdit = new MyLineEdit(qobject_cast<QWidget*>(parent()));

            lineEdit->setText(text());
            lineEdit->setGeometry(geometry());
            lineEdit->setFont(font());
            lineEdit->selectAll();
            lineEdit->show();
            // Устанавливаем фокус на QLineEdit
            lineEdit->setFocus();
            lineEdit->adjustSize();

            // Подключаем слоты для завершения редактирования
            connect(lineEdit, &MyLineEdit::editingFinished, this, &EditableLabel::finishEditing);
            connect(lineEdit, &MyLineEdit::returnPressed, this, &EditableLabel::finishEditing);
            connect(lineEdit, &QLineEdit::textChanged, this, &EditableLabel::change);

            // Скрываем QLabel
//            setHidden(true);
        }
    }
private slots:
    void change() {
        QString newText = lineEdit->text();
        setText(newText);
        QFontMetrics metrics(font());
        int textWidth = metrics.horizontalAdvance(text());
        setFixedWidth(textWidth+5); // Add some padding for better appearance
//        qobject_cast<QWidget*>(parent())->setMinimumSize(300, 300);
    }
    void finishEditing() {
        if (lineEdit) {
            // Получаем текст из QLineEdit и отправляем сигнал об окончании редактирования
//            emit editingFinished(newText);

            // Удаляем QLineEdit
            lineEdit->setParent(nullptr);
//            delete lineEdit;

            // Показываем QLabel снова
//            setHidden(false);
        }
    }


private:
    MyLineEdit *lineEdit = nullptr;
    int nesting_;
};

#endif // EDITABLELABEL_H
