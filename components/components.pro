greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT               += 	core gui
TEMPLATE          = 	lib
TARGET            =     components
DEFINES          +=     QT_DEPRECATED_WARNINGS
DESTDIR          +=     libs
MOC_DIR           =     temp/moc
UI_DIR            =     temp/uic
RCC_DIR           =     temp/rcc
OBJECTS_DIR       =     temp/objs
CONFIG           +=     staticlib
CONFIG           +=     warn_on

SRC_DIR           =     ./

for(var, SRC_DIR){
    SOURCES         += $$files($$join(var, , , /*.cpp) , true)
    HEADERS         += $$files($$join(var, , , /*.h)   , true)
    RESOURCES       += $$files($$join(var, , , /*.qrc) , true)
}










