#include "src/diagnostics/Diagnostics.h"
#include "src/vehicle/Vehicle.h"

Diagnostics::Diagnostics(Vehicle *vehicle, QObject *parent)
    :QObject(parent),
    m_vehicle(vehicle)
{
    connect(m_vehicle, &Vehicle::tirePressureFrontLeftChanged,
            this, &Diagnostics::diagnosticsChanged);

    connect(m_vehicle, &Vehicle::tirePressureFrontRightChanged,
            this, &Diagnostics::diagnosticsChanged);

    connect(m_vehicle, &Vehicle::tirePressureRearLeftChanged,
            this, &Diagnostics::diagnosticsChanged);

    connect(m_vehicle, &Vehicle::tirePressureRearRightChanged,
            this, &Diagnostics::diagnosticsChanged);
}

