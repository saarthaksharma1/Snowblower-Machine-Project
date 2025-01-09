project(MachineLib)

set(SOURCE_FILES
        pch.h
        IMachineSystem.h
        MachineSystemFactory.cpp MachineSystemFactory.h
        MachineStandin.cpp MachineStandin.h
        Polygon.cpp Polygon.h
        MachineDialog.cpp MachineDialog.h include/machine-api.h
        MachineSystemStandin.cpp
        MachineSystemStandin.h
        Const.cpp
        Const.h
        Motor.cpp
        Motor.h
        Shape.cpp
        Shape.h
        MachineSystem.cpp
        MachineSystem.h
        Machine.cpp
        Machine.h
        MachineCFactory.cpp
        MachineCFactory.h
        MachineFactory1.cpp
        MachineFactory1.h
        Component.cpp
        Component.h
        MachineFactory2.cpp
        MachineFactory2.h
        RotationSource.cpp
        RotationSource.h
        RotationSink.cpp
        RotationSink.h
        Pulley.cpp
        Pulley.h
        SnowBlower.cpp
        SnowBlower.h
        Snow.cpp
        Snow.h
)

# Removed:
# Motor.cpp Motor.h Pulley.cpp Pulley.h

find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)
include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})
