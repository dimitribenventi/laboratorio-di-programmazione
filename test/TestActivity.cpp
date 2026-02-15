

#include <gtest/gtest.h>
#include "../src/Activity.h"

TEST(ActivityTest, NameGetter) {
    Activity a("Jogging", "Morning run", "06:00", "07:00");
    EXPECT_EQ(a.getName(), "Jogging");
}

TEST(ActivityTest, TimeGetter) {
    Activity a("Jogging", "Morning run", "06:00", "07:00");
    EXPECT_EQ(a.getStart(), "06:00");
    EXPECT_EQ(a.getEnd(), "07:00");
}