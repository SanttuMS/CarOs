#include "Navigation.h"

Navigation::Navigation(QObject *parent)
    :QObject(parent)
{
}

double Navigation::marker() const
{
    return m_marker;
}

double Navigation::vehicleLatitude() const
{
    return m_vehicleLatitude;
}

double Navigation::vehicleLongitude() const
{
    return m_vehicleLongitude;
}

void Navigation::setMarker(double marker)
{
    if(m_marker == marker)
        return;

    m_marker = marker;
    emit markerChanged();

}

void Navigation::setNav(bool isNavActive)
{
    if (m_isNavActive == isNavActive)
        return;

    m_isNavActive = isNavActive;
    emit isNavActiveChanged();
}

void Navigation::setDestination(const QString &destination)
{
    if(m_destination == destination)
        return;

    if(m_isNavActive == false)
         setNav(true);

    m_destination = destination;

    emit destinationChanged();

}


void Navigation::setEtaTarget(double etaTarget)
{
    if(m_etaTarget == etaTarget)
        return;

    m_etaTarget = etaTarget;
    emit etaTargetChanged();
}

void Navigation::setVehicleLatitude(double vehicleLatitude)
{
    if(m_vehicleLatitude == vehicleLatitude)
        return;

    m_vehicleLatitude = vehicleLatitude;
    emit vehicleLatitudeChanged();
}

void Navigation::setVehicleLongitude(double vehicleLongitude)
{
    if(m_vehicleLongitude == vehicleLongitude)
        return;

    m_vehicleLongitude = vehicleLongitude;
    emit vehicleLongitudeChanged();
}