cmake_minimum_required(VERSION 3.16)

project(EnviarApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick DBus)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_resources(RESOURCES qml.qrc)

qt_add_executable(appEnviarApp
    main.cpp
    ${RESOURCES}
)

qt_add_qml_module(appEnviarApp
    URI EnviarApp
    VERSION 1.0
    QML_FILES
        Main.qml
        QML_FILES Principal.qml
        RESOURCES qml.qrc
        QML_FILES AbreArquivo.qml
        SOURCES carregaarquivo.h carregaarquivo.cpp
        QML_FILES TransmitirComando.qml
        SOURCES enviarcomando.h enviarcomando.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appEnviarApp PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appEnviarApp
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appEnviarApp
    PRIVATE
    Qt6::Quick
    Qt6::DBus
)

include(GNUInstallDirs)
install(TARGETS appEnviarApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
