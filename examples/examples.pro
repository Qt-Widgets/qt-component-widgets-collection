QT 		 += 	core gui
TEMPLATE 	  = 	app
TARGET            =     example
DEFINES          +=     QT_DEPRECATED_WARNINGS
DESTDIR          +=     libs
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
    RESOURCES       += $$files($$join(var, , , /*.qrc) , true)
}
