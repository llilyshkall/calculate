#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <QWidget>
#include <QtWidgets>
#include "editablelabel.h"

class EditableLabel;

class Expression : public QWidget {
    Q_OBJECT
public:
    Expression(QWidget *parent = nullptr);
    Expression(Expression *parent = nullptr, int nesting = 1);
    int nesting();

    QGridLayout *layout;
    Expression *parent;
    int nesting_;
private slots:
    void onLabelEditingFinished(const QString &text);


};


#endif // EXPRESSION_H
