#ifndef EDITABLELABEL_H
#define EDITABLELABEL_H

#include <QObject>
#include <QtWidgets>
#include "mylineedit.h"

class EditableLabel : public QLabel {
    Q_OBJECT
public:
    explicit EditableLabel(QWidget *parent = nullptr) : QLabel(parent) {}

signals:
    void editingFinished(const QString &text);

protected:
    void mousePressEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) {
            // Получаем геометрию QLabel
            QRect rect = geometry();

            // Создаем QLineEdit и устанавливаем его геометрию
            lineEdit = new MyLineEdit(qobject_cast<QWidget*>(parent()));
            lineEdit->setGeometry(rect);
            lineEdit->setText(text());
            lineEdit->selectAll();
            lineEdit->show();
            // Устанавливаем фокус на QLineEdit
            lineEdit->setFocus();

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
};

#endif // EDITABLELABEL_H
