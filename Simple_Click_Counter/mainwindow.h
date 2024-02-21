// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QScopedPointer>

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
    void onButtonClicked();

private:
    Ui::MainWindow               *ui;
    QScopedPointer<QVBoxLayout>  m_main_layout;
    QScopedPointer<QPushButton>  m_click_button;
    QScopedPointer<QLabel>       m_count_label;
    int                          count;
};
#endif // MAINWINDOW_H
