#pragma once
#include <QObject>
#include <QString>
#include <QDebug>

class Climate : public QObject{

    Q_OBJECT

    Q_PROPERTY(double cabinTemperature READ cabinTemperature WRITE setCabinTemperature NOTIFY cabinTemperatureChanged)


public:


    explicit Climate(QObject *parent = nullptr);

    double cabinTemperature() const;
    void setCabinTemperature(double cabinTemperature);






signals:
    void cabinTemperatureChanged();


private:
    double m_cabinTemperature = 20;

};
