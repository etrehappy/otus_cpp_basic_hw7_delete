#include <gtest/gtest.h>

#include "u_list.h"

TEST(TestList, container_create)
{
    u_list list;
    std::cout << std::endl;

    ASSERT_TRUE(list.size() == NULL);
}

int main(int argc, char** argv) {
    
    setlocale(LC_ALL, "Russian");

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}