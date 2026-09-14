#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QTimer>

#include "vehicle/Vehicle.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Vehicle vehicle;
    vehicle.setSpeed(40.0);
    vehicle.setBatteryLevel(72.0);
    vehicle.setDriveMode(Vehicle::DriveMode::Eco);
    vehicle.setTemperature(80.0);
    bool accelerating = true;

    QTimer timer;

    //Connecting timer to a lambda
    QObject::connect(&timer, &QTimer::timeout, [&vehicle, &accelerating]()
    {
        //vehicle.setSpeed(vehicle.speed() + 5.0);
        if(accelerating)
            vehicle.setSpeed(vehicle.speed() + 5.0);
        else
            vehicle.setSpeed(vehicle.speed() - 5.0);

        if(vehicle.speed() >= 120)
            accelerating = false;
        else if(vehicle.speed() <= 0)
            accelerating = true;



    });

    timer.start(1000);

    QObject::connect(&timer, &QTimer::timeout, [&vehicle, &accelerating]()
    {
        if(accelerating)
            vehicle.setBatteryLevel(vehicle.batteryLevel() - 2.0);
        else
            vehicle.setBatteryLevel(vehicle.batteryLevel() + 0.1);

    });



    //GIVE QML cpp OOP "VEHICLE" FOR USE
    engine.rootContext()->setContextProperty("vehicle", &vehicle);

    //Loads qml module from
    engine.loadFromModule("CarOs", "Main");


    //Starts QT event
    return app.exec();

    //QObject::connect(
        //&engine,
        //&QQmlApplicationEngine::objectCreationFailed,
        //&app,
        //[]() { QCoreApplication::exit(-1); },
        //Qt::QueuedConnection);
    //engine.loadFromModule("CarOs", "Main");

    //return QGuiApplication::exec();
}
