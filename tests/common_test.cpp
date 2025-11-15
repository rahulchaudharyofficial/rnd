#include <gtest/gtest.h>
extern "C" {
    #include "common.h"
}

TEST (COMMON_TEST_SUITE, CREATE_HEAD_TEST) {
    EXPECT_TRUE(createHead(-1, NULL,NULL) == NULL);
}