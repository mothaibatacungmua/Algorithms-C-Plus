/*
 * algorithms-test.cpp
 *
 *  Created on: May 17, 2016
 *      Author: asm
 */

#include "algorithms-test.hpp"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( AlgorithmsTest);
using namespace Algorithms;
using namespace DataStructures;

void AlgorithmsTest::setUp(){
    SGraph::SetEdge edges;
    SGraph::SetVertex vertices;

    vertices.insert(1);
    vertices.insert(2);
    vertices.insert(3);
    vertices.insert(4);
    vertices.insert(5);
    vertices.insert(6);
    vertices.insert(7);
    vertices.insert(8);

    /** undirected graph
     *                  1   7
     *                 / \ /|
     *                2 - 3 |
     *               / \ / \|
     *              4 - 5   8
     *                  |
     *                  6
     */
    edges.insert(SGraph::Edge(1, 2, 4.0));
    edges.insert(SGraph::Edge(1, 3, 15.0));
    edges.insert(SGraph::Edge(2, 3, 1.0));
    edges.insert(SGraph::Edge(2, 4, 7.0));
    edges.insert(SGraph::Edge(2, 5, 6.0));
    edges.insert(SGraph::Edge(3, 5, 1.0));
    edges.insert(SGraph::Edge(3, 7, 2.0));
    edges.insert(SGraph::Edge(3, 8, 5.0));
    edges.insert(SGraph::Edge(4, 5, 3.0));
    edges.insert(SGraph::Edge(5, 6, 3.0));

    this->undirected_graph = new SGraph(edges, vertices, true);


    /** tree
     *                  1   7
     *                   \ /|
     *                2 - 3 |
     *                   /  |
     *              4 - 5   8
     *                  |
     *                  6
     */
    edges.clear();
    edges.insert(SGraph::Edge(1, 3, 1.0));
    edges.insert(SGraph::Edge(2, 3, 1.0));
    edges.insert(SGraph::Edge(3, 5, 1.0));
    edges.insert(SGraph::Edge(3, 7, 1.0));
    edges.insert(SGraph::Edge(4, 5, 1.0));
    edges.insert(SGraph::Edge(5, 6, 1.0));
    edges.insert(SGraph::Edge(7, 8, 1.0));

    this->tree = new SGraph(edges, vertices, true);

    /** directed graph
     *                  1   7
     *                 / \ /|
     *                2   3 |
     *               / \ / \|
     *              4 - 5   8
     *                  |
     *                  6
     * (1,3), (1,2), (2,4), (2,5),(3,4),(3,5), (3,7), (3,8), (5,6), (6,7), (7,8)
     */
    edges.clear();
    edges.insert(SGraph::Edge(1, 3, 1.0));
    edges.insert(SGraph::Edge(1, 2, 1.0));
    edges.insert(SGraph::Edge(2, 4, 1.0));
    edges.insert(SGraph::Edge(2, 5, 1.0));
    edges.insert(SGraph::Edge(3, 4, 1.0));
    edges.insert(SGraph::Edge(3, 5, 1.0));
    edges.insert(SGraph::Edge(3, 7, 1.0));
    edges.insert(SGraph::Edge(3, 8, 1.0));
    edges.insert(SGraph::Edge(5, 6, 1.0));
    edges.insert(SGraph::Edge(6, 7, 1.0));
    edges.insert(SGraph::Edge(7, 8, 1.0));

    this->topo_graph = new SGraph(edges, vertices, false);

    /** directed graph
     *                  1---7
     *                 / \ /|
     *                2   3 |
     *               / \ / \|
     *              4 - 5   8
     *                  |
     *                  6
     * (1,3), (1,2), (2,4), (2,5),(3,4),(3,5), (3,7), (3,8), (5,6), (6,7), (7,8), (7,1)
     */
    edges.clear();
    edges.insert(SGraph::Edge(1, 3, 1.0));
    edges.insert(SGraph::Edge(1, 2, 1.0));
    edges.insert(SGraph::Edge(2, 4, 1.0));
    edges.insert(SGraph::Edge(2, 5, 1.0));
    edges.insert(SGraph::Edge(3, 4, 1.0));
    edges.insert(SGraph::Edge(3, 5, 1.0));
    edges.insert(SGraph::Edge(3, 7, 1.0));
    edges.insert(SGraph::Edge(3, 8, 1.0));
    edges.insert(SGraph::Edge(5, 6, 1.0));
    edges.insert(SGraph::Edge(6, 7, 1.0));
    edges.insert(SGraph::Edge(7, 8, 1.0));
    edges.insert(SGraph::Edge(7, 1, 1.0));

    this->non_topo_graph = new SGraph(edges, vertices, false);
    //std::cout << this->undirected_graph->ToString();
    //std::cout << this->tree->ToString();
    //std::cout << this->topo_graph->ToString();
}

void AlgorithmsTest::tearDown(){
    delete tree;
    delete undirected_graph;
    delete topo_graph;
    delete non_topo_graph;
}

void AlgorithmsTest::testCheckGraphIsConnected(){
    bool c = this->undirected_graph->IsConnected();
    CPPUNIT_ASSERT_EQUAL(c, true);

    this->undirected_graph->DeleteEdge(5,6);
    c = this->undirected_graph->IsConnected();
    CPPUNIT_ASSERT_EQUAL(c, false);
}

void AlgorithmsTest::testCheckGraphIsTree(){
    bool c = this->undirected_graph->IsTree();
    CPPUNIT_ASSERT_EQUAL(c, false);

    c = this->tree->IsTree();
    CPPUNIT_ASSERT_EQUAL(c, true);
}

void AlgorithmsTest::testTopologicalOrdering(){
    Vector<int>result;
    bool c = GraphF::TopologicalOrdering(*this->non_topo_graph, result);
    CPPUNIT_ASSERT_EQUAL(c, false);

    c = GraphF::TopologicalOrdering(*this->topo_graph, result);
    CPPUNIT_ASSERT_EQUAL(c, true);
}

void AlgorithmsTest::testDijkstra(){
    Vector<int>path;
    bool c = GraphF::Dijkstra(*this->undirected_graph, 1, 6, path);
    //std::cout<<path.ToString();
    CPPUNIT_ASSERT_EQUAL(c, true);


}

void AlgorithmsTest::testKruskal(){

}

void AlgorithmsTest::testPrim(){

}

void AlgorithmsTest::testReverseDelete(){

}

