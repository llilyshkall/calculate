#ifndef LEXEMA_H
#define LEXEMA_H

#include "editablelabel.h"
#include <QGridLayout>
#include <QLabel>
#include <QWidget>

class Lexema : public QWidget {
public:
  Lexema(QWidget *parent = nullptr);

  EditableLabel *getLabel() const { return label; }

private:
  EditableLabel *label;
};

#endif // LEXEMA_H
