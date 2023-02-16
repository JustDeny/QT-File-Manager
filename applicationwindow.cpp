#include "applicationwindow.h"

#include <QDir>


ApplicationWindow::ApplicationWindow(QWidget *parent)
    : QMainWindow(parent), fileMenu(new QMenu(this)), grid(new QGridLayout(this)),helpMenu(new QMenu(this)),
      leftInput(new QLineEdit(this)), rightInput(new QLineEdit(this)),leftTable(new QTableView(this)),
      rightTable(new QTableView(this)), central_widget(new QWidget(this)), controller(new Controller())
{
    QAction* quit = new QAction("&quit", this);
    fileMenu = menuBar()->addMenu("&File");
    fileMenu->addAction(quit);
    helpMenu = menuBar()->addMenu("&Help");

    grid->addWidget(leftInput, 0,0);
    grid->addWidget(rightInput, 0,1);
    grid->addWidget(leftTable, 1,0);
    grid->addWidget(rightTable, 1,1);
    central_widget->setLayout(grid);
    this->setCentralWidget(central_widget);
    fsModel = new CustomModel();
    leftTable->setModel(fsModel);
//    fsModel = new QFileSystemModel;
//    fsModel->setRootPath(QDir::rootPath());
    //controller->fsModel->setRootPath("/bin/");
    //leftTable->setModel(controller->fsModel);
    //leftTable->setRootIndex(controller->fsModel->index("/bin"));


    connect(quit, &QAction::triggered, qApp, QApplication::quit);
}

ApplicationWindow::~ApplicationWindow()
{

}

