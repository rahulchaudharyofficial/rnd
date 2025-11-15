#include <gtest/gtest.h>
extern "C" {
    #include "common.h"
}

TEST (COMMON_TEST_SUITE, CREATE_HEAD_TEST) 
{
    head_t *head = createHead(-1, NULL,NULL);
    EXPECT_TRUE(head != NULL && head->size == -1 && head -> front == NULL && head -> rear == NULL);
}