#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_formLayout{new QFormLayout},
    m_lineEdit_firstName{new QLineEdit},
    m_lineEdit_lastName{new QLineEdit},
    m_lineEdit_mail{new QLineEdit},
    m_lineEdit_age{new QLineEdit},
    m_submit_button{new QPushButton("Submit")},
    m_central_widget{new QWidget}
{
    ui->setupUi(this);

    m_formLayout->addRow("First Name: " , m_lineEdit_firstName.data());
    m_formLayout->addRow("Last Name: ", m_lineEdit_lastName.data());
    m_formLayout->addRow("Email: ", m_lineEdit_mail.data());
    m_formLayout->addRow("Age: ", m_lineEdit_age.data());
    m_formLayout->addWidget(m_submit_button.data());

    m_central_widget->setLayout(m_formLayout.data());
    setCentralWidget(m_central_widget.data());

     connect(m_submit_button.data(), &QPushButton::clicked, this, &MainWindow::handleSubmitButtonClick);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleSubmitButtonClick()
{
    validateForm();
}

void MainWindow::validateForm()
{
    bool flag = true;

    if(m_lineEdit_firstName->text().isEmpty() &&
       m_lineEdit_lastName->text().isEmpty() &&
       m_lineEdit_mail->text().isEmpty() &&
       m_lineEdit_age->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Please fill in all the fields.");
        return;
    }

    for(const auto symbol : m_lineEdit_firstName->text())
    {
        if(symbol.isSpace())
        {
            QMessageBox::warning(this, "Error", "first name should not contain spaces.");
            return;
        }
        else if(!symbol.isLetter())
        {
            QMessageBox::warning(this, "Error", "Please enter only alphabetic characters for the first name.");
            return;
        }
    }

    for(const auto symbol : m_lineEdit_lastName->text())
    {
        if(symbol.isSpace())
        {
            QMessageBox::warning(this, "Error", "last name should not contain spaces.");
            return;
        }
        else if(!symbol.isLetter())
        {
            QMessageBox::warning(this, "Error", "Please enter only alphabetic characters for the last name.");
            return;
        }
    }

    if(m_lineEdit_age->text().toInt() > 120)
    {
        QMessageBox::warning(this, "Error", "Please enter a valid age (less than or equal to 120).");
        return;
    }

    for(const auto symbol : m_lineEdit_age->text())
    {
        if(symbol.isSpace())
        {
            QMessageBox::warning(this, "Error", "age should not contain spaces.");
            return;
        }
        else if(!symbol.isNumber())
        {
            QMessageBox::warning(this, "Error", "Please enter only numbers for age.");
            return;
        }
    }

    QRegExp emailRegex("\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Z|a-z]{2,}\\b");

    QString email = m_lineEdit_mail->text();
    if (email.contains(emailRegex))
    {

    }
    else
    {
        QMessageBox::warning(this, "Error", "Please enter a valid email address.");
        return;
    }


    QMessageBox::information(this, "Success", "Form submitted successfully!");
    m_map_of_inputs.insert("first_name", m_lineEdit_firstName->text());
    m_map_of_inputs.insert("Last Name: ", m_lineEdit_lastName->text());
    m_map_of_inputs.insert("Email: ", m_lineEdit_mail->text()),
    m_map_of_inputs.insert("Age: ", m_lineEdit_age->text());

}
