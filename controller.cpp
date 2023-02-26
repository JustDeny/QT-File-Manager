#include "controller.h"

Controller::Controller():
    leftFileSysModel(new CustomModel()), leftHeaderModel(new HeaderModel()),
    rightFileSysModel(new CustomModel()), rightHeaderModel(new HeaderModel())
{
    leftHeaderModel->setSourceModel(leftFileSysModel);
    rightHeaderModel->setSourceModel(rightFileSysModel);
}

void Controller::MoveToPath(const QString& new_path)
{
}
