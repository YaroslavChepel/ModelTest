#ifndef APP_MODEL_H
#define APP_MODEL_H

#include <QObject>
#include "info_storage.h"
#include <QAbstractListModel>
#include <QVariant>
#include <QDebug>

namespace MeeShop {
class app_model : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit app_model(QObject *parent = 0);

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

    void addEntry(const info_storage &is);
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;

private:
    QList<info_storage> m_entries;

};
}
Q_DECLARE_METATYPE(MeeShop::app_model*)
#endif // APPS_MODEL_H

