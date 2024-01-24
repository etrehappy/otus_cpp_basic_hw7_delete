#include "tests_main.h"
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
    }
};

TEST_F(ListTestF, create)
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
    u_list::iterator list_lust_it = get_lust_iterator(list, list.begin());

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

TEST_F(ListTestF, extra1_copy)
{
    //arrange
    u_list list2 = list;
    bool expected_size = false;
    bool expected_arr = false;
    u_list::iterator it1 = list.begin();
    u_list::iterator it2 = list2.begin();

    //act
    if (list2.size() == list.size())
        expected_size = true;

    while (it2 != list2.end())
    {
        if (it1.get() != it2.get())
        {
            expected_arr = false;
            break;
        }

        ++it1;
        ++it2;
        expected_arr = true;
    }

    //assert    
    EXPECT_TRUE(expected_size);
    EXPECT_TRUE(expected_arr);
}

TEST_F(ListTestF, extra3_move)
{
    //arange
    u_list list2;
    int list_start = list.begin().get();

    u_list::iterator list_lust_it = get_lust_iterator(list, list.begin());
    int list_lust = list_lust_it.get();

    //act
    list2 = std::move(list);

    u_list::iterator list2_lust_it = get_lust_iterator(list2, list2.begin());
    int list2_lust = list2_lust_it.get();

    //assert
    EXPECT_EQ(list_start, list2.begin().get());
    EXPECT_EQ(list_lust, list2_lust);

    EXPECT_EQ(0, list.size());
}


