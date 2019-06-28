#ifndef LWM2M_H
#define LWM2M_H

#include <QMainWindow>
#include <QNetworkAccessManager>

class LWM2M
{
public:
    LWM2M();
    LWM2M(QByteArray );
    void getDeviceByImei(QObject *object,QString);
private Q_SLOTS:
    void finishedSlot(QNetworkReply *reply);
private:
    QByteArray masterKey;
    QString imei;
    QNetworkAccessManager *m_manager;
};

#endif // LWM2M_H
