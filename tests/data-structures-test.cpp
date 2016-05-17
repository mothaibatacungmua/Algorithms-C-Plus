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
    list = new DataStructures::SingleLinkedList<int>();

    queue = new DataStructures::Queue<int>();

    stack = new DataStructures::Stack<int>();

    c_db_list = new DataStructures::CircularDoublyLinkedList<int>();

    o_db_list = new DataStructures::OpenDoublyLinkedList<int>();

    pr_queue = new DataStructures::PriorityQueue<int>(100);

    hashmap = new DataStructures::Hashmap<int, int>(10);

}

void DataStructuresTest::tearDown(){
    delete list;

    delete queue;

    delete stack;

    delete c_db_list;

    delete o_db_list;

    delete pr_queue;

    delete hashmap;

}

void DataStructuresTest::testSingleLinkedListPush(){

    list->Push(3);

    //check
    CPPUNIT_ASSERT_EQUAL(1, list->Size());


}

void DataStructuresTest::testSingleLinkedListPop(){
    list->Push(3);
    list->Push(10);

    int head = list->Head();
    CPPUNIT_ASSERT_EQUAL(3, head);
    list->Pop();

    head = list->Head();
    CPPUNIT_ASSERT_EQUAL(10, head);
    list->Pop();


    list->Pop();
    CPPUNIT_ASSERT_MESSAGE("List must be empty",(list->Size() == 0));

}

void DataStructuresTest::testQueuePush(){
    queue->Push(3);
    CPPUNIT_ASSERT_EQUAL(1, queue->Size());

    queue->Push(4);
    CPPUNIT_ASSERT_EQUAL(2, queue->Size());
}

void DataStructuresTest::testQueuePop(){
    queue->Push(3);
    queue->Push(10);

    int head = queue->Head();
    CPPUNIT_ASSERT_EQUAL(3, head);
    queue->Pop();

    head = queue->Head();
    CPPUNIT_ASSERT_EQUAL(10, head);
    queue->Pop();

    queue->Pop();
    CPPUNIT_ASSERT_MESSAGE("Queue must be empty",(queue->Size() == 0));
}

void DataStructuresTest::testStackPush(){
    stack->Push(3);
    CPPUNIT_ASSERT_EQUAL(1, stack->Size());

    stack->Push(4);
    CPPUNIT_ASSERT_EQUAL(2, stack->Size());
}

void DataStructuresTest::testStackPop(){
    stack->Push(3);
    stack->Push(10);

    int head = stack->Head();
    CPPUNIT_ASSERT_EQUAL(10, head);
    stack->Pop();

    head = stack->Head();
    stack->Pop();
    CPPUNIT_ASSERT_EQUAL(3, head);

    stack->Pop();
    CPPUNIT_ASSERT_MESSAGE("Queue must be empty",(stack->Size() == 0));
}

void DataStructuresTest::testCircularDoublyLinkedListInsertBeginning(){
    c_db_list->InsertBeginning(12);

    CPPUNIT_ASSERT_EQUAL(1, c_db_list->Size());
    CPPUNIT_ASSERT_EQUAL(12, c_db_list->Head());
    CPPUNIT_ASSERT_MESSAGE("Tail must be equal head when size of list = 1",(c_db_list->Head() == c_db_list->Tail()));

    c_db_list->InsertBeginning(122);

    CPPUNIT_ASSERT_EQUAL(2, c_db_list->Size());
    CPPUNIT_ASSERT_EQUAL(122, c_db_list->Tail());
    CPPUNIT_ASSERT_MESSAGE("Tail must be head->prev",((int)c_db_list->tail == (int)c_db_list->head->prev));
    CPPUNIT_ASSERT_MESSAGE("Tail must be different from head when size of list > 1",(c_db_list->tail != c_db_list->head));
}

void DataStructuresTest::testCircularDoublyLinkedListInsertEnd(){
    c_db_list->InsertBeginning(102);

    CPPUNIT_ASSERT_EQUAL(1, c_db_list->Size());
    CPPUNIT_ASSERT_EQUAL(102, c_db_list->Tail());
    CPPUNIT_ASSERT_MESSAGE("Tail must be equal head when size of list = 1",(c_db_list->tail == c_db_list->head));

    c_db_list->InsertEnd(122);
    c_db_list->InsertEnd(1222);

    CPPUNIT_ASSERT_EQUAL(3, c_db_list->Size());
    CPPUNIT_ASSERT_EQUAL(1222, c_db_list->Tail());
    CPPUNIT_ASSERT_MESSAGE("Head must be tail->next",((int)c_db_list->tail->next == (int)c_db_list->head));
    CPPUNIT_ASSERT_MESSAGE("Tail must be different from head when size of list > 1",(c_db_list->tail != c_db_list->head));
}

