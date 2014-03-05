

BUILDIR     = $$PWD/build
DESTDIR     = $$PWD/bin

OBJECTS_DIR = $$BUILDIR/obj/$$TARGET
MOC_DIR     = $$BUILDIR/moc/$$TARGET


unix:macx{
LIB_PATH     = $(BOOST_PATH)/stage/lib
INCLUDEPATH  = $(BOOST_PATH)
}
unix:!macx{
LIB_PATH     = $(BOOST_PATH)/lib
INCLUDEPATH  = $(BOOST_PATH)/include
}

message(TARGET variable is $$TARGET)
message(INCLUDEPATH variable is $$INCLUDEPATH)
message(LIB_PATH variable is $$LIB_PATH)
message(BUILDIR variable is $$BUILDIR)
message(PWD variable is $$PWD)
