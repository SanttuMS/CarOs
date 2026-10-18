#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QTimer>


#include "vehicle/Vehicle.h"
#include "media/Media.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    Vehicle vehicle;
    Media   media;

    QQmlApplicationEngine engine;

    vehicle.setSpeed(40.0);
    vehicle.setBatteryLevel(72.0);
    vehicle.setDriveMode(Vehicle::DriveMode::Normal);
    vehicle.setTemperature(80.0);
    bool accelerating = true;


    QTimer timer;

    //Connecting timer to a lambda + logic for vehicle speed
    QObject::connect(&timer, &QTimer::timeout, [&vehicle, &accelerating]()
    {
        //vehicle.setSpeed(vehicle.speed() + 5.0);
        if(accelerating && vehicle.driveMode() == Vehicle::DriveMode::Eco)
            vehicle.setSpeed(vehicle.speed() + 2.0);
        else if(accelerating && vehicle.driveMode() == Vehicle::DriveMode::Normal)
            vehicle.setSpeed(vehicle.speed() + 4.0);
        else if(accelerating && vehicle.driveMode() == Vehicle::DriveMode::Sport)
            vehicle.setSpeed(vehicle.speed() + 8.0);
        else
            vehicle.setSpeed(vehicle.speed() - 5.0);

        if(vehicle.speed() >= 120)
            accelerating = false;
        else if(vehicle.speed() <= 0)
            accelerating = true;



    });

    //Debug for drivemode selected
    //qDebug() << "Drive mode:" << static_cast<int>(vehicle.driveMode());

    //Setting timer and logic for drain battery level according to drivemode
    QObject::connect(&timer, &QTimer::timeout, [&vehicle, &accelerating]()
    {
        if(accelerating && vehicle.driveMode() == Vehicle::DriveMode::Eco)
            vehicle.setBatteryLevel(vehicle.batteryLevel() - 0.6);

        else if(accelerating && vehicle.driveMode() == Vehicle::DriveMode::Normal)
            vehicle.setBatteryLevel(vehicle.batteryLevel() - 0.8);

        else if(accelerating && vehicle.driveMode() == Vehicle::DriveMode::Sport)
            vehicle.setBatteryLevel(vehicle.batteryLevel() - 1.0);

        else
            vehicle.setBatteryLevel(vehicle.batteryLevel() + 0.2);

    });

    timer.start(1000);





    //GIVE QML  OOP "VEHICLE" FOR USE
    engine.rootContext()->setContextProperty("vehicle", &vehicle);

    //Loads qml module from
    engine.loadFromModule("CarOs", "Main");


    //Starts QT event
    return app.exec();


}
