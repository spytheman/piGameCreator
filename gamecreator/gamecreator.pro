#-------------------------------------------------
#
# piGameCreator multiplatform game development IDE
#
# GPLv3 preamble goes here for GPLd version,
# commercial for commercial version
#
#-------------------------------------------------

# Note that libzip and zlib folders' varsions are stripped
# in order to be able to do fast updates without many pain

CONFIG += ordered

INCLUDEPATH += ../zlib ../libzip/lib ../glew/include ../glew/lib ../freeglut/include

LIBS += ../zlib/libz.a ../freeglut/lib/libfreeglut32_static.a ../glew/lib/libglew32.a -lopengl32 -luser32 -lgdi32 -lkernel32 -lwinmm

QT       += core gui webkit xml opengl xmlpatterns

TARGET = gamecreator
TEMPLATE = app

SOURCES += main.cpp \
    mainwindow.cpp \
    logwindow.cpp \
    gamecreator.cpp \
    mainpage.cpp \
    gameproject.cpp \
    projectmodel.cpp \
    imagewindow.cpp \
    saveornot.cpp \
    qtwin.cpp \
    gcfileformat.cpp \
    ../libzip/lib/zip_unchange_data.c \
    ../libzip/lib/zip_unchange_archive.c \
    ../libzip/lib/zip_unchange_all.c \
    ../libzip/lib/zip_unchange.c \
    ../libzip/lib/zip_strerror.c \
    ../libzip/lib/zip_stat_init.c \
    ../libzip/lib/zip_stat_index.c \
    ../libzip/lib/zip_stat.c \
    ../libzip/lib/zip_source_zip.c \
    ../libzip/lib/zip_source_function.c \
    ../libzip/lib/zip_source_free.c \
    ../libzip/lib/zip_source_filep.c \
    ../libzip/lib/zip_source_file.c \
    ../libzip/lib/zip_source_buffer.c \
    ../libzip/lib/zip_set_name.c \
    ../libzip/lib/zip_set_file_comment.c \
    ../libzip/lib/zip_set_archive_flag.c \
    ../libzip/lib/zip_set_archive_comment.c \
    ../libzip/lib/zip_replace.c \
    ../libzip/lib/zip_rename.c \
    ../libzip/lib/zip_open.c \
    ../libzip/lib/zip_new.c \
    ../libzip/lib/zip_name_locate.c \
    ../libzip/lib/zip_memdup.c \
    ../libzip/lib/zip_get_num_files.c \
    ../libzip/lib/zip_get_name.c \
    ../libzip/lib/zip_get_file_comment.c \
    ../libzip/lib/zip_get_archive_flag.c \
    ../libzip/lib/zip_get_archive_comment.c \
    ../libzip/lib/zip_free.c \
    ../libzip/lib/zip_fread.c \
    ../libzip/lib/zip_fopen_index.c \
    ../libzip/lib/zip_fopen.c \
    ../libzip/lib/zip_filerange_crc.c \
    ../libzip/lib/zip_file_strerror.c \
    ../libzip/lib/zip_file_get_offset.c \
    ../libzip/lib/zip_file_error_get.c \
    ../libzip/lib/zip_file_error_clear.c \
    ../libzip/lib/zip_fclose.c \
    ../libzip/lib/zip_error_to_str.c \
    ../libzip/lib/zip_error_strerror.c \
    ../libzip/lib/zip_error_get_sys_type.c \
    ../libzip/lib/zip_error_get.c \
    ../libzip/lib/zip_error_clear.c \
    ../libzip/lib/zip_error.c \
    ../libzip/lib/zip_err_str.c \
    ../libzip/lib/zip_entry_new.c \
    ../libzip/lib/zip_entry_free.c \
    ../libzip/lib/zip_dirent.c \
    ../libzip/lib/zip_delete.c \
    ../libzip/lib/zip_close.c \
    ../libzip/lib/zip_add_dir.c \
    ../libzip/lib/zip_add.c \
    ../libzip/lib/mkstemp.c \
    dllforexport.cpp \
    progressdialog.cpp \
    imgwframesmodel.cpp \
    imgwpreview.cpp \
    resourceeditor.cpp \
    platformdependent.cpp \
    scriptwindow.cpp \
    pgsparser.cpp \
    srcSettings/settingswindow.cpp \
    scripttestwindow.cpp \
    classwindow.cpp \
    srcClass/getimageormodel.cpp \
    srcClass/editvardialog.cpp \
    srcClass/variable.cpp \
    srcClass/classwindoweventfilters.cpp \
    srcClass/addeventwindow.cpp \
    srcClass/getclassresource.cpp \
    srcClass/getkeyevent.cpp \
    srcClass/getmouseevent.cpp \
    srcClass/addfunction.cpp \
    sceneeditor.cpp \
    srcScene/sceneview.cpp \
    glhelp.cpp \
    qwidgetwithclosesignal.cpp \
    buildtargets.cpp \
    extapi.cpp \
    skintestwindow.cpp \
    gameframeworkclassdef.cpp \
    ntdialog.cpp \
    overlay.cpp


HEADERS  += mainwindow.h \
    logwindow.h \
    gamecreator.h \
    mainpage.h \
    gameproject.h \
    projectmodel.h \
    imagewindow.h \
    saveornot.h \
    qtwin.h \
    gcfileformat.h \
    ../libzip/lib/zipint.h \
    ../libzip/lib/zip.h \
    dllforexport.h \
    progressdialog.h \
    imgwframesmodel.h \
    imgwpreview.h \
    resourceeditor.h \
    scriptwindow.h \
    pgsparser.h \
    srcSettings/settingswindow.h \
    scripttestwindow.h \
    classwindow.h \
    srcClass/getimageormodel.h \
    srcClass/editvardialog.h \
    srcClass/variable.h \
    srcClass/classwindoweventfilters.h \
    srcClass/addeventwindow.h \
    srcClass/getclassresource.h \
    srcClass/getkeyevent.h \
    srcClass/getmouseevent.h \
    srcClass/addfunction.h \
    sceneeditor.h \
    srcScene/sceneview.h \
    glhelp.h \
    qwidgetwithclosesignal.h \
    buildtargets.h \
    extapi.h \
    skintestwindow.h \
    gameframeworkclassdef.h \
    ntdialog.h \
    overlay.h


FORMS    += mainwindow.ui \
    logwindow.ui \
    mainpage.ui \
    imagewindow.ui \
    saveornot.ui \
    progressdialog.ui \
    scriptwindow.ui \
    srcSettings/settingswindow.ui \
    scripttestwindow.ui \
    classwindow.ui \
    srcClass/getimageormodel.ui \
    srcClass/editvardialog.ui \
    srcClass/addeventwindow.ui \
    srcClass/getclassresource.ui \
    srcClass/getkeyevent.ui \
    srcClass/getmouseevent.ui \
    srcClass/addfunction.ui \
    sceneeditor.ui \
    buildtargets.ui \
    skintestwindow.ui \
    gameframeworkclassdef.ui \
    ntdialog.ui

RESOURCES += \
    resources.qrc

DEFINES += GLEW_STATIC FREEGLUT_STATIC
