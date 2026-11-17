#include "Vehicle.h"

Vehicle::Vehicle(QObject *parent)
    : QObject(parent)
{
}

bool Vehicle::isPoweredOn() const
{
    return m_isPoweredOn;
}

void Vehicle::setPoweredOn(bool poweredOn)
{
    if (m_isPoweredOn == poweredOn)
        return;

    m_isPoweredOn = poweredOn;
    emit poweredOnChanged();
}

void Vehicle::togglePower()
{
    setPoweredOn(!m_isPoweredOn);
}

double Vehicle::speed() const
{
    return m_speed;
}

void Vehicle::setSpeed(double speed)
{
    if(m_speed == speed)
        return;

    m_speed = speed;
    emit speedChanged();
}

double Vehicle::odometer() const
{
    return m_odometer;
}

void Vehicle::setOdometer(double odometer)
{
    if(m_odometer == odometer)
        return;

    m_odometer = odometer;
    emit odometerChanged();
}

double Vehicle::batteryLevel() const
{
    return m_batteryLevel;
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

double Vehicle::batteryVoltage() const
{
    return m_batteryVoltage;
}

void Vehicle::setBatteryVoltage(double batteryVoltage)
{
    if(m_batteryVoltage == batteryVoltage)
        return;

    m_batteryVoltage = batteryVoltage;
    emit batteryVoltageChanged();
}

double Vehicle::motorTemperature() const
{
    return m_motorTemperature;
}

void Vehicle::setMotorTemperature(double motorTemperature)
{
    if(m_motorTemperature == motorTemperature)
        return;

    m_motorTemperature = motorTemperature;
    emit motorTemperatureChanged();
}

double Vehicle::coolantLevel() const
{
    return m_coolantLevel;
}

void Vehicle::setCoolantLevel(double coolantLevel)
{
    if(m_coolantLevel == coolantLevel)
        return;

    m_coolantLevel = coolantLevel;
    emit coolantLevelChanged();
}

double Vehicle::coolantTemperature() const
{
    return m_coolantTemperature;
}

void Vehicle::setCoolateTemperature(double coolantTemperature)
{
    if(m_coolantTemperature == coolantTemperature)
        return;

    m_coolantTemperature = coolantTemperature;
    emit coolantTemperatureChanged();
}

double Vehicle::oilLevel() const
{
    return m_oilLevel;
}

void Vehicle::setOilLevel(double oilLevel)
{
    if(m_oilLevel == oilLevel)
        return;

    m_oilLevel = oilLevel;
    emit oilLevelChanged();
}

double Vehicle::tirePressureFrontLeft() const
{
    return m_tirePressureFrontLeft;
}

void Vehicle::setTirePressureFrontLeft(double tirePressureFrontLeft)
{
    if(m_tirePressureFrontLeft == tirePressureFrontLeft)
        return;

    m_tirePressureFrontLeft = tirePressureFrontLeft;
    emit tirePressureFrontLeftChanged();
}

double Vehicle::tirePressureFrontRight() const
{
    return m_tirePressureFrontRight;
}

void Vehicle::setTirePressureFrontRight(double tirePressureFrontRight)
{
    if(m_tirePressureFrontRight == tirePressureFrontRight)
        return;

    m_tirePressureFrontRight = tirePressureFrontRight;
    emit tirePressureFrontRightChanged();
}

double Vehicle::tirePressureRearLeft() const
{
    return m_tirePressureRearLeft;
}

void Vehicle::setTirePressureRearLeft(double tirePressureRearLeft)
{
    if(m_tirePressureRearLeft == tirePressureRearLeft)
        return;

    m_tirePressureRearLeft = tirePressureRearLeft;
    emit tirePressureRearLeftChanged();
}

double Vehicle::tirePressureRearRight() const
{
    return m_tirePressureRearRight;
}

void Vehicle::setTirePressureRearRight(double tirePressureRearRight)
{
    if(m_tirePressureRearRight == tirePressureRearRight)
        return;

    m_tirePressureRearRight = tirePressureRearRight;
    emit tirePressureRearRightChanged();
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

