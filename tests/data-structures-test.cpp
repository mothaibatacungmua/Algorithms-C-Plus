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
    list_0 = new DataStructures::SingleLinkedList<int>();
    list_1 = new DataStructures::SingleLinkedList<int>();

    queue_0 = new DataStructures::Queue<int>();
    queue_1 = new DataStructures::Queue<int>();

    stack_0 = new DataStructures::Stack<int>();
    stack_1 = new DataStructures::Stack<int>();

    c_db_list_0 = new DataStructures::CircularDoublyLinkedList<int>();
    c_db_list_1 = new DataStructures::CircularDoublyLinkedList<int>();

    o_db_list_0 = new DataStructures::OpenDoublyLinkedList<int>();
    o_db_list_1 = new DataStructures::OpenDoublyLinkedList<int>();
}

void DataStructuresTest::tearDown(){
    delete list_0;
    delete list_1;
    delete queue_0;
    delete queue_1;
    delete stack_0;
    delete stack_1;
    delete c_db_list_0;
    delete c_db_list_1;
    delete o_db_list_0;
    delete o_db_list_1;
}

void DataStructuresTest::testSingleLinkedListPush(){

    list_0->Push(3);

    //check
    CPPUNIT_ASSERT_EQUAL(1, list_0->GetCount());


}

void DataStructuresTest::testSingleLinkedListPop(){
    DataStructures::SingleLinkedList<int>::Node* pop_node = NULL;
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
    DataStructures::Queue<int>::Node* pop_node = NULL;
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
    DataStructures::Stack<int>::Node* pop_node = NULL;
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

void DataStructuresTest::testCircularDoublyLinkedListInsertBeginning(){

}

void DataStructuresTest::testCircularDoublyLinkedListInsertEnd(){

}

void DataStructuresTest::testCircularDoublyLinkedListInsertAfter(){

}

void DataStructuresTest::testCircularDoublyLinkedListInsertBefore(){

}

void DataStructuresTest::testCircularDoublyLinkedListRemove(){

}

void DataStructuresTest::testCircularDoublyLinkedListRemoveEnd(){

}

void DataStructuresTest::testCircularDoublyLinkedListRemoveBeginning(){

}

void DataStructuresTest::testOpenDoublyLinkedListInsertBeginning(){

}

void DataStructuresTest::testOpenDoublyLinkedListInsertEnd(){

}

void DataStructuresTest::testOpenDoublyLinkedListInsertAfter(){

}

void DataStructuresTest::testOpenDoublyLinkedListInsertBefore(){

}

void DataStructuresTest::testOpenDoublyLinkedListRemove(){

}

void DataStructuresTest::testOpenDoublyLinkedListRemoveEnd(){

}

void DataStructuresTest::testOpenDoublyLinkedListRemoveBeginning(){

}
