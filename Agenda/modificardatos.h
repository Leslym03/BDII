#ifndef MODIFICARDATOS_H
#define MODIFICARDATOS_H

#include <QDialog>
#include "QtSql/QSqlDatabase"
#include "QtSql/qsqlquery.h"
#include "QtSql/QSqlError"
#include "QtSql/QSqlQuery"
#include "QMessageBox"
#include "QtSql/QSqlQueryModel"

namespace Ui {
class modificardatos;
}

class modificardatos : public QDialog
{
    Q_OBJECT

public:
    explicit modificardatos(QWidget *parent = nullptr);
    ~modificardatos();

private slots:
    void on_buttonBox_accepted();

    void on_buscar_clicked();

    void on_comboBox_3_currentIndexChanged(const QString &arg1);

private:
    Ui::modificardatos *ui;
};

#endif // MODIFICARDATOS_H
