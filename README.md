# Qt5.6 OpenGLWidget Bug

Minimal example to reproduce bug in Qt 5.6.0 when exiting a QApplication with several QOpenGLWidget on different screens.

On Ubuntu 14.04, when closing all widgets manually, the application exits and a seg fault occurs with the following backtrace:

#0  0x00007ffff70e9a80 in QObject::thread() const ()
   from /home/micha/Projects/Qt/5.6/gcc_64/lib/libQt5Core.so.5
#1  0x00007ffff5e8523a in QOffscreenSurface::create() ()
   from /home/micha/Projects/Qt/5.6/gcc_64/lib/libQt5Gui.so.5
#2  0x00007ffff5e854e8 in QOffscreenSurface::setScreen(QScreen*) ()
   from /home/micha/Projects/Qt/5.6/gcc_64/lib/libQt5Gui.so.5
#3  0x00007ffff70eacef in QMetaObject::activate(QObject*, int, int, void**) ()
   from /home/micha/Projects/Qt/5.6/gcc_64/lib/libQt5Core.so.5
#4  0x00007ffff70eb9ef in QObject::destroyed(QObject*) ()
   from /home/micha/Projects/Qt/5.6/gcc_64/lib/libQt5Core.so.5
#5  0x00007ffff70f3220 in QObject::~QObject() ()
   from /home/micha/Projects/Qt/5.6/gcc_64/lib/libQt5Core.so.5
#6  0x00007ffff5ea1a03 in QScreen::~QScreen() ()
   from /home/micha/Projects/Qt/5.6/gcc_64/lib/libQt5Gui.so.5
#7  0x00007ffff5ea1da9 in QScreen::~QScreen() ()
   from /home/micha/Projects/Qt/5.6/gcc_64/lib/libQt5Gui.so.5
#8  0x00007ffff5e651ff in QPlatformIntegration::destroyScreen(QPlatformScreen*) ()
   from /home/micha/Projects/Qt/5.6/gcc_64/lib/libQt5Gui.so.5
#9  0x00007fffefe058d3 in QXcbConnection::~QXcbConnection() ()
   from /home/micha/Projects/Qt/5.6/gcc_64/plugins/platforms/../../lib/libQt5XcbQpa.so.5
#10 0x00007fffefe05f59 in QXcbConnection::~QXcbConnection() ()
   from /home/micha/Projects/Qt/5.6/gcc_64/plugins/platforms/../../lib/libQt5XcbQpa.so.5
#11 0x00007fffefe0cc2e in QXcbIntegration::~QXcbIntegration() ()
   from /home/micha/Projects/Qt/5.6/gcc_64/plugins/platforms/../../lib/libQt5XcbQpa.so.5
#12 0x00007fffefe0cd09 in QXcbIntegration::~QXcbIntegration() ()
   from /home/micha/Projects/Qt/5.6/gcc_64/plugins/platforms/../../lib/libQt5XcbQpa.so.5
#13 0x00007ffff5e72d84 in QGuiApplicationPrivate::~QGuiApplicationPrivate() ()
   from /home/micha/Projects/Qt/5.6/gcc_64/lib/libQt5Gui.so.5
#14 0x00007ffff76ba7b9 in QApplicationPrivate::~QApplicationPrivate() ()
   from /home/micha/Projects/Qt/5.6/gcc_64/lib/libQt5Widgets.so.5
#15 0x00007ffff70f2fe6 in QObject::~QObject() ()
   from /home/micha/Projects/Qt/5.6/gcc_64/lib/libQt5Core.so.5
#16 0x00007ffff70c3818 in QCoreApplication::~QCoreApplication() ()
   from /home/micha/Projects/Qt/5.6/gcc_64/lib/libQt5Core.so.5
#17 0x00007ffff5e72b8f in QGuiApplication::~QGuiApplication() ()
   from /home/micha/Projects/Qt/5.6/gcc_64/lib/libQt5Gui.so.5
#18 0x00007ffff76bbfd4 in QApplication::~QApplication() ()
   from /home/micha/Projects/Qt/5.6/gcc_64/lib/libQt5Widgets.so.5
#19 0x0000000000400d2f in main (argc=1, argv=0x7fffffffe2a8) at main.cpp:16

Also happens on MacOSX El Capitan:

    __TEXT                 000000010aa24000-000000010aa27000 [   12K]
r-x/rwx SM=COW  /Users/USER/*/qt5bug.app/Contents/MacOS/qt5bug

Thread 0 Crashed:: Dispatch queue: com.apple.main-thread
0   org.qt-project.QtCore         	0x000000010b9ab2f4 QObject::thread()
const + 4
1   org.qt-project.QtGui          	0x000000010b1a6c11
QOffscreenSurface::create() + 113
2   org.qt-project.QtGui          	0x000000010b1a6ffb
QOffscreenSurface::setScreen(QScreen*) + 299
3   org.qt-project.QtCore         	0x000000010b9b35bd
QMetaObject::activate(QObject*, int, int, void**) + 749
4   org.qt-project.QtCore         	0x000000010b9ab67f
QObject::~QObject() + 271
5   org.qt-project.QtGui          	0x000000010b1c6507
QScreen::~QScreen() + 679
6   org.qt-project.QtGui          	0x000000010b1c654e
QScreen::~QScreen() + 14
7   org.qt-project.QtGui          	0x000000010b1850eb
QPlatformIntegration::destroyScreen(QPlatformScreen*) + 43
8   libqcocoa.dylib               	0x000000010eb1c0d1
QCocoaIntegration::~QCocoaIntegration() + 497
9   libqcocoa.dylib               	0x000000010eb1c47e
QCocoaIntegration::~QCocoaIntegration() + 14
10  org.qt-project.QtGui          	0x000000010b194e01
QGuiApplicationPrivate::~QGuiApplicationPrivate() + 417
11  org.qt-project.QtWidgets      	0x000000010aaa0b8e
QApplicationPrivate::~QApplicationPrivate() + 14
12  org.qt-project.QtCore         	0x000000010b9abd71
QObject::~QObject() + 2049
13  org.qt-project.QtWidgets      	0x000000010aaa28f0
QApplication::~QApplication() + 992
14  com.yourcompany.qt5bug        	0x000000010aa26d05 main + 389
(main.cpp:22)
15  com.yourcompany.qt5bug        	0x000000010aa26b74 start + 52


