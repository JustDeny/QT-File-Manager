#include "headermodel.h"

HeaderModel::HeaderModel()
{
}

QVariant HeaderModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(orientation == Qt::Horizontal)
    {
        if(role == Qt::DisplayRole)
        {
            switch (section) {
            case 0: return tr("Name");  break;
            case 1: return tr("Ext");  break;
            case 2: return tr("Date");  break;
            case 3: return tr("Size");  break;
            }
        }
    }
    return QVariant();
}
