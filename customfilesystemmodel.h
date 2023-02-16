#ifndef CUSTOMFILESYSTEMMODEL_H
#define CUSTOMFILESYSTEMMODEL_H

#include <QFileSystemModel>
#include <QFileIconProvider>

class CustomModel: public QAbstractTableModel
{
public:
    CustomModel();
    int rowCount(const QModelIndex &parent)const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
private:
    QFileInfoList list;
    QString currentPath;
    QFileIconProvider* icon_provider;
};

#endif // CUSTOMFILESYSTEMMODEL_H
