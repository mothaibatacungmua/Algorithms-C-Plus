/*
 * data-structures-test.hpp
 *
 *  Created on: Apr 17, 2016
 *      Author: asm
 */

#ifndef DATA_STRUCTURES_TEST_HPP_
#define DATA_STRUCTURES_TEST_HPP_

#include <cppunit/extensions/HelperMacros.h>
#include <string>
#include "../headers/data-structures.hpp"

class DataStructuresTest : public CppUnit::TestCase {
    CPPUNIT_TEST_SUITE( DataStructuresTest );
    CPPUNIT_TEST( testSingleLinkedListPush);
    CPPUNIT_TEST( testSingleLinkedListPop);
    CPPUNIT_TEST( testQueuePush);
    CPPUNIT_TEST( testQueuePop);
    CPPUNIT_TEST( testStackPush);
    CPPUNIT_TEST( testStackPop);
    CPPUNIT_TEST_SUITE_END();
private:
    DataStructures::SingleLinkedList<int> * list_0, *list_1;

    DataStructures::Queue<int> * queue_0, *queue_1;

    DataStructures::Stack<int> * stack_0, *stack_1;

public:
    void setUp();

    void tearDown();

    void testSingleLinkedListPush();

    void testSingleLinkedListPop();

    void testQueuePush();

    void testQueuePop();

    void testStackPush();

    void testStackPop();
};

#endif /* DATA_STRUCTURES_TEST_HPP_ */
