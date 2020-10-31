/*!
 * @file run_tests.cpp
 * @brief Programa para executar testes.
 * @date 28 de Outubro de 2020
 * @author Karina Maria
 * @author Maria Eduarda
 */

#include <iostream>

#include "../lib/test_manager.h"

#include "../include/vector.h"
using namespace sc;

int main(void){
	// Creates a test manager for the DAL class.
    TestManager tm{ "Default Constructor Test Suite" };

    {
        //=== Test #1
        BEGIN_TEST(tm, "SizeVector", "vector size." );
        sc::vector<int> vec;

    	EXPECT_EQ( vec.size(), 0 );
    }

    {
        BEGIN_TEST(tm, "CapacityVector", "vector capacity." );
        sc::vector<int> vec;

    	EXPECT_EQ( vec.capacity(), 0 );
    }

    {
        BEGIN_TEST(tm, "EmptyVector", "vector empty." );
        sc::vector<int> vec;

    	EXPECT_EQ( vec.empty(), true);
    }

    tm.summary();
    std::cout << std::endl;

    // Creates a test manager for the DAL class.
    TestManager tm2{ "Size Constructor Test Suite" };

    {
        //=== Test #1
        BEGIN_TEST(tm2, "SizeVector", "vector size." );
        sc::vector<int> vec(10);

    	EXPECT_EQ( vec.size(), 0 );
    }

    {
        BEGIN_TEST(tm2, "CapacityVector", "vector capacity." );
        sc::vector<int> vec(10);

    	EXPECT_EQ( vec.capacity(), 10 );
    }

    {
        BEGIN_TEST(tm2, "EmptyVector", "vector empty." );
        sc::vector<int> vec(10);

    	EXPECT_EQ( vec.empty(), true);
    }

    tm2.summary();
    std::cout << std::endl;

	return EXIT_SUCCESS;
}