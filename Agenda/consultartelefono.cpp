#include "consultartelefono.h"
#include "ui_consultartelefono.h"
#include "QDebug"


ConsultarTelefono::ConsultarTelefono(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConsultarTelefono)
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

ConsultarTelefono::~ConsultarTelefono()
{
    delete ui;
}

void ConsultarTelefono::on_Bteleco_clicked()
{
    QSqlQueryModel * modal3 = new QSqlQueryModel();
    QString sid = ui->comboBox->currentText();
    QString lista;
    lista.append("SELECT (p.nombre)as Nombre, (t.numero) as Numero, (ct.nombre) as Categoria from persona p "
                 "left join telefono t on (p.idPersona = t.idPersona) "
                 "left join categoriatel ct on (ct.id = t.idCategoriaTel) "
                 "where p.idPersona ="+sid);

    QSqlQuery qry;
    qry.prepare(lista);

    if(qry.exec()){
        qDebug()<<"Seleccion persona correctamente";
    }
    else{
        qDebug()<<"Error en seleccion persona"<<qry.lastError();
    }
    modal3->setQuery(qry);
    ui->tableView->setModel(modal3);
}
