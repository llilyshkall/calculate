#include "expression.h"
#include <QtWidgets/QHBoxLayout>
#include "lexema.h"
#include "editablelabel.h"


int Expression::nesting() {
    return nesting_;
}

Expression::Expression(QWidget *parent) :Expression(nullptr, 1) {}

Expression::Expression(Expression *parent, int nesting): QWidget(nullptr), parent(parent), nesting_(nesting) {
   layout = new QGridLayout(this);
   EditableLabel *label = new EditableLabel(this);
   label->setText("");
   layout->addWidget(label, 1, 1);
   layout->setColumnStretch(300000, 1);
   layout->setRowStretch(3, 1);
}

void Expression::onLabelEditingFinished(const QString &text) {
    // Получаем указатель на QLabel и обновляем его текст
    EditableLabel *label = qobject_cast<EditableLabel*>(sender());
    if (label) {
        label->setText(text);
    }
}
