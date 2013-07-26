#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>
#include <QString>

class HandlerPrivate;
class Handler{
public: 
  static Handler * instance();
  void init(const QString & reportPath);
  void setReportCrashesToSystem(bool report);
  bool writeMinidump();

private:
  Handler();
  ~Handler();
  HandlerPrivate * d_ptr;
  Q_DECLARE_PRIVATE(Handler);
};

#endif