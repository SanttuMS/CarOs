#include "Climate.h"

Climate::Climate(QObject *parent)
    :QObject(parent)
{
}

double Climate::cabinTemperature() const
{
    return m_cabinTemperature;
}

void Climate::setCabinTemperature(double cabinTemperature)
{
    if(m_cabinTemperature == cabinTemperature)
        return;

    m_cabinTemperature = cabinTemperature;
    emit cabinTemperatureChanged();
}

