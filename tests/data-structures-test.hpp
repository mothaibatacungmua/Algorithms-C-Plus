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
    CPPUNIT_TEST_SUITE_END();
private:
    WrapperDataStr::SingleLinkedList<int> * list_0;
public:
    void setUp();

    void tearDown();

    void testSingleLinkedListPush();
};

#endif /* DATA_STRUCTURES_TEST_HPP_ */
