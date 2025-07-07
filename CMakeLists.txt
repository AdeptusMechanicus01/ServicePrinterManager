cmake_minimum_required(VERSION 3.16)
project(ServicePrinterManager VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)  # Упрощаем: используем только Qt6
set(PROJECT_SOURCES
    main.cpp
    widget.cpp
    widget.h
    widget.ui
    repairrecord.h
    repairrecord.cpp
    resources.qrc
)
qt_add_executable(ServicePrinterManager
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)

target_link_libraries(ServicePrinterManager PRIVATE Qt6::Widgets)

# УБИРАЕМ ЛИШНИЕ УСЛОВИЯ ДЛЯ Qt5/ANDROID/IOS
set_target_properties(ServicePrinterManager PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
    MACOSX_BUNDLE_GUI_IDENTIFIER "com.example.ServicePrinterManager"
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)
qt_finalize_executable(ServicePrinterManager)
