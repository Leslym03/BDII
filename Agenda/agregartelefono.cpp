#include "agregartelefono.h"
#include "ui_agregartelefono.h"
#include "QDebug"
#include "QMessageBox"

AgregarTelefono::AgregarTelefono(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AgregarTelefono)
{
    ui->setupUi(this);
    //Combox1
    QSqlQueryModel * modal = new QSqlQueryModel();
    QString combox1;
    combox1.append("select nombre from categoriatel");

    QSqlQuery listacom1;
    listacom1.prepare(combox1);
    if(listacom1.exec()){
        qDebug()<<"Categoria Telefono";
    }
    else{
        qDebug()<<"Error Categoria Telefono"<< listacom1.lastError();
    }
    modal->setQuery(listacom1);
    ui->comboBox_2->setModel(modal);

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

AgregarTelefono::~AgregarTelefono()
{
    delete ui;
}


void AgregarTelefono::on_buttonBox_accepted()
{
    //ID persona
    QString sid = ui->comboBox->currentText();

    //Categoria Telefono
    QString sct = ui->comboBox_2->currentText();
    QString ct_id;
    if(sct == "Movil"){
        ct_id="1";
    }else{
        ct_id="2";
    }

    QString snumero = ui->numero->text();

    QString insertar;
    insertar.append("INSERT INTO telefono (idPersona,numero,idCategoriaTel) "
                    "values(:idPersona,:numero,:idCategoriaTel);");

    QSqlQuery insertar_db;
    insertar_db.prepare(insertar);
    insertar_db.bindValue(":idPersona", sid);
    insertar_db.bindValue(":numero", snumero);
    insertar_db.bindValue(":idCategoriaTel", ct_id);

    if(insertar_db.exec()){
        qDebug()<<"Telefono correctamente";
    }
    else{
        qDebug()<<"Error en Telefono"<<insertar_db.lastError();
    }

}
