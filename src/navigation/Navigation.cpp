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