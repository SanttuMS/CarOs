#pragma once
#include <QObject>

class Navigation : public QObject
{
    //QOBJECTS & PROPERTYS
    Q_OBJECT

    Q_PROPERTY(double marker READ marker WRITE setMarker NOTIFY markerChanged)


public:


    explicit Navigation(QObject *parent = nullptr);

    //Setters & Getters
    double marker() const;
    void setMarker(double marker);

    double vehicleLatitude() const;
    double vehicleLongitude() const;

    void setVehicleLatitude(double vehicleLatitude);
    void setVehicleLongitude(double vehicleLongitude);


signals:
    void markerChanged();



private:
    double m_marker;
    double m_vehicleLatitude = 60.169;
    double m_vehicleLongitude = 24.93;

};