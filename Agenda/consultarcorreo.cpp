#include "consultarcorreo.h"
#include "ui_consultarcorreo.h"
#include "QDebug"

ConsultarCorreo::ConsultarCorreo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConsultarCorreo)
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

ConsultarCorreo::~ConsultarCorreo()
{
    delete ui;
}

void ConsultarCorreo::on_Bteleco_clicked()
{
    QSqlQueryModel * modal3 = new QSqlQueryModel();
    QString sid = ui->comboBox->currentText();
    QString lista;
    lista.append("SELECT (p.nombre) as Nombre, (c.nombreCorreo) as Correo, (cc.nombre) as Categoria from persona p "
                 "left join correo c on (p.idPersona = c.idPersona) "
                 "left join categoriaco cc on (cc.id = c.idCategoriaCo) "
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
