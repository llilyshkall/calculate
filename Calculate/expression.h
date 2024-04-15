#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "editablelabel.h"
#include <QWidget>
#include <QtWidgets>

class EditableLabel;

class Expression : public QWidget {
  Q_OBJECT
public:
  Expression(QWidget *parent = nullptr);
  Expression(Expression *parent = nullptr, int nesting = 1);
  int nesting();
  QString toString();

  QGridLayout *layout;
  Expression *parent;
  int nesting_;

private slots:
  void onLabelEditingFinished(const QString &text);
};

#endif // EXPRESSION_H
