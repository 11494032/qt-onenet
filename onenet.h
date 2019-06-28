#ifndef ONENET_H
#define ONENET_H

#include <QString>



class onenet
{
public:
    onenet();
    onenet( QWidget *parent,QString masterKey);
    void getDeviceByImei( QString imei );
private:
    QString masterKey;

};

#endif // ONENET_H
