#include "lexema.h"

Lexema::Lexema(QWidget* parent) : QWidget(parent) {
    // Создаем сетку
    QGridLayout *layout = new QGridLayout(this);

    // Создаем QLabel в центральной ячейке
    label = new EditableLabel();
    label->setAlignment(Qt::AlignCenter);
    label->setText("abc");
    layout->addWidget(label, 1, 1);

    // Заполняем остальные ячейки пустыми QLabel
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (!(row == 1 && col == 1)) {
                EditableLabel *emptyLabel = new EditableLabel();

                emptyLabel->setText("");
                emptyLabel->setAlignment(Qt::AlignCenter);
                layout->addWidget(emptyLabel, row, col);
            }
        }
    }
    setMinimumSize(layout->minimumSize());
}
