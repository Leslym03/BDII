#ifndef BORRARTELEFONO_H
#define BORRARTELEFONO_H

#include <QDialog>
#include "QtSql/QSqlDatabase"
#include "QtSql/qsqlquery.h"
#include "QtSql/QSqlError"
#include "QtSql/QSqlQuery"
#include "QtSql/QSqlQueryModel"

namespace Ui {
class BorrarTelefono;
}

class BorrarTelefono : public QDialog
{
    Q_OBJECT

public:
    explicit BorrarTelefono(QWidget *parent = nullptr);
    ~BorrarTelefono();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::BorrarTelefono *ui;
};

#endif // BORRARTELEFONO_H
