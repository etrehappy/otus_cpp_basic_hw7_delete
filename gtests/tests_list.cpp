#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "u_list.h"

struct ListTestF : public testing::Test 
{
    //arrange
    u_list list;
    u_list empty_list;
    const int list_start_size = 4;    

    void SetUp() override
    {
        for (int i = 1; i <= list_start_size; i++)
            list.push_back(i);        

        /*for (u_list::iterator it = list.begin(); it != list.end(); ++it)
            list_lust_it = it;*/
    } 
};

TEST_F(ListTestF, create_list)
{   
    //arrange
    const int expected = 0;
   
     //assert    
    EXPECT_EQ(empty_list.size(), expected);
}

TEST_F(ListTestF, push_back)
{
    //arrange
    const int expected = 30;
    
    //act
    list.push_back(expected);

    u_list::iterator list_lust_it = list.begin();
    for (int j = 1; j < list.size(); ++j)
        ++list_lust_it;

    empty_list.push_back(expected);

    //assert    
    EXPECT_EQ(list_lust_it.get(), expected);
    EXPECT_EQ(empty_list.begin().get(), expected);
}

TEST_F(ListTestF, insert_begin)
{
    //arrange 
    const int expected = 10;

    //act
    list.insert(1, expected);

    //assert    
    EXPECT_EQ(list.begin().get(), expected);
}

TEST_F(ListTestF, insert_middle)
{
    //arrange 
    const int expected = 20;
    const int middle = (list.size() / 2) + 1;

    //act
    list.insert(middle, expected);

    u_list::iterator list_it = list.begin();
    for (int count = 1; count != middle; ++count)
        ++list_it;

    //assert    
    EXPECT_EQ(list_it.get(), expected);
}

TEST_F(ListTestF, insert_emptyList)
{
    //arrange 
    const int empty_expected = 0;

    //act
    empty_list.insert(1, empty_expected);

    //assert    
    EXPECT_EQ(empty_list.size(), empty_expected);
}

TEST_F(ListTestF, erase_back)
{
    //arrange 
    const int expected = list_start_size - 1;

    //act
    list.erase(list_start_size);    

    //assert    
    EXPECT_EQ(list.size(), expected);    
}

TEST_F(ListTestF, erase_begin)
{
    //arrange
    const int expected = list_start_size - 1;

    //act
    list.erase(1);

    //assert    
    EXPECT_EQ(list.size(), expected);
}

TEST_F(ListTestF, erase_middle)
{
    //arrange
    const int expected = list_start_size - 1;
    const int middle = (list.size() / 2) + 1;    

    //act
    list.erase(middle);

    //assert    
    EXPECT_EQ(list.size(), expected);
}

TEST_F(ListTestF, erase_emptyList)
{
    //arrange
    const int empty_expected = 0;

    //act
    empty_list.erase(list_start_size);

    //assert    
    EXPECT_EQ(empty_list.size(), empty_expected);
}

TEST_F(ListTestF, get_value)
{
    //arrange
    const int expected = 1;

    //act

    //assert    
    EXPECT_EQ(list.begin().get(), expected);
}

TEST_F(ListTestF, get_size)
{
    //arrange
    const int expected = list_start_size;
    const int empty_expected = 0;

    //act

    //assert    
    EXPECT_EQ(list.size(), expected);
    EXPECT_EQ(empty_list.size(), empty_expected);
}



int main(int argc, char** argv) {
    
    setlocale(LC_ALL, "Russian");

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}