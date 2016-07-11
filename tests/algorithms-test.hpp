/*
 * algorithms-test.hpp
 *
 *  Created on: May 17, 2016
 *      Author: asm
 */

#ifndef ALGORITHMS_TEST_HPP_
#define ALGORITHMS_TEST_HPP_

#include <cppunit/extensions/HelperMacros.h>
#include <string>
#include "../headers/data-structures.hpp"
#include "../headers/algorithms.hpp"

class AlgorithmsTest : public CppUnit::TestCase {
    CPPUNIT_TEST_SUITE( AlgorithmsTest );
    CPPUNIT_TEST( testCheckGraphIsTree);
    CPPUNIT_TEST( testCheckGraphIsConnected);

    CPPUNIT_TEST( testTopologicalOrdering);

    /* Minimum spanning tree */
    CPPUNIT_TEST( testDijkstra);
    CPPUNIT_TEST( testKruskal);
    CPPUNIT_TEST( testPrim);
    CPPUNIT_TEST( testReverseDelete);
    CPPUNIT_TEST_SUITE_END();
private:
    DataStructures::SGraph* undirected_graph;
    DataStructures::SGraph* tree;
    DataStructures::SGraph* topo_graph;
    DataStructures::SGraph* non_topo_graph;
public:
    void setUp();

    void tearDown();

    void testCheckGraphIsTree();

    void testCheckGraphIsConnected();

    void testTopologicalOrdering();

    void testDijkstra();

    void testKruskal();

    void testPrim();

    void testReverseDelete();
};



#endif /* ALGORITHMS_TEST_HPP_ */
