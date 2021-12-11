QT               += 	core gui
TEMPLATE          = 	app
TARGET            =     examples
DEFINES          +=     QT_DEPRECATED_WARNINGS
DESTDIR          +=     apps
MOC_DIR           =     temp/moc
UI_DIR            =     temp/uic
RCC_DIR           =     temp/rcc
OBJECTS_DIR       =     temp/objs
CONFIG           +=     warn_on
CONFIG           +=     debug_and_release



SRC_DIR           =     ./
LIBS_INCLUDE_DIR  =     ../
LIBS_SRC_DIR      =     ../libs

INCLUDEPATH       +=                                            \
                            $${LIBS_INCLUDE_DIR}/components



LIBS              +=                                            \
                            -L"$${LIBS_SRC_DIR}"



LIBS              +=                                            \
                            -lcomponents



for(var, SRC_DIR){
    SOURCES         += $$files($$join(var, , , /*.cpp) , true)
    HEADERS         += $$files($$join(var, , , /*.h)   , true)
    FORMS           += $$files($$join(var, , , /*.ui)  , true)
    RESOURCES       += $$files($$join(var, , , /*.qrc) , true)
    TRANSLATIONS    += $$files($$join(var, , , /*.ts)  , true)
}
