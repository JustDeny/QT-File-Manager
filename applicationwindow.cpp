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

    leftInput->setText(controller->leftFileSysModel->getCurrentPath());
    rightInput->setText(controller->rightFileSysModel->getCurrentPath());

    grid->addWidget(leftInput, 0,0);
    grid->addWidget(rightInput, 0,1);
    grid->addWidget(leftTable, 1,0);
    grid->addWidget(rightTable, 1,1);
    central_widget->setLayout(grid);
    this->setCentralWidget(central_widget);
    leftTable->setModel(controller->leftFileSysModel);
    rightTable->setModel(controller->rightFileSysModel);

    connect(quit, &QAction::triggered, qApp, QApplication::quit);
    connect(leftInput,&QLineEdit::returnPressed,this,[this](){controller->leftFileSysModel->setCurrentPath(leftInput->text());});
    connect(rightInput,&QLineEdit::returnPressed,this,[this](){controller->rightFileSysModel->setCurrentPath(rightInput->text());});
}

ApplicationWindow::~ApplicationWindow()
{

}