void DataStructuresTest::testCircularDoublyLinkedListInsertAfter(){
    DataStructures::CircularDoublyLinkedList<int>::NodeCls* node_0, *node_1, *save = NULL;

    node_0 = c_db_list->InsertBeginning(1);
    save = (DataStructures::CircularDoublyLinkedList<int>::NodeCls*)node_0->next;
    node_1 = c_db_list->InsertAfter(node_0, 2);

    CPPUNIT_ASSERT_EQUAL((int)node_0->next, (int)node_1);
    CPPUNIT_ASSERT_EQUAL((int)node_1->prev, (int)node_0);
    CPPUNIT_ASSERT_EQUAL((int)node_1->next, (int)save);

}

void DataStructuresTest::testCircularDoublyLinkedListInsertBefore(){
    DataStructures::CircularDoublyLinkedList<int>::NodeCls* node_0, *node_1, *save = NULL;

    node_0 = c_db_list->InsertBeginning(1);
    save = (DataStructures::CircularDoublyLinkedList<int>::NodeCls*)node_0->prev;
    node_1 = c_db_list->InsertBefore(node_0, 2);

    CPPUNIT_ASSERT_EQUAL((int)node_0->prev, (int)node_1);
    CPPUNIT_ASSERT_EQUAL((int)node_1->next, (int)node_0);
    CPPUNIT_ASSERT_EQUAL((int)node_1->prev, (int)save);
}

void DataStructuresTest::testCircularDoublyLinkedListRemove(){
    DataStructures::CircularDoublyLinkedList<int>::NodeCls* node_0, *node_1, *node_2, *remove = NULL;

    node_0 = c_db_list->InsertBeginning(1);
    node_1 = c_db_list->InsertAfter(node_0, 2);
    node_2 = c_db_list->InsertAfter(node_1, 2);

    remove = c_db_list->Remove(node_1);

    CPPUNIT_ASSERT_EQUAL((int)remove, (int)node_1);
    CPPUNIT_ASSERT_EQUAL((int)node_0->next, (int)node_2);
    CPPUNIT_ASSERT_EQUAL((int)node_2->prev, (int)node_0);
}

void DataStructuresTest::testCircularDoublyLinkedListRemoveEnd(){
    DataStructures::CircularDoublyLinkedList<int>::NodeCls* save = NULL;

    c_db_list->InsertBeginning(1234);
    c_db_list->InsertBeginning(123);
    c_db_list->InsertBeginning(12);

    c_db_list->RemoveEnd();

    save = (DataStructures::CircularDoublyLinkedList<int>::NodeCls*)c_db_list->tail;
    CPPUNIT_ASSERT_EQUAL((int)save, (int)c_db_list->head->prev);
    CPPUNIT_ASSERT_EQUAL((int)save->next, (int)c_db_list->head);
}

void DataStructuresTest::testCircularDoublyLinkedListRemoveBeginning(){
    DataStructures::CircularDoublyLinkedList<int>::NodeCls* save = NULL;

    c_db_list->InsertBeginning(1234);
    c_db_list->InsertBeginning(123);
    c_db_list->InsertBeginning(12);

    c_db_list->RemoveBeginning();


    save = (DataStructures::CircularDoublyLinkedList<int>::NodeCls*)c_db_list->head;
    CPPUNIT_ASSERT_EQUAL((int)save, (int)c_db_list->tail->next);
    CPPUNIT_ASSERT_EQUAL((int)save->prev, (int)c_db_list->tail);
}

