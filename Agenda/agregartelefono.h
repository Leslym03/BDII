#ifndef AGREGARTELEFONO_H
#define AGREGARTELEFONO_H

#include <QDialog>
#include "QtSql/QSqlDatabase"
#include "QtSql/qsqlquery.h"
#include "QtSql/QSqlError"
#include "QtSql/QSqlQuery"
#include "QtSql/QSqlQueryModel"

namespace Ui {
class AgregarTelefono;
}

class AgregarTelefono : public QDialog
{
    Q_OBJECT

public:
    explicit AgregarTelefono(QWidget *parent = nullptr);
    ~AgregarTelefono();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AgregarTelefono *ui;
};

#endif // AGREGARTELEFONO_H
