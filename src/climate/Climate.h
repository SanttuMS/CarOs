#pragma once
#include <QObject>
#include <QString>
#include <QDebug>

class Climate : public QObject{

    Q_OBJECT

    Q_PROPERTY(double cabinTemperature READ cabinTemperature WRITE setCabinTemperature NOTIFY cabinTemperatureChanged)
    Q_PROPERTY(bool seatHeat READ seatHeat WRITE setSeatHeat NOTIFY seatHeatChanged)
    Q_PROPERTY(double fanSpeed READ fanSpeed WRITE setFanSpeed NOTIFY fanSpeedChanged)
    Q_PROPERTY(bool isClimateOn READ isClimateOn WRITE setClimateOn NOTIFY isClimateOnChanged)
    Q_PROPERTY(QString climateModeText READ climateModeText  NOTIFY climateModeChanged)


public:

    enum class ClimateMode{

        Auto,
        Manual,
        Defrost
    };

    Q_ENUM(ClimateMode)

    Q_INVOKABLE void toggleClimate();
    Q_INVOKABLE void setAuto();
    Q_INVOKABLE void setManual();
    Q_INVOKABLE void setDefrost();



    explicit Climate(QObject *parent = nullptr);

    double cabinTemperature() const;
    void setCabinTemperature(double cabinTemperature);

    bool seatHeat() const;
    void setSeatHeat(bool seatHeat);

    int fanSpeed() const;
    void setFanSpeed(double fanSpeed);

    bool isClimateOn() const;
    void setClimateOn(bool isClimateOn);

    ClimateMode climateMode() const;
    void setClimateMode(ClimateMode climateMode);

    QString climateModeText() const;

signals:
    void cabinTemperatureChanged();
    void seatHeatChanged();
    void climateModeChanged();
    void fanSpeedChanged();
    void isClimateOnChanged();



private:
    double m_cabinTemperature = 20;
    bool m_seatHeat = false;
    int m_fanSpeed = 5;
    bool m_isClimateOn = false;
    ClimateMode m_climateMode = ClimateMode::Auto;

};
