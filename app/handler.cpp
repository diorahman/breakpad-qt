#include "handler.h"
#include "client/mac/handler/exception_handler.h"
#include <QDebug>

class HandlerPrivate{
public:
  HandlerPrivate(Handler * parent) : q_ptr(parent){}

  void init(const QString & dumpPath);
  static google_breakpad::ExceptionHandler * pHandler;
  static bool reportCrashesToSystem;

private:
  Handler * const q_ptr;
  Q_DECLARE_PUBLIC(Handler);
};

google_breakpad::ExceptionHandler * HandlerPrivate::pHandler;
bool HandlerPrivate::reportCrashesToSystem = false;

bool DumpCallback(const char * dump_dir, const char * minidump_id, void * context, bool success){
  Q_UNUSED(context);
  qDebug() << "breakpad crash handler";
  return true;
}

void HandlerPrivate::init(const QString & dumpPath){
  if(pHandler) return;
  std::string path = dumpPath.toStdString();
  pHandler = new google_breakpad::ExceptionHandler(path, 0, DumpCallback, 0, true, NULL);
}

Handler * Handler::instance(){
  static Handler handler;
  return &handler;
}

Handler::~Handler(){
  Q_D(Handler);
  delete d;
}

Handler::Handler(){
  d_ptr = new HandlerPrivate(this);
}

void Handler::setReportCrashesToSystem(bool report){
  Q_D(Handler);
  d->reportCrashesToSystem = report;
}

bool Handler::writeMinidump(){
  Q_D(Handler);
  bool res = d->pHandler->WriteMinidump();
  if(res){ qDebug() << "yay!";}
  else {qDebug() << "ouch!";}
  return res;
}

void Handler::init(const QString & reportPath){
  Q_D(Handler);
  d->init(reportPath);
}

