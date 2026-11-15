#pragma once
#include <QObject>
#include <QString>

class Navigation : public QObject
{
    //QOBJECTS & PROPERTYS
    Q_OBJECT

    Q_PROPERTY(double marker READ marker WRITE setMarker NOTIFY markerChanged)
    Q_PROPERTY(double vehicleLatitude READ vehicleLatitude WRITE setVehicleLatitude NOTIFY vehicleLatitudeChanged)
    Q_PROPERTY(double vehicleLongitude READ vehicleLongitude WRITE setVehicleLongitude NOTIFY vehicleLongitudeChanged)
    Q_PROPERTY(QString destination READ destination WRITE setDestination NOTIFY destinationChanged)
    Q_PROPERTY(double etaTarget READ etaTarget WRITE setEtaTarget NOTIFY etaTargetChanged)
    Q_PROPERTY(bool isNavActive READ isNavActive WRITE setNav NOTIFY isNavActiveChanged)



public:
    //Macro that exposes public method to qml

    Q_INVOKABLE void toggleNavigation();

    //Constructor
    explicit Navigation(QObject *parent = nullptr);

    //Setters & Getters
    double marker() const;
    void setMarker(double marker);

    QString destination() const;
    void setDestination(const QString &destination);

    bool isNavActive() const;
    void setNav(bool isNavActive);

    double etaTarget() const;
    void setEtaTarget(double etaTarget);


    double vehicleLatitude() const;
    double vehicleLongitude() const;

    void setVehicleLatitude(double vehicleLatitude);
    void setVehicleLongitude(double vehicleLongitude);



signals:
    void markerChanged();
    void destinationChanged();
    void isNavActiveChanged();
    void etaTargetChanged();
    void vehicleLatitudeChanged();
    void vehicleLongitudeChanged();

private:
    double m_marker = 0.0;
    double m_etaTarget = 0.0;
    double m_vehicleLatitude = 60.169;
    double m_vehicleLongitude = 24.93;
    QString m_destination;
    bool m_isNavActive = false;
};