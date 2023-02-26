#ifndef HEADERMODEL_H
#define HEADERMODEL_H

#include <QIdentityProxyModel>

class HeaderModel : public QIdentityProxyModel
{
public:
    HeaderModel();
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
};

#endif // HEADERMODEL_H
