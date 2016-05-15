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
    CPPUNIT_TEST( testCircularDoublyLinkedListInsertBeginning);
    CPPUNIT_TEST( testCircularDoublyLinkedListInsertEnd);
    CPPUNIT_TEST( testCircularDoublyLinkedListInsertAfter);
    CPPUNIT_TEST( testCircularDoublyLinkedListInsertBefore);
    CPPUNIT_TEST( testCircularDoublyLinkedListRemove);
    CPPUNIT_TEST( testCircularDoublyLinkedListRemoveEnd);
    CPPUNIT_TEST( testCircularDoublyLinkedListRemoveBeginning);
    CPPUNIT_TEST( testOpenDoublyLinkedListInsertBeginning);
    CPPUNIT_TEST( testOpenDoublyLinkedListInsertEnd);
    CPPUNIT_TEST( testOpenDoublyLinkedListInsertAfter);
    CPPUNIT_TEST( testOpenDoublyLinkedListInsertBefore);
    CPPUNIT_TEST( testOpenDoublyLinkedListRemove);
    CPPUNIT_TEST( testOpenDoublyLinkedListRemoveEnd);
    CPPUNIT_TEST( testOpenDoublyLinkedListRemoveBeginning);
    CPPUNIT_TEST( testPriorityQueuePush);
    CPPUNIT_TEST( testPriorityQueuePop);
    CPPUNIT_TEST_SUITE_END();
private:
    DataStructures::SingleLinkedList<int>* list_0, *list_1;

    DataStructures::Queue<int>* queue_0, *queue_1;

    DataStructures::Stack<int>* stack_0, *stack_1;

    DataStructures::CircularDoublyLinkedList<int>* c_db_list_0, *c_db_list_1;

    DataStructures::OpenDoublyLinkedList<int>* o_db_list_0, *o_db_list_1;

    DataStructures::PriorityQueue<int>* pr_queue;

    DataStructures::Hashmap<int, int>* hashmap;


public:
    void setUp();

    void tearDown();

    void testSingleLinkedListPush();

    void testSingleLinkedListPop();

    void testQueuePush();

    void testQueuePop();

    void testStackPush();

    void testStackPop();

    void testCircularDoublyLinkedListInsertBeginning();

    void testCircularDoublyLinkedListInsertEnd();

    void testCircularDoublyLinkedListInsertAfter();

    void testCircularDoublyLinkedListInsertBefore();

    void testCircularDoublyLinkedListRemove();

    void testCircularDoublyLinkedListRemoveEnd();

    void testCircularDoublyLinkedListRemoveBeginning();

    void testOpenDoublyLinkedListInsertBeginning();

    void testOpenDoublyLinkedListInsertEnd();

    void testOpenDoublyLinkedListInsertAfter();

    void testOpenDoublyLinkedListInsertBefore();

    void testOpenDoublyLinkedListRemove();

    void testOpenDoublyLinkedListRemoveEnd();

    void testOpenDoublyLinkedListRemoveBeginning();

    void testPriorityQueuePush();

    void testPriorityQueuePop();

    void testHashMapSet();

    void testHashMapGet();

    void testInitVector();

    void testInitMatrix();

    void testInitGraph();


};

#endif /* DATA_STRUCTURES_TEST_HPP_ */
