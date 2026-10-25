#pragma once
#include <QObject>
#include <QString>
#include <QDebug>

class Climate : public QObject{


public:


    explicit Climate(QObject *parent = nullptr);

    double cabinTemperature() const;
    double setCabintemperature() const;






signals:
    void cabinTemperatureChanged();


private:
    double m_cabinTemperature = 20;

};
