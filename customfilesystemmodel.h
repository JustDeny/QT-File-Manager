#ifndef CUSTOMFILESYSTEMMODEL_H
#define CUSTOMFILESYSTEMMODEL_H


#include <QFileIconProvider>
#include <QStandardItemModel>

//enum class containing measures in bytes
enum class Measures:int64_t
{
    KILOBYTE = 1024,
    MEGABYTE = 1048576,
    GIGABYTE = 1073741824,
    TERABYTE = 1099511627776

};

bool operator>=(const float lhs, const Measures rhs);
float& operator/=(float& lhs, const Measures rhs);


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
    const QFileInfoList &getList() const;

private:
    QFileInfoList list;
    QString currentPath;
    QFileIconProvider* icon_provider;
};

#endif // CUSTOMFILESYSTEMMODEL_H
