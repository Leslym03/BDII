#ifndef AGREGARCORREO_H
#define AGREGARCORREO_H

#include <QDialog>
#include "QtSql/QSqlDatabase"
#include "QtSql/qsqlquery.h"
#include "QtSql/QSqlError"
#include "QtSql/QSqlQuery"
#include "QtSql/QSqlQueryModel"

namespace Ui {
class AgregarCorreo;
}

class AgregarCorreo : public QDialog
{
    Q_OBJECT

public:
    explicit AgregarCorreo(QWidget *parent = nullptr);
    ~AgregarCorreo();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AgregarCorreo *ui;
};

#endif // AGREGARCORREO_H
