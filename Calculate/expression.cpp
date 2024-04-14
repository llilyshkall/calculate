#include "expression.h"
#include <QtWidgets/QHBoxLayout>
#include "lexema.h"
#include "editablelabel.h"

Expression::Expression(QWidget *parent) : QWidget(parent) {
    QGridLayout *layout = new QGridLayout(this);
    EditableLabel *label = new EditableLabel(this);
    label->setText("abc");
    layout->addWidget(label, 1, 1);

    layout->setColumnStretch(3, 1);
    layout->setRowStretch(3, 1);
}
