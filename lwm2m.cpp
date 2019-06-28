#include "lwm2m.h"
#include <QMainWindow>
#include <QNetworkReply>
LWM2M::LWM2M()
{

}

LWM2M::LWM2M( QByteArray masterKey)
{
    this->masterKey = masterKey;
}


void LWM2M::getDeviceByImei( QObject *object, QString imei)
{
    this->imei = imei;
    m_manager = new QNetworkAccessManager( object );

    QNetworkRequest request;
    request.setUrl(QUrl("http://api.heclouds.com/devices/getbyimei?imei="+imei));
    request.setRawHeader("api-key",this->masterKey);
    //get
    m_manager->get(request);
/*
    QByteArray postData;
    QString str = "imei=861931045659293";
    postData.append(str);

    //post
    QNetworkReply* reply = m_manager->post(request, postData);
    */
    QObject::connect(m_manager, &QNetworkAccessManager::finished, [](QNetworkReply* reply){
             if(reply->error() != QNetworkReply::NoError)
             {
                 qDebug() << "Error:" << reply->errorString();
                 return;
             }
             QByteArray buf = reply->readAll();
             qDebug() << "OK:"<< buf;
     });
}

