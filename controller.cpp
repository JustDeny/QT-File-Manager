#include "controller.h"

Controller::Controller():
    fsModel(new QFileSystemModel())
{
    //fsModel->setRootPath("/bin");
}
