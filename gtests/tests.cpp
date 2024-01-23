#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <locale>

#include "u_list.h"
#include "u_vector.h"

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




//======================================================




struct VectorTestF : public testing::Test
{
    //arrange
    u_vector<int> vector;
    u_vector<int> empty_vector;
    const int vector_start_size = 4;

    void SetUp() override
    {
        for (int i = 1; i <= vector_start_size; i++)
            vector.push_back(i);

        /*for (u_vector::iterator it = vector.begin(); it != vector.end(); ++it)
            list_lust_it = it;*/
    }
};

TEST_F(VectorTestF, create_vector)
{
    //arrange
    const int expected = 0;

    //assert    
    EXPECT_EQ(empty_vector.size(), expected);
}

TEST_F(VectorTestF, push_back)
{
    //arrange
    const int expected = 30;

    //act
    vector.push_back(expected);

    u_vector<int>::iterator vector_lust_it = vector.begin();
    for (int j = 1; j < vector.size(); ++j)
        ++vector_lust_it;

    empty_vector.push_back(expected);

    //assert    
    EXPECT_EQ(vector_lust_it.get(), expected);
    EXPECT_EQ(empty_vector.begin().get(), expected);
}

TEST_F(VectorTestF, insert_begin)
{
    //arrange 
    const int expected = 10;

    //act
    vector.insert(1, expected);

    //assert    
    EXPECT_EQ(vector.begin().get(), expected);
}

TEST_F(VectorTestF, insert_middle)
{
    //arrange 
    const int expected = 20;
    const int middle = (vector.size() / 2) + 1;

    //act
    vector.insert(middle, expected);

    u_vector<int>::iterator it = vector.begin();
    for (int count = 1; count != middle; ++count)
        ++it;

    //assert    
    EXPECT_EQ(it.get(), expected);
}

TEST_F(VectorTestF, insert_emptyVector)
{
    //arrange 
    const int empty_expected = 0;

    //act
    empty_vector.insert(1, empty_expected);

    //assert    
    EXPECT_EQ(empty_vector.size(), empty_expected);
}

TEST_F(VectorTestF, erase_back)
{
    //arrange 
    const int expected = vector_start_size - 1;

    //act
    vector.erase(vector_start_size);

    //assert    
    EXPECT_EQ(vector.size(), expected);
}

TEST_F(VectorTestF, erase_begin)
{
    //arrange
    const int expected = vector_start_size - 1;

    //act
    vector.erase(1);

    //assert    
    EXPECT_EQ(vector.size(), expected);
}

TEST_F(VectorTestF, erase_middle)
{
    //arrange
    const int expected = vector_start_size - 1;
    const int middle = (vector.size() / 2) + 1;

    //act
    vector.erase(middle);

    //assert    
    EXPECT_EQ(vector.size(), expected);
}

TEST_F(VectorTestF, erase_emptyVector)
{
    //arrange
    const int empty_expected = 0;

    //act
    empty_vector.erase(vector_start_size);

    //assert    
    EXPECT_EQ(empty_vector.size(), empty_expected);
}

TEST_F(VectorTestF, get_value)
{
    //arrange
    const int expected = 1;

    //act

    //assert    
    EXPECT_EQ(vector.begin().get(), expected);
}

TEST_F(VectorTestF, get_size)
{
    //arrange
    const int expected = vector_start_size;
    const int empty_expected = 0;

    //act

    //assert    
    EXPECT_EQ(vector.size(), expected);
    EXPECT_EQ(empty_vector.size(), empty_expected);
}





int main(int argc, char** argv) {
    
    std::locale::global(std::locale("en_US.utf8"));   

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}