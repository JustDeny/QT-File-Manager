#include "customfilesystemmodel.h"


CustomModel::CustomModel():
    icon_provider(new QFileIconProvider)
{
    currentPath = "/bin";//QDir().homePath();
    list = QDir(currentPath).entryInfoList(QDir::NoDotAndDotDot | QDir::AllEntries);
}

int CustomModel::rowCount(const QModelIndex &parent) const
{
    return list.size();
}

int CustomModel::columnCount(const QModelIndex &parent) const
{
    return 4;
}

QVariant CustomModel::data(const QModelIndex &index, int role) const
{
    const auto &target = list.at(index.row());
//    switch(index.column())
//    {
//    case 0:{
//        if(role == Qt::DecorationRole){
//            return QVariant(icon_provider->icon(target));
//        }
//        else if(role == Qt::DisplayRole){
//            if(target.isDir())
//                return QVariant(target.fileName());
//            else
//                return QVariant(target.completeBaseName());
//        }
//        break;
//    }
//    case 1:
//        return QVariant(target.suffix());
//        break;
//    case 2:
//        return QVariant(target.birthTime().toString());
//        break;
//    default:
//        return QVariant();
//        break;
//    }
//    switch(role){
//    case Qt::DecorationRole:
//        if(index.column()==0)
//            return QVariant(icon_provider->icon(target));
//        break;
//    case Qt::DisplayRole:{
//        switch(index.column())
//        {
//        case 0:
//            if(target.isDir())
//                return QVariant(target.fileName());
//            else
//                return QVariant(target.completeBaseName());
//        case 1:
//            return QVariant(target.suffix());
//        case 2:
//            return QVariant(target.birthTime().toString());
//        }
//    }
//    default:
//        return QVariant();
//    }

    if(role == Qt::DecorationRole && index.column() == 0 )
    {
        return QVariant(icon_provider->icon(target));
    }
    else if(role == Qt::DisplayRole){
//        if(index.column()==0)
//        {
//            if(target.isDir())
//                return QVariant(target.fileName());
//            else
//                return QVariant(target.completeBaseName());
//        }
//        else if(index.column() ==1)
//        {
//            return QVariant(target.suffix());
//        }
//        else if(index.column() ==2)
//        {
//            return QVariant(target.birthTime().toString());
//        }
        switch(index.column())
        {
        case 0:
            if(target.isDir())
                return QVariant(target.fileName());
            else
                return QVariant(target.completeBaseName());
        case 1:
            if(!target.isDir())
                return QVariant(target.suffix());
            break;
        case 2:
            return QVariant(target.birthTime().toString());
        }
    }
    return QVariant();

}
