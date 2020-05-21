#ifndef MODIFICARTELEFONO_H
#define MODIFICARTELEFONO_H

#include <QDialog>
#include "QtSql/QSqlDatabase"
#include "QtSql/qsqlquery.h"
#include "QtSql/QSqlError"
#include "QtSql/QSqlQuery"
#include "QtSql/QSqlQueryModel"

namespace Ui {
class ModificarTelefono;
}

class ModificarTelefono : public QDialog
{
    Q_OBJECT

public:
    explicit ModificarTelefono(QWidget *parent = nullptr);
    ~ModificarTelefono();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ModificarTelefono *ui;
};

#endif // MODIFICARTELEFONO_H
