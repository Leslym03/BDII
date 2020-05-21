#include "borrarcorreo.h"
#include "ui_borrarcorreo.h"
#include "QDebug"
#include "QMessageBox"
BorrarCorreo::BorrarCorreo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BorrarCorreo)
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

    //Combox2
    QSqlQueryModel * modal2 = new QSqlQueryModel();
    QString combox2;
    combox2.append("select nombreCorreo from correo");

    QSqlQuery listacom2;
    listacom2.prepare(combox2);
    if(listacom2.exec()){
        qDebug()<<"Id personas";
    }
    else{
        qDebug()<<"Error Id personas"<< listacom2.lastError();
    }
    modal2->setQuery(listacom2);
    ui->comboBox_2->setModel(modal2);
}

BorrarCorreo::~BorrarCorreo()
{
    delete ui;
}

void BorrarCorreo::on_buttonBox_accepted()
{
    QString sid = ui->comboBox->currentText();
    QString scorreo = ui->comboBox_2->currentText();

    QString eliminar;
    eliminar.append("DELETE FROM correo WHERE idPersona = "+sid+
                    " AND nombreCorreo ='" +scorreo+"'");

    QSqlQuery eliminar_db;
    eliminar_db.prepare(eliminar);

    if(eliminar_db.exec()){
        qDebug()<<"Datos eliminados correctamente";
    }
    else{
        qDebug()<<"Error al eliminar"<<eliminar_db.lastError();
    }
}
