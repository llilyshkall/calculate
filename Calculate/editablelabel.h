#ifndef EDITABLELABEL_H
#define EDITABLELABEL_H

#include "mylineedit.h"
#include <QObject>
#include <QtWidgets>

class Expression;

class EditableLabel : public QLabel {
  Q_OBJECT
public:
  EditableLabel(QWidget *parent = nullptr);
  EditableLabel(Expression *parent = nullptr);
  static EditableLabel *select;
  Expression *parent_;
  void setSelectStyle();
  void setDefaultStyle();
signals:
  void editingFinished(const QString &text);

protected:
  void mousePressEvent(QMouseEvent *event) override;
private slots:
  void change();
  void finishEditing();

private:
  MyLineEdit *lineEdit = nullptr;

  int nesting_;
};

#endif // EDITABLELABEL_H
