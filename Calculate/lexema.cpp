#include "lexema.h"

Lexema::Lexema(QWidget* parent) : QWidget(parent) {
    // Создаем сетку
    QGridLayout *layout = new QGridLayout(this);

    // Создаем QLabel в центральной ячейке
    label = new EditableLabel(this);
    label->setAlignment(Qt::AlignCenter);
    label->setText("abc");
    label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    label->setStyleSheet("border: 1px solid black;");
    layout->addWidget(label, 1, 1);

    // Заполняем остальные ячейки пустыми QLabel
//    for (int row = 0; row < 3; ++row) {
//        for (int col = 0; col < 3; ++col) {
//            if (!(row == 1 && col == 1)) {
//                QLabel *emptyLabel = new QLabel(this);

//                emptyLabel->setText("");
//                emptyLabel->setStyleSheet("border: 1px solid black;");
//                layout->addWidget(emptyLabel, row, col);
//            }
//        }
//    }
}
