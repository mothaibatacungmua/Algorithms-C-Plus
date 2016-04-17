/*
 * data-structures-test.cpp
 *
 *  Created on: Apr 17, 2016
 *      Author: asm
 */
#include "data-structures-test.hpp"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( DataStructuresTest);

void DataStructuresTest::setUp(){
    list_0 = new WrapperDataStr::SingleLinkedList<int>();
}

void DataStructuresTest::tearDown(){
    delete list_0;
}

void DataStructuresTest::testSingleLinkedListPush(){

    list_0->Push(3);

    //check
    CPPUNIT_ASSERT_EQUAL(2, list_0->GetCount());


}



