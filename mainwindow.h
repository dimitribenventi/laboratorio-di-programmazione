//
// Created by dimitri benvenuti on 12/02/26.
//

#ifndef ACTIVITYREGISTER_MAINWINDOW_H
#define ACTIVITYREGISTER_MAINWINDOW_H


#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QVBoxLayout>

#include "Register.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void onAddActivityClicked();

private:
    void updateActivityList(const std::string& date);

    Register activityRegister;

    QLineEdit *nameInput;
    QLineEdit *descriptionInput;
    QPushButton *addButton;
    QListWidget *activityList;
};


#endif //ACTIVITYREGISTER_MAINWINDOW_H