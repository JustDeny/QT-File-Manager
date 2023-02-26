#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "customfilesystemmodel.h"

#include <headermodel.h>



class Controller
{
public:
    Controller();
    void MoveToPath(const QString& new_path);
    CustomModel* leftFileSysModel;
    HeaderModel* leftHeaderModel;
    CustomModel* rightFileSysModel;
    HeaderModel* rightHeaderModel;
};

inline Controller::Controller():
    leftFileSysModel(new CustomModel()), leftHeaderModel(new HeaderModel()),
    rightFileSysModel(new CustomModel()), rightHeaderModel(new HeaderModel())
{
    leftHeaderModel->setSourceModel(leftFileSysModel);
    rightHeaderModel->setSourceModel(rightFileSysModel);
}

#endif // CONTROLLER_H