void DataStructuresTest::testOpenDoublyLinkedListInsertBeginning(){
    o_db_list->InsertBeginning(12);


    CPPUNIT_ASSERT_EQUAL(1, o_db_list->Size());
    CPPUNIT_ASSERT_EQUAL(12, o_db_list->Head());
    CPPUNIT_ASSERT_MESSAGE("Tail must be head",((int)o_db_list->head == (int)o_db_list->tail));

    o_db_list->InsertBeginning(122);

    CPPUNIT_ASSERT_EQUAL(2, o_db_list->Size());
    CPPUNIT_ASSERT_EQUAL(122, o_db_list->tail->value);
    CPPUNIT_ASSERT_MESSAGE("Tail->next must be null",((int)NULL == (int)o_db_list->tail->next));
}

void DataStructuresTest::testOpenDoublyLinkedListInsertEnd(){
    o_db_list->InsertEnd(12);

    CPPUNIT_ASSERT_EQUAL(1, o_db_list->Size());
    CPPUNIT_ASSERT_EQUAL(12,  o_db_list->tail->value);
    CPPUNIT_ASSERT_MESSAGE("Tail must be head",((int) o_db_list->head == (int) o_db_list->tail));

    o_db_list->InsertEnd(122);
    o_db_list->InsertEnd(123);

    CPPUNIT_ASSERT_EQUAL(3, o_db_list->Size());
    CPPUNIT_ASSERT_EQUAL(123,  o_db_list->tail->value);
    CPPUNIT_ASSERT_MESSAGE("Tail->next must be null",((int)NULL == (int) o_db_list->tail->next));
}

void DataStructuresTest::testOpenDoublyLinkedListInsertAfter(){
    DataStructures::OpenDoublyLinkedList<int>::NodeCls* node_0, *node_1, *save = NULL;

    node_0 = o_db_list->InsertBeginning(1);
    save = (DataStructures::OpenDoublyLinkedList<int>::NodeCls*)node_0->next;
    node_1 = o_db_list->InsertAfter(node_0, 2);

    CPPUNIT_ASSERT_EQUAL((int)node_0->next, (int)node_1);
    CPPUNIT_ASSERT_EQUAL((int)node_1->prev, (int)node_0);
    CPPUNIT_ASSERT_EQUAL((int)node_1->next, (int)save);

}

void DataStructuresTest::testOpenDoublyLinkedListInsertBefore(){
    DataStructures::OpenDoublyLinkedList<int>::NodeCls* node_0, *node_1, *save = NULL;

    node_0 = o_db_list->InsertBeginning(1);
    save = (DataStructures::OpenDoublyLinkedList<int>::NodeCls*)node_0->prev;
    node_1 = o_db_list->InsertBefore(node_0, 2);

    CPPUNIT_ASSERT_EQUAL((int)node_0->prev, (int)node_1);
    CPPUNIT_ASSERT_EQUAL((int)node_1->next, (int)node_0);
    CPPUNIT_ASSERT_EQUAL((int)node_1->prev, (int)save);
}

void DataStructuresTest::testOpenDoublyLinkedListRemove(){
    DataStructures::OpenDoublyLinkedList<int>::NodeCls* node_0, *node_1, *node_2, *remove = NULL;

    node_0 = o_db_list->InsertBeginning(1);
    node_1 = o_db_list->InsertAfter(node_0, 2);
    node_2 = o_db_list->InsertAfter(node_1, 2);

    remove = o_db_list->Remove(node_1);

    CPPUNIT_ASSERT_EQUAL((int)remove, (int)node_1);
    CPPUNIT_ASSERT_EQUAL((int)node_0->next, (int)node_2);
    CPPUNIT_ASSERT_EQUAL((int)node_2->prev, (int)node_0);
}

void DataStructuresTest::testOpenDoublyLinkedListRemoveEnd(){
    o_db_list->InsertEnd(1234);
    o_db_list->InsertEnd(123);
    o_db_list->InsertEnd(12);

    int tail = o_db_list->Tail();
    o_db_list->RemoveEnd();

    CPPUNIT_ASSERT_EQUAL((int)tail, 12);

    CPPUNIT_ASSERT_EQUAL(2, o_db_list->Size());
}

void DataStructuresTest::testOpenDoublyLinkedListRemoveBeginning(){
    o_db_list->InsertEnd(1234);
    o_db_list->InsertEnd(123);
    o_db_list->InsertEnd(12);

    int head = o_db_list->Head();
    o_db_list->RemoveBeginning();

    CPPUNIT_ASSERT_EQUAL((int)head, 1234);

    CPPUNIT_ASSERT_EQUAL(2, o_db_list->Size());
}

