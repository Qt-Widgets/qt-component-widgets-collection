QT 		 += 	core gui
TEMPLATE 	  = 	lib
TARGET            =     components
DEFINES          +=     QT_DEPRECATED_WARNINGS
DESTDIR          +=     libs
MOC_DIR           =     temp/moc
UI_DIR            =     temp/uic
RCC_DIR           =     temp/rcc
OBJECTS_DIR       =     temp/objs
CONFIG           +=     staticlib
CONFIG           +=     warn_on
CONFIG           +=     debug_and_release
SRC_DIR           =     ./

MK_LIBS_DIR       =     ../libs

exists($$MK_LIBS_DIR) {
        message("existing")
    } else {
            QMAKE_POST_LINK += $$quote(mkdir $${MK_LIBS_DIR} $$escape_expand(\n\t))
    }

for(var, SRC_DIR){
    SOURCES         += $$files($$join(var, , , /*.cpp) , true)
    HEADERS         += $$files($$join(var, , , /*.h)   , true)
    RESOURCES       += $$files($$join(var, , , /*.qrc) , true)
}