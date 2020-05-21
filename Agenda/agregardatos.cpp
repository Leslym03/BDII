#include "agregardatos.h"
#include "ui_agregardatos.h"
#include "QDebug"
#include "QMessageBox"

AgregarDatos::AgregarDatos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AgregarDatos)
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
    ui->comboBox->setModel(modal);

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

}

AgregarDatos::~AgregarDatos()
{
    delete ui;
}

void AgregarDatos::on_buttonBox_accepted()
{
    QString sid = ui->id->text();
    QString snombre = ui->nombre->text();
    QString sapellido = ui->apellido->text();
    QString sfechanac = ui->fechanac->text();
    QString stelefono = ui->telefono->text();
    QString scorreo = ui->correo->text();

    QString insertar;
    insertar.append("INSERT INTO persona (idPersona,nombre,apellido,fecnac) "
                    "values(:idPersona,:nombre,:apellido,:fecnac);");

    QSqlQuery insertar_db;
    insertar_db.prepare(insertar);
    insertar_db.bindValue(":idPersona", sid);
    insertar_db.bindValue(":nombre", snombre);
    insertar_db.bindValue(":apellido", sapellido);
    insertar_db.bindValue(":fecnac", sfechanac);

    if(insertar_db.exec()){
        qDebug()<<"Datos persona ingresados correctamente";
    }
    else{
        qDebug()<<"Error en ingresar persona "<<insertar_db.lastError();
    }

    //Categoria Telefono
    QString sct = ui->comboBox->currentText();
    QString ct_id;
    if(sct == "Movil"){
        ct_id="1";
    }else{
        ct_id="2";
    }

    //Categoria Correo
    QString scc = ui->comboBox_2->currentText();
    QString cc_id;
    if(scc == "Particular"){
        cc_id="1";
    }else{
        cc_id="2";
    }


    if(stelefono != ""){
    //Telefono
    QString insertar_t;
    insertar_t.append("INSERT INTO telefono (idPersona,numero,idCategoriaTel) "
                    "values(:idPersona,:numero,:idCategoriaTel);");

    QSqlQuery insertar_t_db;
    insertar_t_db.prepare(insertar_t);
    insertar_t_db.bindValue(":idPersona", sid);
    insertar_t_db.bindValue(":numero", stelefono);
    insertar_t_db.bindValue(":idCategoriaTel", ct_id);

    if(insertar_t_db.exec()){
        qDebug()<<"Datos telefono ingresados correctamente";
    }
    else{
        qDebug()<<"Error en ingresar telefono "<<insertar_t_db.lastError();
    }
    }

    if(scorreo !=""){
    //Correo
    QString insertar_c;
    insertar_c.append("INSERT INTO correo (idPersona,nombreCorreo,idCategoriaCo) "
                    "values(:idPersona,:nombreCorreo,:idCategoriaCo);");

    QSqlQuery insertar_c_db;
    insertar_c_db.prepare(insertar_c);
    insertar_c_db.bindValue(":idPersona", sid);
    insertar_c_db.bindValue(":nombreCorreo", scorreo);
    insertar_c_db.bindValue(":idCategoriaCo", cc_id);

    if(insertar_c_db.exec()){
        qDebug()<<"Datos correo ingresados correctamente";
    }
    else{
        qDebug()<<"Error en ingresar correo "<<insertar_c_db.lastError();
    }
    }
}
