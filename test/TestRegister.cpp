
#include <gtest/gtest.h>
#include "../src/Register.h"
#include "../src/Activity.h"

TEST(RegisterTest, AddAndRetrieveActivity) {
    Register reg;
    Activity a("Jogging", "Morning run", "06:00", "07:00");
    reg.addActivity("2026-02-15", a);

    auto activities = reg.getActivitiesByDate("2026-02-15");
    ASSERT_EQ(activities.size(), 1);
    EXPECT_EQ(activities[0].getName(), "Jogging");
}