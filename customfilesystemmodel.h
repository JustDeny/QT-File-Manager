#ifndef CUSTOMFILESYSTEMMODEL_H
#define CUSTOMFILESYSTEMMODEL_H

#include <QFileSystemModel>
#include <QFileIconProvider>
#include <QStandardItemModel>

class CustomModel: public QAbstractTableModel
{
    Q_OBJECT;
public:
    CustomModel();
    int rowCount(const QModelIndex &parent)const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    const QString &getCurrentPath() const;
    void setCurrentPath(const QString &newCurrentPath);
    //bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    //bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    //bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
private:
    QFileInfoList list;
    QString currentPath;
    QFileIconProvider* icon_provider;
};

#endif // CUSTOMFILESYSTEMMODEL_H
