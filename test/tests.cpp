#include <iterator>             // std::begin(), std::end()
#include <functional>           // std::function
#include <algorithm>            // std::min_element

#include "gtest/gtest.h"        // gtest lib
#include "../include/vector.h"   // header file for tested functions



// ============================================================================
// TESTING VECTOR AS A CONTAINER OF INTEGERS
// ============================================================================

TEST(IntVector, DefaultConstructor)
{
    sc::vector<int> vec;

    EXPECT_EQ( vec.size(), 0 );
    EXPECT_EQ( vec.capacity(), 0);
    EXPECT_TRUE( vec.empty() );
}

TEST(IntVector, ConstructorSize)
{
    sc::vector<int> vec(10);

    EXPECT_EQ( vec.size(), 0 );
    EXPECT_EQ( vec.capacity(), 10 );
    EXPECT_TRUE( vec.empty() );
}


TEST(IntVector, ListConstructor)
{
    sc::vector<int> vec{ 1, 2, 3, 4, 5 };
    ASSERT_EQ( vec.size(), 5 );
    EXPECT_FALSE( vec.empty() );

    for( auto i{0u} ; i < vec.size() ; ++i )
        ASSERT_EQ( i+1, vec[i] );
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
