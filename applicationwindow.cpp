#include "applicationwindow.h"

#include <QDesktopServices>
#include <QDir>
#include <QHeaderView>


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
    rightTable->verticalHeader()->setVisible(false);
    leftTable->verticalHeader()->setVisible(false);
    leftTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    rightTable->setSelectionBehavior(QAbstractItemView::SelectRows);

    connect(quit, &QAction::triggered, qApp, QApplication::quit);
    connect(leftInput,&QLineEdit::returnPressed,this,[this](){controller->leftFileSysModel->setCurrentPath(leftInput->text());});
    connect(rightInput,&QLineEdit::returnPressed,this,[this](){controller->rightFileSysModel->setCurrentPath(rightInput->text());});
    connect(leftTable,&QTableView::doubleClicked,this,
            [this](QModelIndex index){handleCellDoubleClick(index.row(),controller->leftFileSysModel, leftInput);});
    connect(rightTable,&QTableView::doubleClicked,this,
            [this](QModelIndex index){handleCellDoubleClick(index.row(),controller->rightFileSysModel, rightInput);});
}

ApplicationWindow::~ApplicationWindow()
{

}

void ApplicationWindow::handleCellDoubleClick(int row, CustomModel* fsModel, QLineEdit* currentPath)
{
    const auto& entry = fsModel->getList().at(row);
    if(entry.isDir()){
         fsModel->setCurrentPath(entry.absoluteFilePath());
         currentPath->setText(fsModel->getCurrentPath());
    }
    else{
        QDesktopServices::openUrl(QUrl::fromLocalFile(entry.absoluteFilePath()));
    }
}

