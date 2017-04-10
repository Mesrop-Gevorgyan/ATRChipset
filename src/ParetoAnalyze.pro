#-------------------------------------------------
#
# Project created by QtCreator 2017-03-19T22:10:14
#
#-------------------------------------------------

QT += charts

SOURCES += \
    main.cpp \
    draw_pareto.cpp \
    mainwindow.cpp \
    pareto.cpp

target.path = $$[QT_INSTALL_EXAMPLES]/charts/barchart
INSTALLS += target

FORMS += \
    mainwindow.ui

DISTFILES += \
    ParetoAnalyze.pro.user

HEADERS += \
    draw_pareto.h \
    mainwindow.h \
    pareto.h
