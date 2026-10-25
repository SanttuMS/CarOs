#pragma once
#include <QObject>

class Navigation : public QObject
{
    //QOBJECTS & PROPERTYS


public:


    explicit Navigation(QObject *parent = nullptr);

    //Setters & Getters
    double marker() const;
    double setMarker(double marker) const;

    double vehicleLatitude() const;
    double vehicleLongitude() const;

    double setVehicleLatitude(double vehicleLatitude) const;
    double setVehicleLongitude(double vehicleLongitude) const;


signals:
    void markerChanged();



private:
    double m_marker;
    double m_vehicleLatitude = 60.169;
    double m_vehicleLongitude = 24.93;

};