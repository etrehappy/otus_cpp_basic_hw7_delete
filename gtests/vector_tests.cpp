#include "tests_main.h"

#include "u_vector.h"

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
    }
};

TEST_F(VectorTestF, create)
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

    u_vector<int>::iterator vector_lust_it = get_lust_iterator(vector, vector.begin());

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

TEST_F(VectorTestF, extra1_copy)
{
    //arrange
    u_vector<int> vector2 = vector;
    bool expected_size = false;
    bool expected_arr = false;
    u_vector<int>::iterator it1 = vector.begin();
    u_vector<int>::iterator it2 = vector2.begin();

    //act
    if (vector2.size() == vector.size())
        expected_size = true;

    while (it2 != vector2.end())
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

TEST_F(VectorTestF, extra3_move)
{
    //arange
    u_vector<int> vector2;
    int vec_start = vector.begin().get();

    u_vector<int>::iterator vector_lust_it = get_lust_iterator(vector, vector.begin());
    int vec_lust = vector_lust_it.get();

    //act
    vector2 = std::move(vector);

    u_vector<int>::iterator vector2_lust_it = get_lust_iterator(vector2, vector2.begin());
    int vec2_lust = vector2_lust_it.get();

    //assert
    EXPECT_EQ(vec_start, vector2.begin().get());
    EXPECT_EQ(vec_lust, vec2_lust);

    EXPECT_EQ(0, vector.size());
}

