#include "customfilesystemmodel.h"
#include <iostream>


CustomModel::CustomModel():
    icon_provider(new QFileIconProvider)
{
    currentPath = QDir::currentPath();
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
    if(index.isValid()){
        const auto& target = list.at(index.row());
        if(role == Qt::DisplayRole){
            switch(index.column())
            {
            case 0:
                if(target.isDir())
                    return target.fileName();
                else
                    return target.completeBaseName();
            case 1:
                if(!target.isDir())
                    return target.suffix();
                break;
            case 2:
                return target.birthTime().toString();
            }
        }
        else if(role == Qt::DecorationRole && index.column() == 0 )
        {
            return icon_provider->icon(target);
        }

    }
    return QVariant();
}

const QString &CustomModel::getCurrentPath() const
{
    return currentPath;
}

void CustomModel::setCurrentPath(const QString &newCurrentPath)
{
    QDir newDir(newCurrentPath);
    currentPath = newCurrentPath;
    uint newEntriesCount = newDir.count()-2;     //counting without parent and current dirs
    beginRemoveRows(QModelIndex(),0,list.size()-1);
    endRemoveRows();
    int row_count1 = rowCount(QModelIndex());
    beginInsertRows(QModelIndex(), 0, newEntriesCount-1);
    list = newDir.entryInfoList(QDir::NoDotAndDotDot | QDir::AllEntries);
    int row_count2 = rowCount(QModelIndex());
    endInsertRows();
}

const QFileInfoList &CustomModel::getList() const
{
    return list;
}

