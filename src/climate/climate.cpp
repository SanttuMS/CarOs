#include "Climate.h"

Climate::Climate(QObject *parent)
    :QObject(parent)
{
}

int Climate::fanSpeed() const
{
    return m_fanSpeed;
}

bool Climate::seatHeat() const
{
    return m_seatHeat;
}

double Climate::cabinTemperature() const
{
    return m_cabinTemperature;
}

void Climate::climateOn()
{
    setClimateOn(!m_isClimateOn);
}

void Climate::setCabinTemperature(double cabinTemperature)
{
    if(m_cabinTemperature == cabinTemperature)
        return;

    m_cabinTemperature = cabinTemperature;
    emit cabinTemperatureChanged();
}

void Climate::setFanSpeed(double fanSpeed)
{
    if(m_fanSpeed == fanSpeed)
        return;
    m_fanSpeed = fanSpeed;
    emit fanSpeedChanged();
}

void Climate::setSeatHeat(bool seatHeat)
{
    if(m_seatHeat == seatHeat)
        return;

    m_seatHeat = seatHeat;
    emit seatHeatChanged();
}

void Climate::setClimateMode(ClimateMode climateMode)
{
    if(m_driveMode == driveMode)
        return;

    m_driveMode = driveMode;
    emit driveModeChanged();
}

void Climate::setAuto()
{
    setClimateMode(ClimateMode::Auto);
}

void Climate::setManual()
{
    setClimateMode(ClimateMode::Manual);
}

void Climate::setDefrost()
{
    setClimateMode(ClimateMode::Defrost);
}