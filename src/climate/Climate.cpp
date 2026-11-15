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

void Climate::toggleClimate()
{
    setClimateOn(!m_isClimateOn);
}

bool Climate::isClimateOn() const
{
    return m_isClimateOn;
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

void Climate::setClimateOn(bool isClimateOn)
{
    if (m_isClimateOn == isClimateOn)
        return;

    m_isClimateOn = isClimateOn;
    emit isClimateOnChanged();

    if(m_isClimateOn)
        setClimateMode(ClimateMode::Auto);
}

void Climate::setClimateMode(ClimateMode climateMode)
{
    if(m_climateMode == climateMode)
        return;

    m_climateMode = climateMode;
    emit climateModeChanged();
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

QString Climate::climateModeText() const
{

    switch(m_climateMode){
    case ClimateMode::Auto:
        return "AUTO";

    case ClimateMode::Manual:
        return "MANUAL";

    case ClimateMode::Defrost:
        return "DEFROST";
    }

    return "UNKNOWN";
}
