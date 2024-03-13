#ifndef MEESHOPMODEL_H
#define MEESHOPMODEL_H
#include <QAbstractListModel>
#include "info_storage.h"
#include <QList>
#include <algorithm>
#include <QDebug>
#include <QSortFilterProxyModel>


namespace MeeShop {
class MeeShopApplicationModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum EntryRoles {
        AppNameRole = Qt::UserRole + 1,
        AppVerRole,
        AppSizeRole,
        AppPkgNameRole,
        AppIconRole,

        RssCountryNameRole,
        RssCountryFileRole,

        RssFeedNameRole,
        RssFeedUrlRole,

        LetterRole
    };

    MeeShopApplicationModel(QObject *parent = 0);

    void addEntry(const MeeShop::info_storage &is);

    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

    QList<MeeShop::info_storage> get_list() {return m_entries; m_entries.clear();}
    void set_sorted_list(QList<MeeShop::info_storage> new_list) {
        beginInsertRows(QModelIndex(), rowCount(), rowCount());
        m_entries = new_list;
        endInsertRows();
    }

private:
    QList<MeeShop::info_storage> m_entries;
};
}

Q_DECLARE_METATYPE(MeeShop::MeeShopApplicationModel*)
#endif // MEESHOPMODEL_H


