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

    double coolantTemperature() const;

    double tirePressureFrontLeft() const;
    double tirePressureFrontRight() const;
    double tirePressureRearLeft() const;
    double tirePressureRearRight() const;

    double odometer() const;

    double oilLevel() const;









signals:
    void poweredOnChanged();
    void speedChanged();
    void batteryLevelChanged();
    void driveModeChanged();
    void motorTemperatureChanged();

private:
    bool m_isPoweredOn = false;
    double m_speed = 0.0;
    double m_batteryLevel = 50.0;
    DriveMode m_driveMode = DriveMode::Normal;
    double m_motorTemperature = 20.0;
    double m_tirePressureFrontLeft = 2.4;
    double m_tirePressureFrontRight = 2.4;
    double m_tirePressureRearLeft = 2.3;
    double m_tirePressureRearRight = 2.3;


};
