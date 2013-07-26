SOURCES = handler.cpp main.cpp
HEADERS = handler.cpp

BREAKPADPATH += /Users/diorahman/Experiments/misc/breakpad/google-breakpad
INCLUDEPATH += $$BREAKPADPATH/src
CONFIG -= app_bundle
QT -= gui
LIBS= -F../Frameworks -framework Breakpad