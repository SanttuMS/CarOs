#pragma once
#include <QObject>
#include <QString>
#include <QDateTime>
#include <QDebug>

class Vehicle : public QObject
{


    Q_OBJECT

    //Tells QT that these objects have properties
    Q_PROPERTY(bool isPoweredOn READ isPoweredOn WRITE setPoweredOn NOTIFY poweredOnChanged)
    Q_PROPERTY(double speed READ speed WRITE setSpeed NOTIFY speedChanged)
    Q_PROPERTY(double batteryLevel READ batteryLevel WRITE setBatteryLevel NOTIFY batteryLevelChanged)
    Q_PROPERTY(DriveMode driveMode READ driveMode WRITE setDriveMode NOTIFY driveModeChanged)
    Q_PROPERTY(QString driveModeText READ driveModeText NOTIFY driveModeChanged)
    Q_PROPERTY(double motorTemperature READ motorTemperature WRITE setTemperature NOTIFY motorTemperatureChanged)


public:

    enum class DriveMode
    {

        Eco,
        Normal,
        Sport
    };
    Q_ENUM(DriveMode)



    //Macro that exposes public method to qml
    Q_INVOKABLE void togglePower();
    Q_INVOKABLE void setEcoMode();
    Q_INVOKABLE void setNormalMode();
    Q_INVOKABLE void setSportMode();

    //Constructor
    explicit Vehicle(QObject *parent = nullptr);




    //Getters&setters

    bool isPoweredOn() const;
    void setPoweredOn(bool isPoweredOn);

    double speed() const;
    void setSpeed(double speed);

    double batteryLevel() const;
    void setBatteryLevel(double batteryLevel);

    double motorTemperature() const;
    void setTemperature(double temperature);

    DriveMode driveMode() const;
    void setDriveMode(DriveMode driveMode);

    //Property/Function that converts enum into text in QT
    QString driveModeText() const;

    double batteryVoltage() const;
    void setBatteryVoltage(double batteryVoltage);

    double coolantLevel() const;
    void setCoolantLevel(double coolantLevel);

    double coolantTemperature() const;
    void setCoolateTemperature(double coolantTemperature);

    double tirePressureFrontLeft() const;
    void setTirePressureFrontLeft(double tirePressureFrontLeft);

    double tirePressureFrontRight() const;
    void setTirePressureFrontRight(double tirePressureFrontRight);

    double tirePressureRearLeft() const;
    void setTirePressureRearLeft(double tirePressureRearLeft);

    double tirePressureRearRight() const;
    void setTirePressureRearRight(double tirePressureRearRight);

    double odometer() const;
    void setOdometer(double odometer);

    double oilLevel() const;
    void setOilLevel(double oilLevel);









signals:
    void poweredOnChanged();
    void speedChanged();
    void batteryLevelChanged();
    void driveModeChanged();
    void motorTemperatureChanged();
    void batteryVoltageChanged();
    void coolantTemperatureChanged();
    void tirePressureFrontLeftChanged();
    void tirePressureFrontRightChanged();
    void tirePressureRearLeftChanged();
    void tirePressureRearRightChanged();
    void odometerChanged();
    void oilLevelChanged();
    void coolantLevelChanged();

private:
    bool m_isPoweredOn = false;
    double m_odometer = 20000;
    double m_oilLevel = 5;
    double m_batteryLevel = 50.0;
    double m_batteryVoltage = 11.8;
    double m_coolantLevel = 10;
    double m_coolantTemperature = 37;
    double m_speed = 0.0;
    DriveMode m_driveMode = DriveMode::Normal;
    double m_motorTemperature = 20.0;
    double m_tirePressureFrontLeft = 2.4;
    double m_tirePressureFrontRight = 2.4;
    double m_tirePressureRearLeft = 2.3;
    double m_tirePressureRearRight = 2.3;


};
