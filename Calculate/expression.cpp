#include "expression.h"
#include <QtWidgets/QHBoxLayout>
#include "lexema.h"
#include "editablelabel.h"


int Expression::nesting() {
    return nesting_;
}

Expression::Expression(QWidget *parent) :Expression(nullptr, 1) {
    layout->setAlignment(Qt::AlignBottom | Qt::AlignRight);
}

Expression::Expression(Expression *parent, int nesting): QWidget(nullptr), parent(parent), nesting_(nesting) {
   layout = new QGridLayout(this);
   layout->setSpacing(0); // Установка межколоночного и межстрочного пространства в 0
   EditableLabel *label = new EditableLabel(this);
   label->setText("");
   layout->addWidget(label, 1, 1);
   layout->setColumnStretch(300000, 1);
   layout->setRowStretch(3, 1);
   layout->setSpacing(0);
   layout->setAlignment(Qt::AlignBottom | Qt::AlignLeft);
   setStyleSheet("margin: 0px; padding: 0px;");
}

void Expression::onLabelEditingFinished(const QString &text) {
    // Получаем указатель на QLabel и обновляем его текст
    EditableLabel *label = qobject_cast<EditableLabel*>(sender());
    if (label) {
        label->setText(text);
    }
}

QString Expression::toString() {
    QString str = "";
    int i = 1;
    while (layout->itemAtPosition(1, i)) {
        if (layout->itemAtPosition(0, i - 1)) {
            Expression* expr = qobject_cast<Expression*>(layout->itemAtPosition(0, i - 1)->widget());
            str += "^{" + expr->toString() + "}";
        }
        if (layout->itemAtPosition(2, i - 1)) {
            Expression* expr = qobject_cast<Expression*>(layout->itemAtPosition(2, i - 1)->widget());
            str += "_{" + expr->toString() + "}";
        }
        EditableLabel* lexema = qobject_cast<EditableLabel*>(layout->itemAtPosition(1, i)->widget());
        str += "{" + lexema->text() + "}";

        if (layout->itemAtPosition(2, i + 1)) {
            Expression* expr = qobject_cast<Expression*>(layout->itemAtPosition(2, i + 1)->widget());
            str += "_{" + expr->toString() + "}";
        }
        if (layout->itemAtPosition(0, i + 1)) {
                    Expression* expr = qobject_cast<Expression*>(layout->itemAtPosition(0, i + 1)->widget());
                    str += "^{" + expr->toString() + "}";
                }
        i += 3;
    }
    return str;
}
