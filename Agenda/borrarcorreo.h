#ifndef BORRARCORREO_H
#define BORRARCORREO_H

#include <QDialog>
#include "QtSql/QSqlDatabase"
#include "QtSql/qsqlquery.h"
#include "QtSql/QSqlError"
#include "QtSql/QSqlQuery"
#include "QtSql/QSqlQueryModel"

namespace Ui {
class BorrarCorreo;
}

class BorrarCorreo : public QDialog
{
    Q_OBJECT

public:
    explicit BorrarCorreo(QWidget *parent = nullptr);
    ~BorrarCorreo();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::BorrarCorreo *ui;
};

#endif // BORRARCORREO_H
