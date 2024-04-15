#ifndef EDITABLELABEL_H
#define EDITABLELABEL_H

#include <QObject>
#include <QtWidgets>
#include "mylineedit.h"

#define STYLE_SELECT "border: 1px solid red; color: white"
#define STYLE_NOT_SELECT "color: white; border: 1px solid transparent;"

class Expression;

class EditableLabel : public QLabel {
    Q_OBJECT
public:
    EditableLabel(QWidget *parent = nullptr);
    EditableLabel(Expression* parent = nullptr);
    static EditableLabel* select;
    Expression* parent_;
signals:
    void editingFinished(const QString &text);
protected:
    void mousePressEvent(QMouseEvent *event) override;
private slots:
    void change();
    void finishEditing();


private:
    MyLineEdit *lineEdit = nullptr;

    int nesting_;
};

#endif // EDITABLELABEL_H
