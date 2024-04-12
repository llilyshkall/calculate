#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <QWidget>
#include <QtWidgets/QLabel>
#include "lexema.h"
#include "editablelabel.h"

class Expression : public QWidget {
public:
    Expression(QWidget *parent = nullptr);

    // Функция для доступа к QLabel в центральной ячейке определенного Lexema
    QLabel* getCentralLabel(int index) const {
        if (index >= 0 && index < lexemas.size()) {
            return lexemas[index]->getLabel();
        }
        return nullptr;
    }
private slots:
    void onLabelEditingFinished(const QString &text) {
        // Получаем указатель на QLabel и обновляем его текст
        EditableLabel *label = qobject_cast<EditableLabel*>(sender());
        if (label) {
            label->setText(text);
        }
    }
private:
    QList<Lexema*> lexemas;
};

#endif // EXPRESSION_H
