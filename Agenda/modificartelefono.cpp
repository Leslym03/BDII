#include "modificartelefono.h"
#include "ui_modificartelefono.h"
#include "QDebug"
#include "QMessageBox"

ModificarTelefono::ModificarTelefono(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModificarTelefono)
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
    ui->idbox->setModel(modal3);

    //Combox1
    QSqlQueryModel * modal = new QSqlQueryModel();
    QString combox1;
    combox1.append("select numero from telefono");

    QSqlQuery listacom1;
    listacom1.prepare(combox1);
    if(listacom1.exec()){
        qDebug()<<"Categoria Telefono";
    }
    else{
        qDebug()<<"Error Categoria Telefono"<< listacom1.lastError();
    }
    modal->setQuery(listacom1);
    ui->numactaulbox->setModel(modal);

    //Combox2
    QSqlQueryModel * modal2 = new QSqlQueryModel();
    QString combox2;
    combox2.append("select nombre from categoriatel");

    QSqlQuery listacom2;
    listacom2.prepare(combox2);
    if(listacom2.exec()){
        qDebug()<<"Categoria Telefono";
    }
    else{
        qDebug()<<"Error Categoria Telefono"<< listacom2.lastError();
    }
    modal2->setQuery(listacom2);
    ui->categoriabox->setModel(modal2);
}

ModificarTelefono::~ModificarTelefono()
{
    delete ui;
}

void ModificarTelefono::on_buttonBox_accepted()
{
    QString sid = ui->idbox->currentText();
    QString nactual = ui->numactaulbox->currentText();
    QString sct = ui->categoriabox->currentText();
    QString nmodif = ui->numeromodificar->text();

    //Categoria Telefono
    QString ct_id;
    if(sct == "Movil"){
        ct_id="1";
    }else{
        ct_id="2";
    }

    //Telefono
    QString modificar_t;
    modificar_t.append("UPDATE telefono SET numero=" + nmodif +
                       ", idCategoriaTel="+ ct_id+
                      " WHERE idPersona = "+sid +
                       " AND numero="+nactual);
    QSqlQuery modificar_t_db;
    modificar_t_db.prepare(modificar_t);

    if(modificar_t_db.exec()){
        qDebug()<<"Datos telefono actualizados correctamente";
    }
    else{
        qDebug()<<"Error en actualizar telefono "<<modificar_t_db.lastError();
    }

}
