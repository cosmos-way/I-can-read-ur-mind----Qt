#ifndef Menu_H
#define Menu_H

#include <QWidget>
#include <additional_header.h>

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent);
    ~Menu();
public slots:
    int signalsHandler(const QString&);
private:
    QWidget *pMainWin;
};

#endif // Menu_H
