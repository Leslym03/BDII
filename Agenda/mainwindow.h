#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QtSql/QSqlDatabase"
#include "QtSql/qsqlquery.h"
#include "QtSql/QSqlError"
#include "QtSql/QSqlQuery"
#include "QtSql/QSqlQueryModel"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();
    void tablas();

    void on_actionContacto_Nuevo_triggered();
    void on_actionTelefono_triggered();
    void on_actionCorreo_triggered();

    void on_actionContacto_triggered();
    void on_actionTelefono_2_triggered();
    void on_actionCorreo_2_triggered();

    void on_actionContacto_2_triggered();
    void on_actionTelefono_3_triggered();
    void on_actionCorreo_3_triggered();

    void on_actionCumples_triggered();
    void on_actionTelefono_4_triggered();
    void on_actionCorreo_4_triggered();

private:
    Ui::MainWindow *ui;
    QSqlDatabase dbmain;

};
#endif // MAINWINDOW_H
