#include "mainwindow.h"
#include "agregardatos.h"
#include "modificardatos.h"
#include "consultardatos.h"
#include "agregarcorreo.h"
#include "agregartelefono.h"
#include "modificarcorreo.h"
#include "modificartelefono.h"
#include "borrardatos.h"
#include "borrartelefono.h"
#include "borrarcorreo.h"
#include "consultarcorreo.h"
#include "consultartelefono.h"

#include "ui_mainwindow.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString nombredb;
    nombredb = "BaseDatos.sqlite";
    dbmain = QSqlDatabase::addDatabase("QSQLITE");
    dbmain.setDatabaseName(nombredb);
    if(dbmain.open()){
        qDebug() <<"Base de datos creada";
    }
    else{
        qDebug() << "Error";
    }
    tablas();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::tablas(){
    //Tabla persona
    QString consulta;
    consulta.append("CREATE TABLE IF NOT EXISTS persona("
                    "idPersona integer PRIMARY KEY AUTOINCREMENT,"
                    "nombre varchar(20),"
                    "apellido varchar(20),"
                    "fecnac date"
                    ");");
    QSqlQuery crear;
    crear.prepare(consulta);
    if(crear.exec()){
        qDebug()<<"Tabla creada";
    }
    else{
        qDebug()<<"Error al crear tabla"<< crear.lastError();
    }

    //Tabla categoria telefono
    QString consulta2;
    consulta2.append("CREATE TABLE IF NOT EXISTS categoriatel("
                    "id integer PRIMARY KEY AUTOINCREMENT,"
                    "nombre varchar(45)"
                    ");");
    QSqlQuery crear2;
    crear2.prepare(consulta2);
    if(crear2.exec()){
        qDebug()<<"Tabla creada";
    }
    else{
        qDebug()<<"Error al crear tabla"<< crear2.lastError();
    }

    //Tabla categoria correo
    QString consulta3;
    consulta3.append("CREATE TABLE IF NOT EXISTS categoriaco("
                     "id integer PRIMARY KEY AUTOINCREMENT,"
                     "nombre varchar(45)"
                     ");");
    QSqlQuery crear3;
    crear3.prepare(consulta3);
    if(crear3.exec()){
        qDebug()<<"Tabla creada";
    }
    else{
        qDebug()<<"Error al crear tabla"<< crear3.lastError();
    }

    //Tabla telefono
    QString consulta4;
    consulta4.append("CREATE TABLE IF NOT EXISTS telefono("
                     "idPersona integer,"
                     "numero integer,"
                     "idCategoriaTel integer,"
                     "PRIMARY KEY(idPersona, numero),"
                     "FOREIGN KEY (idCategoriaTel) REFERENCES categoriatel (id),"
                     "FOREIGN KEY (idPersona) REFERENCES persona (idPersona)"
                     ");");
    QSqlQuery crear4;
    crear4.prepare(consulta4);
    if(crear4.exec()){
        qDebug()<<"Tabla creada";
    }
    else{
        qDebug()<<"Error al crear tabla"<< crear4.lastError();
    }

    //Tabla correo
    QString consulta5;
    consulta5.append("CREATE TABLE IF NOT EXISTS correo("
                     "idPersona integer,"
                     "nombreCorreo varchar(50),"
                     "idCategoriaCo integer,"
                     "PRIMARY KEY(idPersona, nombreCorreo),"
                     "FOREIGN KEY (idPersona) REFERENCES categoriaco (id),"
                     "FOREIGN KEY (idPersona) REFERENCES persona (idPersona)"
                     ");");
    QSqlQuery crear5;
    crear5.prepare(consulta5);
    if(crear5.exec()){
        qDebug()<<"Tabla creada";
    }
    else{
        qDebug()<<"Error al crear tabla"<< crear5.lastError();
    }
}

void MainWindow::on_pushButton_clicked()
{
    QSqlQueryModel * modal = new QSqlQueryModel();
    QString consulta2;
    consulta2.append("select (p.idPersona) as Id,(p.nombre) as Nombre,(p.apellido) as Apellido,(p.fecnac) as FecNac,(t.numero) as Telefono,(ct.nombre) as Categoria,(c.nombreCorreo) Correo,(cc.nombre) as Categoria from persona p "
                     "left join telefono t "
                     "on (p.idPersona = t.idPersona) "
                     "left join correo c "
                     "on (p.idPersona = c.idPersona) "
                     "left join categoriatel ct "
                     "on (t.idCategoriaTel = ct.id) "
                     "left join categoriaco cc "
                     "on (c.idCategoriaCo = cc.id)");

    QSqlQuery lista;
    lista.prepare(consulta2);
    if(lista.exec()){
        qDebug()<<"Tabla actualizada";
    }
    else{
        qDebug()<<"Error al actualizar tabla"<< lista.lastError();
    }
    modal->setQuery(lista);
    ui->tableView->setModel(modal);
}

void MainWindow::on_actionContacto_Nuevo_triggered()
{
    AgregarDatos ventana1;
    ventana1.setModal(true);
    ventana1.exec();
}

void MainWindow::on_actionTelefono_triggered()
{
    AgregarTelefono ventana5;
    ventana5.setModal(true);
    ventana5.exec();
}

void MainWindow::on_actionCorreo_triggered()
{
    AgregarCorreo ventana6;
    ventana6.setModal(true);
    ventana6.exec();
}

void MainWindow::on_actionContacto_triggered()
{
    modificardatos ventana2;
    ventana2.setModal(true);
    ventana2.exec();
}

void MainWindow::on_actionTelefono_2_triggered()
{
    ModificarTelefono ventana7;
    ventana7.setModal(true);
    ventana7.exec();
}

void MainWindow::on_actionCorreo_2_triggered()
{
    ModificarCorreo ventana8;
    ventana8.setModal(true);
    ventana8.exec();
}

void MainWindow::on_actionContacto_2_triggered()
{
    BorrarDatos ventana9;
    ventana9.setModal(true);
    ventana9.exec();
}

void MainWindow::on_actionTelefono_3_triggered()
{
    BorrarTelefono ventana10;
    ventana10.setModal(true);
    ventana10.exec();
}

void MainWindow::on_actionCorreo_3_triggered()
{
    BorrarCorreo ventana11;
    ventana11.setModal(true);
    ventana11.exec();
}

void MainWindow::on_actionCumples_triggered()
{
    ConsultarDatos ventana3;
    ventana3.setModal(true);
    ventana3.exec();
}

void MainWindow::on_actionTelefono_4_triggered()
{
    ConsultarTelefono ventana12;
    ventana12.setModal(true);
    ventana12.exec();
}

void MainWindow::on_actionCorreo_4_triggered()
{
    ConsultarCorreo ventana13;
    ventana13.setModal(true);
    ventana13.exec();
}
