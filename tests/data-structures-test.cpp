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
    list_1 = new WrapperDataStr::SingleLinkedList<int>();
}

void DataStructuresTest::tearDown(){
    delete list_0;
    delete list_1;
}

void DataStructuresTest::testSingleLinkedListPush(){

    list_0->Push(3);

    //check
    CPPUNIT_ASSERT_EQUAL(1, list_0->GetCount());


}

void DataStructuresTest::testSingleLinkedListPop(){
    WrapperDataStr::SingleLinkedList<int>::Node* pop_node = NULL;
    list_1->Push(3);
    list_1->Push(10);

    pop_node = list_1->Pop();
    CPPUNIT_ASSERT_EQUAL(3, pop_node->value);
    delete pop_node;    //always remember this after popping

    pop_node = list_1->Pop();
    CPPUNIT_ASSERT_EQUAL(10, pop_node->value);
    delete pop_node;    //always remember this after popping

    pop_node = list_1->Pop();

    CPPUNIT_ASSERT_MESSAGE("List must be empty",(pop_node == NULL));

}



