#-------------------------------------------------
#
# Project created by QtCreator 2011-10-09T11:19:10
#
#-------------------------------------------------

QT       += core gui network
TARGET = Client
TEMPLATE = app



SOURCES += main.cpp mainwindow.cpp

#HEADERS  += json_spirit_error_position.h json_spirit_reader_template.h \
#            json_spirit_value.h json_spirit_writer_template.h \
HEADERS +=  json_spirit.h \ #json_spirit_stream_reader.h json_spirit_writer.h \
            mainwindow.h \ #json_spirit_reader.h json_spirit_utils.h \
            #json_spirit_writer_options.h \ #ui_mainwindow.h \
            boost/variant.hpp \
            ../Server/mserver.hpp


#    ../Server/mserver.hpp
#	    *.hpp

FORMS    += mainwindow.ui


