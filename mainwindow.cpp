//
// Created by dimitri benvenuti on 12/02/26.
//


#include "mainwindow.h"
#include "Activity.h"

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    nameInput = new QLineEdit(this);
    nameInput->setPlaceholderText("Activity name");

    descriptionInput = new QLineEdit(this);
    descriptionInput->setPlaceholderText("Activity description");

    addButton = new QPushButton("Add Activity", this);

    activityList = new QListWidget(this);

    layout->addWidget(nameInput);
    layout->addWidget(descriptionInput);
    layout->addWidget(addButton);
    layout->addWidget(activityList);

    connect(addButton, &QPushButton::clicked,
            this, &MainWindow::onAddActivityClicked);
}

void MainWindow::onAddActivityClicked()
{
    QString name = nameInput->text();
    QString description = descriptionInput->text();

    if (name.isEmpty())
        return;

    Activity activity(
        name.toStdString(),
        description.toStdString(),
        "08:00",
        "09:00"
    );

    std::string date = "2026-02-12";

    activityRegister.addActivity(date, activity);

    updateActivityList(date);

    nameInput->clear();
    descriptionInput->clear();
}

void MainWindow::updateActivityList(const std::string& date)
{
    activityList->clear();

    auto activities = activityRegister.getActivitiesByDate(date);

    for (const auto& a : activities) {
        QString itemText = QString::fromStdString(
            a.getName() + " (" + a.getStart() + " - " + a.getEnd() + ")"
        );

        activityList->addItem(itemText);
    }
}