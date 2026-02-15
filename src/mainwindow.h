#ifndef ACTIVITYREGISTER_MAINWINDOW_H
#define ACTIVITYREGISTER_MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QVBoxLayout>
#include <QTimeEdit>
#include <QDateEdit>
#include <QTime>

#include "Register.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void onAddActivityClicked();
    void onActivityClicked(QListWidgetItem* item);
    void onDateChanged(const QDate &date);
private:
    void updateActivityList(const std::string& date);

    Register activityRegister;

    QLineEdit *nameInput;
    QLineEdit *descriptionInput;
    QTimeEdit *startTimeInput;
    QTimeEdit *endTimeInput;
    QDateEdit *dateInput;

    QPushButton *addButton;
    QListWidget *activityList;
};

#endif //ACTIVITYREGISTER_MAINWINDOW_H