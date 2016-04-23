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
    DataStructures::CircularDoublyLinkedList<int>::Node* head = NULL;
    DataStructures::CircularDoublyLinkedList<int>::Node* tail = NULL;
    c_db_list_0->InsertBeginning(12);

    head = (DataStructures::CircularDoublyLinkedList<int>::Node*)c_db_list_0->head;
    tail = (DataStructures::CircularDoublyLinkedList<int>::Node*)c_db_list_0->tail;

    CPPUNIT_ASSERT_EQUAL(1, c_db_list_0->GetCount());
    CPPUNIT_ASSERT_EQUAL(12, head->value);
    CPPUNIT_ASSERT_MESSAGE("Tail must be equal head when size of list = 1",(tail == head));

    c_db_list_0->InsertBeginning(122);

    tail = (DataStructures::CircularDoublyLinkedList<int>::Node*)c_db_list_0->tail;
    CPPUNIT_ASSERT_EQUAL(2, c_db_list_0->GetCount());
    CPPUNIT_ASSERT_EQUAL(122, tail->value);
    CPPUNIT_ASSERT_MESSAGE("Tail must be head->prev",((int)tail == (int)head->prev));
    CPPUNIT_ASSERT_MESSAGE("Tail must be different from head when size of list > 1",(tail != head));
}

void DataStructuresTest::testCircularDoublyLinkedListInsertEnd(){
    DataStructures::CircularDoublyLinkedList<int>::Node* head = NULL;
    DataStructures::CircularDoublyLinkedList<int>::Node* tail = NULL;
    c_db_list_0->InsertBeginning(102);

    head = (DataStructures::CircularDoublyLinkedList<int>::Node*)c_db_list_0->head;
    tail = (DataStructures::CircularDoublyLinkedList<int>::Node*)c_db_list_0->tail;

    CPPUNIT_ASSERT_EQUAL(1, c_db_list_0->GetCount());
    CPPUNIT_ASSERT_EQUAL(102, tail->value);
    CPPUNIT_ASSERT_MESSAGE("Tail must be equal head when size of list = 1",(tail == head));

    c_db_list_0->InsertEnd(122);
    c_db_list_0->InsertEnd(1222);

    tail = (DataStructures::CircularDoublyLinkedList<int>::Node*)c_db_list_0->tail;
    CPPUNIT_ASSERT_EQUAL(3, c_db_list_0->GetCount());
    CPPUNIT_ASSERT_EQUAL(1222, tail->value);
    CPPUNIT_ASSERT_MESSAGE("Head must be tail->next",((int)tail->next == (int)head));
    CPPUNIT_ASSERT_MESSAGE("Tail must be different from head when size of list > 1",(tail != head));
}

void DataStructuresTest::testCircularDoublyLinkedListInsertAfter(){
    DataStructures::CircularDoublyLinkedList<int>::Node* node_0, *node_1, *save = NULL;

    node_0 = c_db_list_0->InsertBeginning(1);
    save = (DataStructures::CircularDoublyLinkedList<int>::Node*)node_0->next;
    node_1 = c_db_list_0->InsertAfter(node_0, 2);

    CPPUNIT_ASSERT_EQUAL((int)node_0->next, (int)node_1);
    CPPUNIT_ASSERT_EQUAL((int)node_1->prev, (int)node_0);
    CPPUNIT_ASSERT_EQUAL((int)node_1->next, (int)save);

}

void DataStructuresTest::testCircularDoublyLinkedListInsertBefore(){
    DataStructures::CircularDoublyLinkedList<int>::Node* node_0, *node_1, *save = NULL;

    node_0 = c_db_list_0->InsertBeginning(1);
    save = (DataStructures::CircularDoublyLinkedList<int>::Node*)node_0->prev;
    node_1 = c_db_list_0->InsertBefore(node_0, 2);

    CPPUNIT_ASSERT_EQUAL((int)node_0->prev, (int)node_1);
    CPPUNIT_ASSERT_EQUAL((int)node_1->next, (int)node_0);
    CPPUNIT_ASSERT_EQUAL((int)node_1->prev, (int)save);
}

void DataStructuresTest::testCircularDoublyLinkedListRemove(){
    DataStructures::CircularDoublyLinkedList<int>::Node* node_0, *node_1, *node_2, *remove = NULL;

    node_0 = c_db_list_1->InsertBeginning(1);
    node_1 = c_db_list_1->InsertAfter(node_0, 2);
    node_2 = c_db_list_1->InsertAfter(node_1, 2);

    remove = c_db_list_1->Remove(node_1);

    CPPUNIT_ASSERT_EQUAL((int)remove, (int)node_1);
    CPPUNIT_ASSERT_EQUAL((int)node_0->next, (int)node_2);
    CPPUNIT_ASSERT_EQUAL((int)node_2->prev, (int)node_0);
}

void DataStructuresTest::testCircularDoublyLinkedListRemoveEnd(){
    DataStructures::CircularDoublyLinkedList<int>::Node* save, *remove = NULL;

    c_db_list_1->InsertBeginning(1234);
    c_db_list_1->InsertBeginning(123);
    c_db_list_1->InsertBeginning(12);
    save = (DataStructures::CircularDoublyLinkedList<int>::Node*)c_db_list_1->tail;

    remove = c_db_list_1->RemoveEnd();

    CPPUNIT_ASSERT_EQUAL((int)remove, (int)save);
    delete remove;

    save = (DataStructures::CircularDoublyLinkedList<int>::Node*)c_db_list_1->tail;
    CPPUNIT_ASSERT_EQUAL((int)save, (int)c_db_list_1->head->prev);
    CPPUNIT_ASSERT_EQUAL((int)save->next, (int)c_db_list_1->head);
}

