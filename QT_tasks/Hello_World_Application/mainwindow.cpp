#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_from_ui->setText("hello world ui");

    m_hello_label.reset(new QLabel("Hello world programmatically", this));
    m_hello_label->setWordWrap(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}
