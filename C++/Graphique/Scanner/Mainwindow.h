#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include "Nmap.hpp"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui ;
    Scanneur *scan ;


private slots :
    void buttonScan1() ;
    void buttonScan2() ;
    void buttonScan3() ;
    void buttonScan4() ;

    void btnSuivant() ;

};
#endif // MAINWINDOW_H
