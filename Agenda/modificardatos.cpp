#include "modificardatos.h"
#include "ui_modificardatos.h"
#include "QDebug"
#include "QMessageBox"

modificardatos::modificardatos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modificardatos)
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
    ui->comboBox_3->setModel(modal3);
}

modificardatos::~modificardatos()
{
    delete ui;
}

void modificardatos::on_buttonBox_accepted()
{
    QString sid = ui->comboBox_3->currentText();
    QString snombre = ui->nombre->text();
    QString sapellido = ui->apellido->text();
    QString sfechanac = ui->fechanac->text();
    QString stelefono = ui->telefono->text();
    QString scorreo = ui->correo->text();


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

    QString modificar;
    modificar.append("UPDATE persona SET nombre='" + snombre +
                     "', apellido='" + sapellido +
                     "', fecnac='" + sfechanac +
                     "' WHERE idPersona = "+sid);

    QSqlQuery modificar_db;
    modificar_db.prepare(modificar);

    if(modificar_db.exec()){
        qDebug()<<"Datos modificados correctamente";
    }
    else{
        qDebug()<<"Error en modificar"<<modificar_db.lastError();
    }

    //Telefono
    QString modificar_t;
    modificar_t.append("UPDATE telefono SET numero=" + stelefono +
                       ", idCategoriaTel="+ cc_id+
                      " WHERE idPersona = "+sid);
    QSqlQuery modificar_t_db;
    modificar_t_db.prepare(modificar_t);

    if(modificar_t_db.exec()){
        qDebug()<<"Datos telefono actualizados correctamente";
    }
    else{
        qDebug()<<"Error en actualizar telefono "<<modificar_t_db.lastError();
    }

    //Correo
    QString modificar_c;
    modificar_c.append("UPDATE correo SET nombreCorreo='" + scorreo +
                       "', idCategoriaCo=" +cc_id+
                      " WHERE idPersona = "+sid);
    QSqlQuery modificar_c_db;
    modificar_c_db.prepare(modificar_c);

    if(modificar_c_db.exec()){
        qDebug()<<"Datos correo actualizados correctamente";
    }
    else{
        qDebug()<<"Error en actualizar correo "<<modificar_c_db.lastError();
    }

}

void modificardatos::on_buscar_clicked()
{
    QString sid = ui->comboBox_3->currentText();
    QString snombre;
    snombre.append("SELECT nombre FROM persona WHERE idPersona = "+sid);
    QSqlQuery sqlnombre;
    sqlnombre.prepare(snombre);

    ui->nombre->insert(sid);
}

void modificardatos::on_comboBox_3_currentIndexChanged(const QString &arg1)
{
    QString sid = ui->comboBox_3->currentText();
    QSqlQuery qry;
    qry.prepare("SELECT * from persona where idPersona ="+sid);

    if(qry.exec()){
        while(qry.next()){
            ui->nombre->setText(qry.value(1).toString());
            ui->apellido->setText(qry.value(2).toString());
            ui->fechanac->setText(qry.value(3).toString());
        }
        qDebug()<<"Seleccion persona correctamente";
    }
    else{
        qDebug()<<"Error en seleccion persona"<<qry.lastError();
    }

    //telefono
    QSqlQuery qry2;
    qry2.prepare("SELECT * from telefono where idPersona ="+sid);

    if(qry2.exec()){
        while(qry2.next()){
            ui->telefono->setText(qry2.value(1).toString());
        }
        qDebug()<<"Seleccion telefono correctamente";
    }
    else{
        qDebug()<<"Error en seleccion telefono"<<qry2.lastError();
    }

    //Correo
    QSqlQuery qry3;
    qry3.prepare("SELECT * from correo where idPersona ="+sid);

    if(qry3.exec()){
        while(qry3.next()){
            ui->correo->setText(qry3.value(1).toString());
        }
        qDebug()<<"Seleccion Correo correctamente";
    }
    else{
        qDebug()<<"Error en seleccion Correo"<<qry3.lastError();
    }
}
