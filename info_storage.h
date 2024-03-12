#ifndef INFO_STORAGE_H
#define INFO_STORAGE_H

#include <QString>
#include <qdeclarative.h>
namespace MeeShop {
struct info_storage {
    QString app_name;
    QString app_ver;
    QString app_size;
    QString app_pkg_name;
    QString app_icon;

    QString rss_country_name;
    QString rss_country_file;

    QString rss_feed_name;
    QString rss_feed_url;

    QString letter;
};
}
Q_DECLARE_METATYPE(MeeShop::info_storage)

#endif // INFO_STORAGE_H
