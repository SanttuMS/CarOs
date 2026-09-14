#pragma once
#include <QObject>
#include <QString>

class Vehicle : public QObject
{

    Q_OBJECT

    //Tells QT that these objects have properties
    Q_PROPERTY(double speed READ speed WRITE setSpeed NOTIFY speedChanged)
    Q_PROPERTY(double batteryLevel READ batteryLevel WRITE setBatteryLevel NOTIFY batteryLevelChanged)
    Q_PROPERTY(DriveMode driveMode READ driveMode WRITE setDriveMode NOTIFY driveModeChanged)
    Q_PROPERTY(QString driveModeText READ driveModeText NOTIFY driveModeChanged)
    Q_PROPERTY(double temperature READ temperature WRITE setTemperature NOTIFY temperatureChanged)


public:

    enum class DriveMode
    {

        Eco,
        Normal,
        Sport
    };
    Q_ENUM(DriveMode)

    //Constructor
    explicit Vehicle(QObject *parent = nullptr);




    //Variables
    double speed() const;
    void setSpeed(double speed);

    double batteryLevel() const;
    void setBatteryLevel(double batteryLevel);

    double temperature() const;
    void setTemperature(double temp);

    DriveMode driveMode() const;
    void setDriveMode(DriveMode driveMode);

    //Property/Function that converts enum into text in QT
    QString driveModeText() const;





signals:
    void speedChanged();
    void batteryLevelChanged();
    void driveModeChanged();
    void temperatureChanged();

private:
    double m_speed = 0.0;
    double m_batteryLevel = 50.0;
    DriveMode m_driveMode = DriveMode::Eco;
    double m_temperature = 20.0;

};
