#include "menu.h"

Menu::Menu(QWidget *parent) :
    QWidget(parent)
{
}

Menu::~Menu()
{
}

void Menu::addEyeTrackerActions()
{
    QPushButton *pcmd1 = new QPushButton("Калибровка");
    QPushButton *pcmd2 = new QPushButton("Проверка движения");
    QPushButton *pcmd3 = new QPushButton("Тест 1");

    QVBoxLayout *pvbxLayout = new QVBoxLayout;
    pvbxLayout->setMargin(5);
    pvbxLayout->setSpacing(15);
    pvbxLayout->addWidget(pcmd1);
    pvbxLayout->addWidget(pcmd2);
    pvbxLayout->addWidget(pcmd3);

    this->setLayout(pvbxLayout);

   connect(pcmd1, &QPushButton::clicked, this,
           [=](){sendSignal(MENU_OPEN_EYE_TRACKER_CALIBRATION_WIDGET); });

}