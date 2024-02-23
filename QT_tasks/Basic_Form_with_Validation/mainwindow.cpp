#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_formLayout{new QFormLayout},
    m_lineEdit_firstName{new QLineEdit},
    m_lineEdit_lastName{new QLineEdit},
    m_lineEdit_mail{new QLineEdit},
    m_lineEdit_age{new QLineEdit},
    m_lineEdit_phoneNumber{new QLineEdit},
    m_submit_button{new QPushButton("Submit")},
    m_central_widget{new QWidget}
{
    ui->setupUi(this);

    m_formLayout->addRow("First Name: " , m_lineEdit_firstName);
    QString name_example = "James";
    m_lineEdit_firstName->setPlaceholderText(name_example);

    m_formLayout->addRow("Last Name: ", m_lineEdit_lastName);
    QString lastName_example = "Smith";
    m_lineEdit_lastName->setPlaceholderText(lastName_example);

    m_formLayout->addRow("Phone Number: ", m_lineEdit_phoneNumber);
    QString phone_example = "012 34 56 78";
    m_lineEdit_phoneNumber->setPlaceholderText(phone_example);

    m_formLayout->addRow("Email: ", m_lineEdit_mail);
    QString email_example("your_email@example.com");
    m_lineEdit_mail->setPlaceholderText(email_example);

    m_formLayout->addRow("Age: ", m_lineEdit_age);
    QString age_example = "27";
    m_lineEdit_age->setPlaceholderText(age_example);

    m_formLayout->addWidget(m_submit_button);

    m_central_widget->setLayout(m_formLayout);
    setCentralWidget(m_central_widget);

    connect(m_submit_button, &QPushButton::clicked, this, &MainWindow::handleSubmitButtonClick);
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
       m_lineEdit_age->text().isEmpty() &&
        m_lineEdit_phoneNumber->text().isEmpty())
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
    if (!email.contains(emailRegex))
    {
        QMessageBox::warning(this, "Error", "Please enter a valid email address.");
        return;
    }

    QRegExp phoneRegex("^\\d{3} \\d{2} \\d{2} \\d{2}$");

    QString phoneNumber = m_lineEdit_phoneNumber->text();

    if (!phoneNumber.contains(phoneRegex))
    {
        QMessageBox::warning(this, "Error", "Please enter a valid phone number.\n"
                             "for example`\n"
                             "012 45 67 89");
        return;
    }

    QMessageBox::information(this, "Success", "Form submitted successfully!");
    m_map_of_inputs.insert("First_name", m_lineEdit_firstName->text());
    m_map_of_inputs.insert("Last_name", m_lineEdit_lastName->text());
    m_map_of_inputs.insert("Email", m_lineEdit_mail->text()),
    m_map_of_inputs.insert("Age", m_lineEdit_age->text());
    m_map_of_inputs.insert("Phone_Number", m_lineEdit_phoneNumber->text());
}
