#include "agregarcorreo.h"
#include "ui_agregarcorreo.h"
#include "QDebug"
#include "QMessageBox"

AgregarCorreo::AgregarCorreo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AgregarCorreo)
{
    ui->setupUi(this);

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
    ui->comboBox_2->setModel(modal2);

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

AgregarCorreo::~AgregarCorreo()
{
    delete ui;
}

void AgregarCorreo::on_buttonBox_accepted()
{
    //ID persona
    QString sid = ui->comboBox->currentText();

    //Categoria Telefono
    QString scc = ui->comboBox_2->currentText();
    QString cc_id;
    if(scc == "Particular"){
        cc_id="1";
    }else{
        cc_id="2";
    }

    QString scorreo = ui->correo->text();

    QString insertar;
    insertar.append("INSERT INTO correo (idPersona,nombreCorreo,idCategoriaCo) "
                    "values(:idPersona,:nombreCorreo,:idCategoriaCo);");

    QSqlQuery insertar_db;
    insertar_db.prepare(insertar);
    insertar_db.bindValue(":idPersona", sid);
    insertar_db.bindValue(":nombreCorreo", scorreo);
    insertar_db.bindValue(":idCategoriaCo", cc_id);

    if(insertar_db.exec()){
        qDebug()<<"Correo correctamente";
    }
    else{
        qDebug()<<"Error en Correo"<<insertar_db.lastError();
    }
}
