#ifndef INFORMATION_PROCESSOR_H
#define INFORMATION_PROCESSOR_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QScopedPointer>
#include <QSharedPointer>
#include <QXmlStreamReader>
#include "info_storage.h"
#include <app_model.h>
#include <QList>
#include <algorithm>
#include <QDebug>

namespace MeeShop {
    class information_processor : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QVariant model READ get_final_list NOTIFY model_changed)
    public:
        explicit information_processor(QObject *parent = 0) : QObject(parent), final_model(new app_model(this)) {}

        Q_INVOKABLE void load_applications(QString xml);
        Q_INVOKABLE void load_rss_feeds(QString xml);

        QVariant get_final_list() {return QVariant::fromValue(final_model);}
    private slots:
        void parse_xml(QNetworkReply* reply);
        void process_reply();

    signals:
        void information_loading_finished();
        void model_changed();

        void loading_error(QString error);
        void parsing_error(QString error);
    private:
        QNetworkAccessManager manager;
        QScopedPointer<QNetworkReply> reply;
        app_model *final_model;
        QXmlStreamReader xml_reader;
    };
}


#endif // INFORMATION_PROCESSOR_H
