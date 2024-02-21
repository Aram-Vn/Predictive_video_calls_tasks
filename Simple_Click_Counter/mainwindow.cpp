// mainwindow.cpp
#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_main_layout{new QVBoxLayout()},
    m_click_button{new QPushButton("Click me", this)},
    m_count_label{new QLabel("Count: 0", this)},
    count{0}


{
    ui->setupUi(this);

    // Connect the button click signal to the custom slot
    connect(m_click_button.data(), &QPushButton::clicked, this, &MainWindow::onButtonClicked);

    // Set up the layout
    m_main_layout->addWidget(m_click_button.data());
    m_main_layout->addWidget(m_count_label.data());
    centralWidget()->setLayout(m_main_layout.data());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onButtonClicked()
{
    // Increment the counter and update the label
    count++;
    m_count_label->setText("Count: " + QString::number(count));
}
