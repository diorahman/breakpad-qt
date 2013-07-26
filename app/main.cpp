#include <QtCore/QCoreApplication>
#include <QString>
#include <QDebug>
#include "handler.h"

int bug(){
  delete reinterpret_cast<QString*>(0xFEE1DEAD);
  return 0;
}

int main(int argc, char * argv[]){
  QCoreApplication app(argc, argv);

  Handler::instance()->init(".");
  qDebug() << "init";
  bug();
  return app.exec();
}