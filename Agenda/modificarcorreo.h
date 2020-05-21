#ifndef MODIFICARCORREO_H
#define MODIFICARCORREO_H

#include <QDialog>
#include "QtSql/QSqlDatabase"
#include "QtSql/qsqlquery.h"
#include "QtSql/QSqlError"
#include "QtSql/QSqlQuery"
#include "QtSql/QSqlQueryModel"

namespace Ui {
class ModificarCorreo;
}

class ModificarCorreo : public QDialog
{
    Q_OBJECT

public:
    explicit ModificarCorreo(QWidget *parent = nullptr);
    ~ModificarCorreo();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ModificarCorreo *ui;
};

#endif // MODIFICARCORREO_H
