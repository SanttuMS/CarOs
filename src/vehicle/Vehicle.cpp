#include "Vehicle.h"

Vehicle::Vehicle(QObject *parent)
    : QObject(parent)
{
}

double Vehicle::speed() const
{
    return m_speed;
}

double Vehicle::batteryLevel() const
{
    return m_batteryLevel;
}

double Vehicle::temperature() const
{
    return m_temperature;
}

void Vehicle::setTemperature(double temperature)
{
    if(m_temperature == temperature)
        return;

    m_temperature = temperature;
    emit temperatureChanged();
}

void Vehicle::setSpeed(double speed)
{
    if(m_speed == speed)
        return;

    m_speed = speed;
    emit speedChanged();
}

void Vehicle::setBatteryLevel(double batteryLevel)
{
    if(batteryLevel <= 0)
        batteryLevel = 0;
    else if(batteryLevel >= 100)
        batteryLevel = 100;


    if(m_batteryLevel == batteryLevel)
        return;

    m_batteryLevel = batteryLevel;
    emit batteryLevelChanged();
}

Vehicle::DriveMode Vehicle::driveMode() const
{
    return m_driveMode;
}

void Vehicle::setDriveMode(DriveMode driveMode)
{
    if(m_driveMode == driveMode)
        return;

    m_driveMode = driveMode;
    emit driveModeChanged();
}

void Vehicle::setEcoMode()
{
    setDriveMode(DriveMode::Eco);
}

void Vehicle::setNormalMode()
{
    setDriveMode(DriveMode::Normal);
}

void Vehicle::setSportMode()
{
    setDriveMode(DriveMode::Sport);
}

QString Vehicle::driveModeText() const
{

    switch(m_driveMode){
    case DriveMode::Eco:
        return "ECO";

    case DriveMode::Normal:
        return "NORMAL";

    case DriveMode::Sport:
        return "SPORT";
    }

    return "UNKNOWN";
}

