CarOS is a C++20 and Qt 6/QML automotive dashboard and infotainment simulation project.

The goal of the project is to practice modern C++, Qt/QML, software architecture, and automotive-style application development.



v0.1 Dashboard

The first milestone focuses on a working vehicle dashboard with a C++ backend connected to a QML user interface.

Features

- Vehicle speed simulation
- Battery level monitoring
- Battery drain while accelerating
- Regenerative braking simulation while decelerating
- Drive modes:
  - ECO
  - NORMAL
  - SPORT
- Different acceleration and battery consumption behavior depending on drive mode
- Vehicle temperature display
- Current date and time
- Interactive drive mode selection
- Active drive mode highlighting
- Light and dark UI modes
- Automatic QML updates using Qt signals and properties

Technologies

- C++20
- Qt 6
- QML / Qt Quick
- CMake
- Clang
- Git / GitHub

Architecture

The project separates vehicle logic from the user interface.

The `Vehicle` C++ class manages vehicle state and simulation logic, while QML is responsible for displaying the dashboard and handling user interaction.

Communication between C++ and QML is implemented using:

- `QObject`
- `Q_PROPERTY`
- signals
- setters and getters
- `Q_INVOKABLE` functions


Future versions may include:

- Media player
- Climate controls
- Navigation simulation
- Vehicle diagnostics
- CAN bus simulation
- ECU simulation
- Unit tests
- Multithreading
- Improved UI and animations


Version 0.1 represents the first functional dashboard prototype.
