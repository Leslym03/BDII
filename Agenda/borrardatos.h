#ifndef BORRARDATOS_H
#define BORRARDATOS_H

#include <QDialog>
#include "QtSql/QSqlDatabase"
#include "QtSql/qsqlquery.h"
#include "QtSql/QSqlError"
#include "QtSql/QSqlQuery"
#include "QtSql/QSqlQueryModel"

namespace Ui {
class BorrarDatos;
}

class BorrarDatos : public QDialog
{
    Q_OBJECT

public:
    explicit BorrarDatos(QWidget *parent = nullptr);
    ~BorrarDatos();

private slots:
    void on_buttonBox_accepted();

    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::BorrarDatos *ui;
};

#endif // BORRARDATOS_H
