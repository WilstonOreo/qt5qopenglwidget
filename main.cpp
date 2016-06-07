#include <QApplication>
#include <QDesktopWidget>
#include <QOpenGLWidget>

int main(int argc, char* argv[]) {
  QApplication _a(argc, argv);

  int _screenCount = QApplication::desktop()->screenCount();

  // Create a QOpenGLWidget for each screen
  for (int i = 0; i < _screenCount; ++i) {
    QOpenGLWidget* _widget = new QOpenGLWidget();

    // Set geometry of widget to fill entire screen
    // This causes the bug, probably because a new QOpenGLContext is created here
    _widget->setGeometry(QApplication::desktop()->screenGeometry(i));

    _widget->show();
  }

  return _a.exec();
}
