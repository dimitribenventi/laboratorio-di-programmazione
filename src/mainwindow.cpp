


#include "mainwindow.h"
#include "Activity.h"
#include <QTimeEdit>
#include <QTime>
#include <QMessageBox>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    QPushButton *removeButton = new QPushButton("Remove Selected", this);
    layout->addWidget(removeButton);

    connect(removeButton, &QPushButton::clicked, [this]() {
        auto item = activityList->currentItem();
        if (!item) return;

        int row = activityList->currentRow();
        std::string date = "2026-02-12";
        activityRegister.removeActivityByIndex(date, row);

        updateActivityList(date);
    });

    nameInput = new QLineEdit(this);
    nameInput->setPlaceholderText("Activity name");

    descriptionInput = new QLineEdit(this);
    descriptionInput->setPlaceholderText("Activity description");

    startTimeInput = new QTimeEdit(this);
    startTimeInput->setDisplayFormat("HH:mm");
    startTimeInput->setTime(QTime(8,0));

    endTimeInput = new QTimeEdit(this);
    endTimeInput->setDisplayFormat("HH:mm");
    endTimeInput->setTime(QTime(9,0));

    layout->addWidget(startTimeInput);
    layout->addWidget(endTimeInput);

    addButton = new QPushButton("Add Activity", this);

    activityList = new QListWidget(this);

    layout->addWidget(nameInput);
    layout->addWidget(descriptionInput);
    layout->addWidget(addButton);
    layout->addWidget(activityList);

    connect(addButton, &QPushButton::clicked,
            this, &MainWindow::onAddActivityClicked);

    connect(activityList, &QListWidget::itemClicked, this, &MainWindow::onActivityClicked);
}

void MainWindow::onAddActivityClicked()
{
    QString name = nameInput->text();
    QString description = descriptionInput->text();

    if (name.isEmpty())
        return;

    QString start = startTimeInput->time().toString("HH:mm");
    QString end   = endTimeInput->time().toString("HH:mm");

    Activity activity(
        name.toStdString(),
        description.toStdString(),
        start.toStdString(),
        end.toStdString()
    );

    std::string date = "2026-02-12";

    activityRegister.addActivity(date, activity);

    updateActivityList(date);

    nameInput->clear();
    descriptionInput->clear();
    startTimeInput->setTime(QTime(8,0));
    endTimeInput->setTime(QTime(9,0));
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

void MainWindow::onActivityClicked(QListWidgetItem* item)
{
    int row = activityList->row(item);

    std::string date = "2026-02-12";

    auto activities = activityRegister.getActivitiesByDate(date);

    if(row >= 0 && row < static_cast<int>(activities.size())) {
        const Activity& a = activities[row];

        QMessageBox::information(this, "Descrizione attività",
                                 QString::fromStdString(a.getDescription()));
    }
}