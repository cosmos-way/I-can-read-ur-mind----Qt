#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent)
{

}

void Controller::handler(const ResponseAnswer_ENUM cmd, const QString JSONdata)
{
    qDebug() << "Controller::handler recieved: "<< cmd;
    switch (cmd) {
    case VIEW_INIT_COMRLETED:
    {
        emit modelHandler(MODEL_INIT_ALL_GADGETS);
        emit modelHandler(MODEL_INIT);
        // после инициализации всех н-интерфейсов необходимо найти (загрузить) все доступные тесты в рабочей директории
        findAllTests();
        break;
    }
    case VIEW_CALIBRATION_WIDGET_READY:
    {
        emit modelHandler(EYE_TRACKER_START_CALIBRATION);
        break;
    }
    case MENU_OPEN_TEST_d:
    {
        emit modelHandler(MODEL_START_TEST_d, JSONdata);
        break;
    }
    case CONTROLLER_NEW_TEST_FILE_d:
    {
        emit modelHandler(MODEL_ADD_TEST_d, JSONdata);
        break;
    }
    case CONTROLLER_ADD_NEW_TEST_FILE_WITH_DIALOG:
    {
        // отправляется запрос во view с параметрами фильтрации
        break;
    }
//    case MODEL_TESTS_CONTROLLER_TEST_NOT_LOADED:
//    case MODEL_TESTS_CONTROLLER_SUCCESS:
//    case MODEL_TESTS_CONTROLLER_NO_SUCH_TEST_ID:
//    case MODEL_TESTS_CONTROLLER_TEST_NOT_LOADED:
//    case MODEL_TESTS_CONTROLLER_LOADED:
//    case MODEL_TESTS_CONTROLLER_NO_LOADED_TEST:
//    case MODEL_TESTS_CONTROLLER_SUCCESS_TEST_START:
//    case MODEL_TESTS_CONTROLLER_THERE_IS_ACTIVE_TEST:
//        break;
    case MODEL__TEST_PATH_d:
    {
        emit viewHandler(VIEW_TEST_PATH_FOR_LOAD, JSONdata);
        break;
    }
    case VIEW_TEST_VIEW_SHOW_SUCCESS:
    {// отправляем запрос на запуск трекинга
        emit modelHandler(VIEW_TEST_VIEW_SHOW_SUCCESS);
        break;
    }
    case VIEW_WINDOW_SIZE_d:
    {
        emit modelHandler(VIEW_WINDOW_SIZE_d, JSONdata);
        break;
    }
    case VIEW_TEST_CLOSE_TEST:
    {
        emit modelHandler(VIEW_TEST_CLOSE_TEST);
        break;
    }
    case MODEL_TEST_WAS_ADDED_d:
    {
        emit viewHandler(MENU_ADD_TEST_d, JSONdata); // отправляем меню данные о тесте
        break;
    }
    case MODEL_INIT_COMRLETED:
    {
        emit viewHandler(MODEL_INIT_COMRLETED);
        break;
    }
    case APP_EXIT:
        emit appExit();
        break;
    default:
        break;
    }
}

int Controller::findAllTests()
{
    qDebug() << "QDir::current()" << QDir::current();
    workDir = QDir::current();
    // находим в актуальной директории все файлы с помощью фильтра
    listFiles = workDir.entryList(QStringList() << "BCIs_T*.xml",
                                  QDir::Files);
    QJsonObject  tmpJson;

    foreach(QString fileElement, listFiles)
    {
        qDebug() << "Finded test file: " << fileElement;
        tmpJson["fileName"] = fileElement;
        handler(CONTROLLER_NEW_TEST_FILE_d, JSONtoStr(tmpJson));
    }
    return listFiles.count();
}
