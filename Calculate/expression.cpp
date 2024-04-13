#include "expression.h"
#include <QtWidgets/QHBoxLayout>
#include "lexema.h"
#include "editablelabel.h"

Expression::Expression(QWidget *parent) : QWidget(parent) {
    QHBoxLayout *layout = new QHBoxLayout(this);

    // Создаем объекты типа Lexema и добавляем их в горизонтальный layout
    for (int i = 0; i < 3; ++i) {
        Lexema *lexema = new Lexema(this);
        layout->addWidget(lexema);
        lexemas.append(lexema);
        connect(lexema->getLabel(),
                &EditableLabel::editingFinished,
                this,
                &Expression::onLabelEditingFinished);
    }
    setMinimumSize(layout->minimumSize());
    layout->addStretch(1);
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
}
