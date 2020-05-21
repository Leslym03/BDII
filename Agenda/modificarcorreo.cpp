#include "modificarcorreo.h"
#include "ui_modificarcorreo.h"
#include "QDebug"
#include "QMessageBox"

ModificarCorreo::ModificarCorreo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModificarCorreo)
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
    combox1.append("select nombreCorreo from correo");

    QSqlQuery listacom1;
    listacom1.prepare(combox1);
    if(listacom1.exec()){
        qDebug()<<"Correo";
    }
    else{
        qDebug()<<"Error Correo"<< listacom1.lastError();
    }
    modal->setQuery(listacom1);
    ui->actualbox->setModel(modal);

    //Combox2
    QSqlQueryModel * modal2 = new QSqlQueryModel();
    QString combox2;
    combox2.append("select nombre from categoriaco");

    QSqlQuery listacom2;
    listacom2.prepare(combox2);
    if(listacom2.exec()){
        qDebug()<<"Categoria Correo";
    }
    else{
        qDebug()<<"Error Categoria Correo"<< listacom2.lastError();
    }
    modal2->setQuery(listacom2);
    ui->categoriabox->setModel(modal2);
}

ModificarCorreo::~ModificarCorreo()
{
    delete ui;
}

void ModificarCorreo::on_buttonBox_accepted()
{
    QString sid = ui->idbox->currentText();
    QString nactual = ui->actualbox->currentText();
    QString sct = ui->categoriabox->currentText();
    QString nmodif = ui->modifbox->text();

    //Categoria correo
    QString cc_id;
    if(sct == "Particular"){
        cc_id="1";
    }else{
        cc_id="2";
    }

    //correo
    QString modificar_t;
    modificar_t.append("UPDATE correo SET nombreCorreo='" + nmodif +
                       "', idCategoriaCo="+ cc_id+
                      " WHERE idPersona = "+sid +
                       " AND nombreCorreo='"+nactual+"' ");
    QSqlQuery modificar_t_db;
    modificar_t_db.prepare(modificar_t);

    if(modificar_t_db.exec()){
        qDebug()<<"Datos correo actualizados correctamente";
    }
    else{
        qDebug()<<"Error en actualizar correo "<<modificar_t_db.lastError();
    }
}
