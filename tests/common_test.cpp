#include <gtest/gtest.h>

extern "C" {
    #include "common.h"
}

TEST (COMMON_TEST_SUITE, CREATE_HEAD_TEST) 
{
    head_t *head = createHead();
    EXPECT_TRUE(head != NULL && get_head_size(head) == -1 && get_head_front(head) == NULL && get_head_rear(head) == NULL);
}