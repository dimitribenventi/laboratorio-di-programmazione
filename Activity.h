//
// Created by dimitri benvenuti on 12/02/26.
//

#ifndef ACTIVITYREGISTER_ACTIVITY_H
#define ACTIVITYREGISTER_ACTIVITY_H

#include <string>

class Activity {
private:
    std::string name, description;
    std::string startTime, endTime;
public:
    Activity(const std::string &n, const std::string &d, const std::string &s, const std::string &e) :
        name(std::move(n)), description(std::move(d)), startTime(std::move(s)), endTime(std::move(e)) {}

    std::string getName() const { return name; }
    std::string getDescription() const { return description; }
    std::string getStart() const { return startTime; }
    std::string getEnd() const { return endTime; }
};

#endif //ACTIVITYREGISTER_ACTIVITY_H