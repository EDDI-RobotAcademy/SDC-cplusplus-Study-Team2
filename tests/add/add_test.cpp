//
// Created by eddi on 23. 12. 4.
//

#include <gtest/gtest.h>
#include "../../g_sample/g_sample.h"

TEST(AddTest, onePlusTwoGivesThree)
{
    g_sample *add_object = new g_sample();

    EXPECT_EQ(3, add_object->sum(1, 2));
}