void DataStructuresTest::testCircularDoublyLinkedListRemoveBeginning(){
    DataStructures::CircularDoublyLinkedList<int>::Node* save, *remove = NULL;

    c_db_list_1->InsertBeginning(1234);
    c_db_list_1->InsertBeginning(123);
    c_db_list_1->InsertBeginning(12);
    save = (DataStructures::CircularDoublyLinkedList<int>::Node*)c_db_list_1->head;

    remove = c_db_list_1->RemoveBeginning();

    CPPUNIT_ASSERT_EQUAL((int)remove, (int)save);
    delete remove;

    save = (DataStructures::CircularDoublyLinkedList<int>::Node*)c_db_list_1->head;
    CPPUNIT_ASSERT_EQUAL((int)save, (int)c_db_list_1->tail->next);
    CPPUNIT_ASSERT_EQUAL((int)save->prev, (int)c_db_list_1->tail);
}

void DataStructuresTest::testOpenDoublyLinkedListInsertBeginning(){
    DataStructures::OpenDoublyLinkedList<int>::Node* head = NULL;
    DataStructures::OpenDoublyLinkedList<int>::Node* tail = NULL;
    o_db_list_0->InsertBeginning(12);

    head = (DataStructures::OpenDoublyLinkedList<int>::Node*)o_db_list_0->head;
    tail = (DataStructures::OpenDoublyLinkedList<int>::Node*)o_db_list_0->tail;

    CPPUNIT_ASSERT_EQUAL(1, o_db_list_0->GetCount());
    CPPUNIT_ASSERT_EQUAL(12, head->value);
    CPPUNIT_ASSERT_MESSAGE("Tail must be head",((int)head == (int)tail));

    o_db_list_0->InsertBeginning(122);

    tail = (DataStructures::OpenDoublyLinkedList<int>::Node*)o_db_list_0->tail;
    CPPUNIT_ASSERT_EQUAL(2, o_db_list_0->GetCount());
    CPPUNIT_ASSERT_EQUAL(122, tail->value);
    CPPUNIT_ASSERT_MESSAGE("Tail->next must be null",((int)NULL == (int)tail->next));
}

void DataStructuresTest::testOpenDoublyLinkedListInsertEnd(){
    DataStructures::OpenDoublyLinkedList<int>::Node* head = NULL;
    DataStructures::OpenDoublyLinkedList<int>::Node* tail = NULL;
    o_db_list_0->InsertEnd(12);

    head = (DataStructures::OpenDoublyLinkedList<int>::Node*)o_db_list_0->head;
    tail = (DataStructures::OpenDoublyLinkedList<int>::Node*)o_db_list_0->tail;

    CPPUNIT_ASSERT_EQUAL(1, o_db_list_0->GetCount());
    CPPUNIT_ASSERT_EQUAL(12, tail->value);
    CPPUNIT_ASSERT_MESSAGE("Tail must be head",((int)head == (int)tail));

    o_db_list_0->InsertEnd(122);
    o_db_list_0->InsertEnd(123);

    tail = (DataStructures::OpenDoublyLinkedList<int>::Node*)o_db_list_0->tail;
    CPPUNIT_ASSERT_EQUAL(3, o_db_list_0->GetCount());
    CPPUNIT_ASSERT_EQUAL(123, tail->value);
    CPPUNIT_ASSERT_MESSAGE("Tail->next must be null",((int)NULL == (int)tail->next));
}

void DataStructuresTest::testOpenDoublyLinkedListInsertAfter(){
    DataStructures::OpenDoublyLinkedList<int>::Node* node_0, *node_1, *save = NULL;

    node_0 = o_db_list_0->InsertBeginning(1);
    save = (DataStructures::OpenDoublyLinkedList<int>::Node*)node_0->next;
    node_1 = o_db_list_0->InsertAfter(node_0, 2);

    CPPUNIT_ASSERT_EQUAL((int)node_0->next, (int)node_1);
    CPPUNIT_ASSERT_EQUAL((int)node_1->prev, (int)node_0);
    CPPUNIT_ASSERT_EQUAL((int)node_1->next, (int)save);

}

void DataStructuresTest::testOpenDoublyLinkedListInsertBefore(){
    DataStructures::OpenDoublyLinkedList<int>::Node* node_0, *node_1, *save = NULL;

    node_0 = o_db_list_0->InsertBeginning(1);
    save = (DataStructures::OpenDoublyLinkedList<int>::Node*)node_0->prev;
    node_1 = o_db_list_0->InsertBefore(node_0, 2);

    CPPUNIT_ASSERT_EQUAL((int)node_0->prev, (int)node_1);
    CPPUNIT_ASSERT_EQUAL((int)node_1->next, (int)node_0);
    CPPUNIT_ASSERT_EQUAL((int)node_1->prev, (int)save);
}

void DataStructuresTest::testOpenDoublyLinkedListRemove(){

}

void DataStructuresTest::testOpenDoublyLinkedListRemoveEnd(){

}

void DataStructuresTest::testOpenDoublyLinkedListRemoveBeginning(){

}
