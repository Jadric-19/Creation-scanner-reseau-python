#include "Mainwindow.h"
#include "./ui_Mainwindow.h"

#include <string>
#include "Nmap.hpp"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this) ;

    scan = new Scanneur() ;
    ui->stackedWidget->setCurrentIndex(0) ;

    connect(ui->btnScan1 , SIGNAL(clicked()) , this ,  SLOT(buttonScan1())) ;
    connect(ui->btnScan2 , SIGNAL(clicked()) , this ,  SLOT(buttonScan2())) ;
    connect(ui->btnScan3 , SIGNAL(clicked()) , this ,  SLOT(buttonScan3())) ;
    connect(ui->btnScan4 , SIGNAL(clicked()) , this ,  SLOT(buttonScan4())) ;

    connect(ui->next1 , SIGNAL(clicked()) , this , SLOT(btnSuivant())) ;
    connect(ui->next2 , SIGNAL(clicked()) , this , SLOT(btnSuivant())) ;
    connect(ui->next3 , SIGNAL(clicked()) , this , SLOT(btnSuivant())) ;
    connect(ui->next4 , SIGNAL(clicked()) , this , SLOT(btnSuivant())) ;


}


MainWindow::~MainWindow()
{
    delete ui ;
}

void MainWindow::buttonScan1()
{
    ui->textResult->setText("") ;
    QString ip = ui->lineIp1->text() ;

    ui->textHost1->setText("\n\n" + ip + "\n\n") ;


    ui->textResult->setText("\n\n         [ loading... ]") ;
    std::string result = scan->decouverte_hotes(ip.toStdString()) ;
    std::cout << scan->decouverte_hotes(ip.toStdString()) << std::endl ;

    ui->textResult->setText("\n\n" + QString::fromStdString(result) + "\n\n" ) ;
    QCoreApplication::processEvents() ;

}


void MainWindow::buttonScan2()
{
    ui->textResult->setText("") ;
    QString ip = ui->lineIp2->text() ;
    ui->textHost2->setText("\n\n" + ip + "\n\n") ;

    ui->textResult->setText("\n\n         [ loading... ]") ;
    std::string result = scan->detection_services(ip.toStdString()) ;
    std::cout << scan->detection_services(ip.toStdString()) << std::endl ;

    ui->textResult->setText("\n\n" + QString::fromStdString(result) + "\n\n" ) ;

    QCoreApplication::processEvents();
}


void MainWindow::buttonScan3()
{
    ui->textResult->setText("") ;
    QString ip = ui->lineIp3->text() ;

    ui->textHost3->setText("\n\n" + ip + "\n\n") ;

    ui->textResult->setText("\n\n         [ loading... ]") ;
    std::string result = scan->detection_os(ip.toStdString()) ;
    std::cout << scan->detection_os(ip.toStdString()) << std::endl ;

    ui->textResult->setText("\n\n" + QString::fromStdString(result) + "\n\n" ) ;
    QCoreApplication::processEvents();
}


void MainWindow::buttonScan4()
{
    ui->textResult->setText("") ;
    QString ip = ui->lineIp4->text() ;


    ui->textHost4->setText("\n\n" + ip + "\n\n") ;

     ui->textResult->setText("\n\n         [ loading... ]") ;
    std::string result = scan->scan_syn(ip.toStdString()) ;
    std::cout << scan->scan_syn(ip.toStdString()) << std::endl ;

    ui->textResult->setText("\n\n" + QString::fromStdString(result) + "\n\n" ) ;
    QCoreApplication::processEvents();
}



void MainWindow::btnSuivant()
{
    int currentIndex = ui->stackedWidget->currentIndex() ;
    int totalPages = ui->stackedWidget->count() ;

    int nextIndex = (currentIndex + 1) % totalPages ;

    ui->stackedWidget->setCurrentIndex(nextIndex) ;
}
