#ifndef AGREGAR_H
#define AGREGAR_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class agregar; }
QT_END_NAMESPACE

class agregar : public QWidget
{
    Q_OBJECT
public:
    explicit agregar(QWidget *parent = nullptr);
private:
    Ui::agregar *ui;
signals:

};

#endif // AGREGAR_H
