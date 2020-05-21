#include "agregar.h"
#include "ui_agregar.h"
#include "QDebug"

agregar::agregar(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::agregar)
{
    ui->setupUi(this);
}
