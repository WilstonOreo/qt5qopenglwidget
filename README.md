# Qt5.6 OpenGLWidget Bug

Minimal example to reproduce bug in Qt 5.6.0 when exiting a QApplication with several QOpenGLWidget on different screens.

When closing all widgets manually, the application exits and a seg fault occurs with the following backtrace:

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

