#include "borrardatos.h"
#include "ui_borrardatos.h"
#include "QDebug"
#include "QMessageBox"

BorrarDatos::BorrarDatos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BorrarDatos)
{
    ui->setupUi(this);
    //Combox3
    QSqlQueryModel * modal3 = new QSqlQueryModel();
    QString combox3;
    combox3.append("select idPersona from persona");

    QSqlQuery listacom3;
    listacom3.prepare(combox3);
    if(listacom3.exec()){
        qDebug()<<"Id personas";
    }
    else{
        qDebug()<<"Error Id personas"<< listacom3.lastError();
    }
    modal3->setQuery(listacom3);
    ui->comboBox->setModel(modal3);

}

BorrarDatos::~BorrarDatos()
{
    delete ui;
}

void BorrarDatos::on_buttonBox_accepted()
{
    QString sborrar = ui->comboBox->currentText();

    qDebug()<<sborrar;

    QString eliminar;
    eliminar.append("DELETE FROM persona WHERE idPersona = "+sborrar);

    QSqlQuery eliminar_db;
    eliminar_db.prepare(eliminar);

    if(eliminar_db.exec()){
        qDebug()<<"Datos eliminados correctamente";
    }
    else{
        qDebug()<<"Error al eliminar"<<eliminar_db.lastError();
    }
}

void BorrarDatos::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QString sid = ui->comboBox->currentText();
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery qry;
    qry.prepare("SELECT * from persona where idPersona ="+sid);

    if(qry.exec()){
        while(qry.next()){
            modal->setQuery(qry);
            ui->tableView->setModel(modal);
        }
        qDebug()<<"Seleccion persona correctamente";
    }
    else{
        qDebug()<<"Error en seleccion persona"<<qry.lastError();
    }


}
