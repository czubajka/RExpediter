# needed for qDebug() info

CONFIG += debug

# put auto-generated catalogs in unseen dir

win32 {
   MOC_DIR = _moc
   UI_DIR = _ui
   OBJECTS_DIR = _obj
}  else {
   UI_DIR = .ui
   MOC_DIR = .moc
   OBJECTS_DIR = .obj
}

# for TEMPLATE = app projects
app {
    # put execution file in the same dir
    DESTDIR = $$OUT_PWD
    # do not put exec files into applications package for MacOS
    # so that console apps can work there as well
    mac {
    	CONFIG -= app_bundle 
    }

    # open console for stdin, stdout, stderr on Windows
    win32 {
    	  CONFIG += console
    }
}
