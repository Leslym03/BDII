#include "consultardatos.h"
#include "ui_consultardatos.h"
#include "QDebug"
#include "QMessageBox"

ConsultarDatos::ConsultarDatos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConsultarDatos)
{
    ui->setupUi(this);
    QSqlQueryModel * modal2 = new QSqlQueryModel();
    QString cumple;
    cumple.append("SELECT (nombre) as Nombre, (apellido) as Apellido, (fecnac) as Fecha, (strftime('%Y', 'now') - strftime('%Y', fecnac )) - (strftime('%m-%d', 'now') < strftime('%m-%d', fecnac )) "
                  "as Edad from persona "
                  "ORDER BY strftime('%m', fecnac)");

    QSqlQuery cumple_db;
    cumple_db.prepare(cumple);

    if(cumple_db.exec()){
        qDebug()<<"Edad correctamente";
    }
    else{
        qDebug()<<"Error Edad"<<cumple_db.lastError();
    }
    modal2->setQuery(cumple_db);
    ui->tableView->setModel(modal2);


}

ConsultarDatos::~ConsultarDatos()
{
    delete ui;
}

