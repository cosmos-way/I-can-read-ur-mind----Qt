#pragma once
#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include <QtWidgets>
#include <QTimer>

#define NO_ET false

#define MAX_CMD_LENGTH 2

const QString OTHER_SIGNAL_WITH_DATA = "000";

const QString EYE_TRACKER_INIT = "100";
const QString EYE_TRACKER_SUCESSFULL_INIT = "101";
const QString EYE_TRACKER_FAILED_INIT = "102";
const QString EYE_TRACKER_START_CALIBRATION = "110";
const QString EYE_TRACKER_SUCESSFULL_CALIBRATION_START = "111";
const QString EYE_TRACKER_FAILED_CALIBRATION = "112";
const QString EYE_TRACKER_POINT_TO_CALIBRATE = "115";
const QString EYE_TRACKER_COMPUTING_AND_APPLYING_CALIBRATION = "116";
const QString EYE_TRACKER_LEAVE_CALIBRATION_MODE = "119";

const QString MENU_ADD_EYE_TRACKER_ACTIONS = "200";
const QString MENU_OPEN_EYE_TRACKER_CALIBRATION_WIDGET = "201";
const QString MENU_START_CALIBRATION = "202";

const QString CONTROLLER_ALL_GADGETS_SUCESSFULL_INITED = "310";
const QString CONTROLLER_CALIBRATION_WIDGET_CLICKED_START = "311";

const QString VIEW_CALIBRATION_WIDGET_READY = "400";
const QString VIEW_INIT_COMRLETED = "401";

const QString MODEL_INIT_ALL_GADGETS = "500";

void JSON_read();
void JSON_create();
//pt::ptree * JSON_representation(string strData);
