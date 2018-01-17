#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFrame>
#include <QStackedWidget>
#include "src/additional_header.h"



class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void init(){}
    int addInViewStack(QWidget*inWidget);
    int addAndShowInViewStack(QWidget*inWidget);
    int showWidgetFromStack(QWidget*inWidget);
    int showLoadingWidget(); // send pre widget id in stackedWidget
    void closeLoadingWidget();
    void removeFromStack(QWidget*inWidget);
signals:
    void sendSignal(const ResponseAnswer_ENUM cmd, const QString JSONdata = "");
public slots:
private:
    QStackedWidget *stackedWidget;
    int loadingWidgetIndexInStack;
};

#endif // MAINWINDOW_H
