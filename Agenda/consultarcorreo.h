#ifndef CONSULTARCORREO_H
#define CONSULTARCORREO_H

#include <QDialog>
#include "QtSql/QSqlDatabase"
#include "QtSql/qsqlquery.h"
#include "QtSql/QSqlError"
#include "QtSql/QSqlQuery"
#include "QtSql/QSqlQueryModel"

namespace Ui {
class ConsultarCorreo;
}

class ConsultarCorreo : public QDialog
{
    Q_OBJECT

public:
    explicit ConsultarCorreo(QWidget *parent = nullptr);
    ~ConsultarCorreo();

private slots:
    void on_Bteleco_clicked();

private:
    Ui::ConsultarCorreo *ui;
};

#endif // CONSULTARCORREO_H
