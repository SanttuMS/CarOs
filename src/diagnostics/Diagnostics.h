#pragma once
#include <QObject>
#include <QString>


class Vehicle;


class Diagnostics : public QObject{

    Q_OBJECT

    Q_PROPERTY(bool tirePressureFrontLeftLow READ tirePressureFrontLeftLow  NOTIFY diagnosticsChanged)
    Q_PROPERTY(bool tirePressureFrontLeftHigh READ tirePressureFrontLeftHigh  NOTIFY diagnosticsChanged)

    Q_PROPERTY(bool tirePressureFrontRightLow READ tirePressureFrontRightLow  NOTIFY diagnosticsChanged)
    Q_PROPERTY(bool tirePressureFrontRightHigh READ tirePressureFrontRightHigh  NOTIFY diagnosticsChanged)

    Q_PROPERTY(bool tirePressureRearLeftLow READ tirePressureFrontRightLow  NOTIFY diagnosticsChanged)
    Q_PROPERTY(bool tirePressureRearLeftHigh READ tirePressureFrontRightHigh  NOTIFY diagnosticsChanged)

    Q_PROPERTY(bool tirePressureRearRightLow READ tirePressureFrontRightLow  NOTIFY diagnosticsChanged)
    Q_PROPERTY(bool tirePressureRearRightHigh READ tirePressureFrontRightHigh  NOTIFY diagnosticsChanged)


public:



    //Constructor
    explicit Diagnostics(Vehicle *vehicle, QObject *parent = nullptr);

    bool batteryVoltageLow() const;
    int faultCount() const;
    bool motorTemperatureHigh() const;

    bool tirePressureFrontLeftLow() const;
    bool tirePressureFrontLeftHigh() const;

    bool tirePressureFrontRightLow() const;
    bool tirePressureFrontRightHigh() const;

    bool tirePressureRearLeftLow() const;
    bool tirePressureRearLeftHigh() const;

    bool tirePressureRearRightLow() const;
    bool tirePressureRearRightHigh() const;




signals:
    void diagnosticsChanged();




private:
    Vehicle *m_vehicle;
    double m_minTirePressure = 2.6;
    double m_maxTirePressure = 3.3;
    double m_maxMotorTemperature = 110;
    double m_maxCoolantTemperature = 105;
    double m_minBatteryVoltage = 11.5;



};

