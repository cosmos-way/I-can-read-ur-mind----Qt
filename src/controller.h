#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "src/additional_header.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);

signals:
    void modelHandler(const ResponseAnswer_ENUM cmd, const QString JSONdata = "");
public slots:
    void handler(const ResponseAnswer_ENUM cmd, const QString JSONdata = "");
};

#endif // CONTROLLER_H