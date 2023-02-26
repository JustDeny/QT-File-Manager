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



#endif // CONTROLLER_H
