#include "Navigation.h"

Navigation::Navigation(QObject *parent)
    :QObject(parent)
{
}

double Navigation::marker() const
{
    return m_marker;
}

void Navigation::setMarker(double marker)
{
    if(m_marker == marker)
        return;

    m_marker = marker;
    emit markerChanged();

}


double Navigation::vehicleLatitude() const
{
    return m_vehicleLatitude;
}

double Navigation::vehicleLongitude() const
{
    return m_vehicleLongitude;
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

QString Navigation::destination() const
{
    return m_destination;
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


double Navigation::etaTarget() const
{
    return m_etaTarget;
}

void Navigation::setEtaTarget(double etaTarget)
{
    if(m_etaTarget == etaTarget)
        return;

    m_etaTarget = etaTarget;
    emit etaTargetChanged();
}

bool Navigation::isNavActive() const
{
    return m_isNavActive;
}

void Navigation::toggleNavigation()
{
    setNav(!m_isNavActive);
}

void Navigation::setNav(bool isNavActive)
{
    if(m_isNavActive == isNavActive)
        return;

    m_isNavActive = isNavActive;
    emit isNavActiveChanged();
}
