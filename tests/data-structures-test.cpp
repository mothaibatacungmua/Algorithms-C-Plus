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

    queue_0 = new WrapperDataStr::Queue<int>();
    queue_1 = new WrapperDataStr::Queue<int>();

    stack_0 = new WrapperDataStr::Stack<int>();
    stack_1 = new WrapperDataStr::Stack<int>();
}

void DataStructuresTest::tearDown(){
    delete list_0;
    delete list_1;
    delete queue_0;
    delete queue_1;
    delete stack_0;
    delete stack_1;
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

void DataStructuresTest::testQueuePush(){
    queue_0->Push(3);
    CPPUNIT_ASSERT_EQUAL(1, queue_0->GetCount());

    queue_0->Push(4);
    CPPUNIT_ASSERT_EQUAL(2, queue_0->GetCount());
}

void DataStructuresTest::testQueuePop(){
    WrapperDataStr::Queue<int>::Node* pop_node = NULL;
    queue_1->Push(3);
    queue_1->Push(10);

    pop_node = queue_1->Pop();
    CPPUNIT_ASSERT_EQUAL(3, pop_node->value);
    delete pop_node;    //always remember this after popping

    pop_node = queue_1->Pop();
    CPPUNIT_ASSERT_EQUAL(10, pop_node->value);
    delete pop_node;    //always remember this after popping

    pop_node = queue_1->Pop();
    CPPUNIT_ASSERT_MESSAGE("Queue must be empty",(pop_node == NULL));
}

void DataStructuresTest::testStackPush(){
    stack_0->Push(3);
    CPPUNIT_ASSERT_EQUAL(1, stack_0->GetCount());

    stack_0->Push(4);
    CPPUNIT_ASSERT_EQUAL(2, stack_0->GetCount());
}

void DataStructuresTest::testStackPop(){
    WrapperDataStr::Stack<int>::Node* pop_node = NULL;
    stack_1->Push(3);
    stack_1->Push(10);

    pop_node = stack_1->Pop();
    CPPUNIT_ASSERT_EQUAL(10, pop_node->value);
    delete pop_node;    //always remember this after popping

    pop_node = stack_1->Pop();
    CPPUNIT_ASSERT_EQUAL(3, pop_node->value);
    delete pop_node;    //always remember this after popping

    pop_node = stack_1->Pop();
    CPPUNIT_ASSERT_MESSAGE("Queue must be empty",(pop_node == NULL));
}


