#include "app_model.h"

MeeShop::app_model::app_model(QObject *parent) :
    QAbstractListModel(parent)
{}

void MeeShop::app_model::addEntry(const info_storage &is) {
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_entries << is;
    endInsertRows();
}

int MeeShop::app_model::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_entries.count();
}

QVariant MeeShop::app_model::data(const QModelIndex &index, int role) const {
    if (index.row() < 0 || index.row() >= m_entries.count())
        return QVariant();

    const info_storage &is = m_entries[index.row()];

    switch (role) {
        case AppNameRole:
            return is.app_name;
            break;
        case AppVerRole:
            return is.app_ver;
            break;
        case AppSizeRole:
            return is.app_size;
            break;
        case AppPkgNameRole:
            return is.app_pkg_name;
            break;
        case AppIconRole:
            return is.app_icon;
            break;

        case RssCountryNameRole:
            return is.rss_country_name;
            break;
        case RssCountryFileRole:
            return is.rss_country_file;
            break;

        case RssFeedNameRole:
            return is.rss_feed_name;
            break;
        case RssFeedUrlRole:
            return is.rss_feed_url;
            break;
        case LetterRole:
            return is.letter;
            break;
        default:
            return QVariant();
    }
}

QHash<int, QByteArray> MeeShop::app_model::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[AppNameRole] = "app_name";
    roles[AppVerRole] = "app_ver";
    roles[AppSizeRole] = "app_size";
    roles[AppPkgNameRole] = "app_pkg_name";
    roles[AppIconRole] = "app_icon";

    roles[RssCountryNameRole] = "rss_country_name";
    roles[RssCountryFileRole] = "rss_country_file";

    roles[RssFeedNameRole] = "rss_feed_name";
    roles[RssFeedUrlRole] = "rss_feed_url";

    roles[LetterRole] = "letter";
    return roles;
}
