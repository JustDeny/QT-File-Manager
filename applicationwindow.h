#ifndef APPLICATIONWINDOW_H
#define APPLICATIONWINDOW_H

#include <QGridLayout>
#include <QLineEdit>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QApplication>
#include <QTableView>
#include <QFileSystemModel>

#include "controller.h"
#include "customfilesystemmodel.h"
#include "headermodel.h"


class ApplicationWindow : public QMainWindow
{


public:
    ApplicationWindow(QWidget *parent = nullptr);
    ~ApplicationWindow();
public slots:
    void handleCellDoubleClick(int row, CustomModel* fsModel, QLineEdit* currentPath);
private:
    QGridLayout *grid;
    QMenu* fileMenu;
    QMenu* helpMenu;
    QLineEdit* leftInput;       //displaying current dir field that also allows to use it to change showed dir
    QLineEdit* rightInput;
    QTableView* leftTable;
    QTableView* rightTable;
    QWidget* central_widget;
    CustomModel* fsModel;
    Controller* controller;
    HeaderModel* headerModel;
};
#endif // APPLICATIONWINDOW_H
