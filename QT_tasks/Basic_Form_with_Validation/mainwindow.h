#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <QDebug>
#include <QPushButton>
#include <QScopedPointer>
#include <QMessageBox>
#include <QMap>
#include <QString>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleSubmitButtonClick();

private:
    void validateForm();

private:
    Ui::MainWindow          *ui;
    QFormLayout             *m_formLayout;
    QLineEdit               *m_lineEdit_firstName;
    QLineEdit               *m_lineEdit_lastName;
    QLineEdit               *m_lineEdit_mail;
    QLineEdit               *m_lineEdit_age;
    QLineEdit               *m_lineEdit_phoneNumber;
    QPushButton             *m_submit_button;
    QWidget                 *m_central_widget;
    QMap<QString, QString>   m_map_of_inputs;
};
#endif // MAINWINDOW_H
