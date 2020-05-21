#ifndef AGREGARDATOS_H
#define AGREGARDATOS_H

#include <QDialog>
#include "QtSql/QSqlDatabase"
#include "QtSql/qsqlquery.h"
#include "QtSql/QSqlError"
#include "QtSql/QSqlQuery"
#include "QtSql/QSqlQueryModel"

namespace Ui {
class AgregarDatos;
}

class AgregarDatos : public QDialog
{
    Q_OBJECT

public:
    explicit AgregarDatos(QWidget *parent = nullptr);
    ~AgregarDatos();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AgregarDatos *ui;
};

#endif // AGREGARDATOS_H
