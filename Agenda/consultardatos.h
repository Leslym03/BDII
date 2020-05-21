#ifndef CONSULTARDATOS_H
#define CONSULTARDATOS_H

#include <QDialog>
#include "QtSql/QSqlDatabase"
#include "QtSql/qsqlquery.h"
#include "QtSql/QSqlError"
#include "QtSql/QSqlQuery"
#include "QtSql/QSqlQueryModel"

namespace Ui {
class ConsultarDatos;
}

class ConsultarDatos : public QDialog
{
    Q_OBJECT

public:
    explicit ConsultarDatos(QWidget *parent = nullptr);
    ~ConsultarDatos();

private slots:

private:
    Ui::ConsultarDatos *ui;
};

#endif // CONSULTARDATOS_H