void DataStructuresTest::testPriorityQueuePush(){
    pr_queue->Push(10);
    pr_queue->Push(7);
    pr_queue->Push(4);
    pr_queue->Push(22);
    pr_queue->Push(15);
    pr_queue->Push(18);

    CPPUNIT_ASSERT_EQUAL(6, pr_queue->Size());
    CPPUNIT_ASSERT_EQUAL(4, (*pr_queue)[0]);
    CPPUNIT_ASSERT_EQUAL(10, (*pr_queue)[1]);
    CPPUNIT_ASSERT_EQUAL(7, (*pr_queue)[2]);
    CPPUNIT_ASSERT_EQUAL(22, (*pr_queue)[3]);
    CPPUNIT_ASSERT_EQUAL(15, (*pr_queue)[4]);
    CPPUNIT_ASSERT_EQUAL(18, (*pr_queue)[5]);

}

void DataStructuresTest::testPriorityQueuePop(){
    pr_queue->Push(10);
    pr_queue->Push(7);
    pr_queue->Push(4);
    pr_queue->Push(22);
    pr_queue->Push(15);
    pr_queue->Push(18);

    int pop_value = pr_queue->Head();
    pr_queue->Pop();
    CPPUNIT_ASSERT_EQUAL(5, pr_queue->Size());
    CPPUNIT_ASSERT_EQUAL(4, pop_value);
    CPPUNIT_ASSERT_EQUAL(7, (*pr_queue)[0]);
    CPPUNIT_ASSERT_EQUAL(18, (*pr_queue)[2]);
}

void DataStructuresTest::testHashMapSet(){
    /* TODO */
}

void DataStructuresTest::testHashMapGet(){
    /* TODO */
}

void DataStructuresTest::testInitVector(){
    /* TODO */
    int a[] = {1,2,3,4};

    DataStructures::Vector<int> int_vect(a,4);

    CPPUNIT_ASSERT_EQUAL(1, int_vect[0]);
    CPPUNIT_ASSERT_EQUAL(2, int_vect[1]);
    CPPUNIT_ASSERT_EQUAL(3, int_vect[2]);
    CPPUNIT_ASSERT_EQUAL(4, int_vect[3]);

    std::string s[] = {"a", "b", "c", "d"};

    DataStructures::Vector<string> string_vect(s,4);
    CPPUNIT_ASSERT_MESSAGE("Element 0 must have been 'a'", ("a" == string_vect[0]));
    CPPUNIT_ASSERT_MESSAGE("Element 1 must have been 'b'", ("b" == string_vect[1]));
    CPPUNIT_ASSERT_MESSAGE("Element 2 must have been 'c'", ("c" == string_vect[2]));
    CPPUNIT_ASSERT_MESSAGE("Element 3 must have been 'd'", ("d" == string_vect[3]));
}

void DataStructuresTest::testInitMatrix(){
    /* TODO */
    int c_0[4] = {1,2,3,4};
    int c_1[4] = {5,6,7,8};
    int c_2[4] = {9,10,11,12};
    int c_3[4] = {13,14,15,16};

    DataStructures::Vector<int> m_0[] = {
            DataStructures::Vector<int>(c_0,4),
            DataStructures::Vector<int>(c_1,4),
            DataStructures::Vector<int>(c_2,4),
            DataStructures::Vector<int>(c_3,4)
    };


    DataStructures::Matrix<int> int_mat_0(m_0, 4);
    DataStructures::Matrix<int> int_mat_1(m_0, 4, false);

    CPPUNIT_ASSERT_EQUAL(1, int_mat_0[0][0]);
    CPPUNIT_ASSERT_EQUAL(5, int_mat_0[0][1]);
    CPPUNIT_ASSERT_EQUAL(11, int_mat_0[2][2]);
    CPPUNIT_ASSERT_EQUAL(16, int_mat_0[3][3]);


    CPPUNIT_ASSERT_EQUAL(1, int_mat_1[0][0]);
    CPPUNIT_ASSERT_EQUAL(2, int_mat_1[0][1]);
    CPPUNIT_ASSERT_EQUAL(11, int_mat_1[2][2]);
    CPPUNIT_ASSERT_EQUAL(16, int_mat_1[3][3]);
}

void DataStructuresTest::testInitGraph(){
    /* TODO */
    DataStructures::Graph graph(10);
}
