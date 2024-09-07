lessThan(QT_MAJOR_VERSION, 6) {
  CONFIG += c++14
  windows:QMAKE_CXXFLAGS += /std:c++14
} else {
  CONFIG += c++17
  windows:QMAKE_CXXFLAGS += /Zc:__cplusplus /std:c++17
}

windows {
  INCLUDEPATH += $$quote($$(TFDIR)\\include)
  LIBS += -L$$quote($$(TFDIR)\\bin)
  CONFIG(debug, debug|release) {
    LIBS += -ltreefrogd2
  } else {
    LIBS += -ltreefrog2
  }
} else {
  unix:LIBS += -Wl,-rpath,. -Wl,-rpath,/opt/homebrew/Cellar/treefrog/2.9.0/lib -L/opt/homebrew/Cellar/treefrog/2.9.0/lib -ltreefrog
  unix:INCLUDEPATH += /opt/homebrew/Cellar/treefrog/2.9.0/include/treefrog
  linux-*:LIBS += -lrt
}
