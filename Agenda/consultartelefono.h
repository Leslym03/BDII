#ifndef CONSULTARTELEFONO_H
#define CONSULTARTELEFONO_H

#include <QDialog>
#include "QtSql/QSqlDatabase"
#include "QtSql/qsqlquery.h"
#include "QtSql/QSqlError"
#include "QtSql/QSqlQuery"
#include "QtSql/QSqlQueryModel"

namespace Ui {
class ConsultarTelefono;
}

class ConsultarTelefono : public QDialog
{
    Q_OBJECT

public:
    explicit ConsultarTelefono(QWidget *parent = nullptr);
    ~ConsultarTelefono();

private slots:
    void on_Bteleco_clicked();

private:
    Ui::ConsultarTelefono *ui;
};

#endif // CONSULTARTELEFONO_H
