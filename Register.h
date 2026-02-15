//
// Created by dimitri benvenuti on 12/02/26.
//

#ifndef ACTIVITYREGISTER_REGISTER_H
#define ACTIVITYREGISTER_REGISTER_H


#include <map>
#include <vector>
#include <iostream>
#include "Activity.h"

class Register {
private:
    std::map<std::string, std::vector<Activity>> activities;
public:

    void addActivity(const std::string& date, const Activity& newActivity) {
        activities[date].push_back(newActivity);
    }

    std::vector<Activity> getActivitiesByDate(const std::string& date) const {
        auto it = activities.find(date);
        if (it != activities.end()) {
            return it->second;
        }
        return {};
    }

    void printByDate(const std::string& date) const {
        auto it = activities.find(date);
        if (it == activities.end()) {
            std::cout << "date not found;" << std::endl;
            return;
        }
        std::cout << " -----" << date << "----- " << std::endl;
        for (const auto& a : it->second) {
            std::cout << a.getName()
                  << " (" << a.getStart()
                  << " - " << a.getEnd() << ")\n";
        }
    }
};

#endif //ACTIVITYREGISTER_REGISTER_H