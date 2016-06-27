/*
 * data-structures.hpp
 *
 *  Created on: Apr 16, 2016
 *      Author: asm
 */

#ifndef DATA_STRUCTURES_HPP_
#define DATA_STRUCTURES_HPP_

#include <string>
#include <vector>
#include "../headers/comparator.hpp"
#include "../headers/hashor.hpp"

using namespace std;

namespace DataStructures{
    template <typename T>
    class ForwardNode{
    public:
        ForwardNode<T>* next;
        T value;

        ForwardNode(T value){
            next = NULL;
            this->value = value;
        }
        bool operator== (const ForwardNode<T>& a){
            return (value == a.value);
        }
    };

    template <typename T>
    class CycleNode{
    public:
        CycleNode<T>* next;
        CycleNode<T>* prev;
        T value;

        CycleNode(T value){
            next = prev = NULL;
            this->value = value;
        }

        bool operator== (const CycleNode<T>& a){
            return (value == a.value);
        }

        bool operator== (T v){
            return (value == v);
        }
    };
    //
    // Single Linked List declare
    //
    template <typename T, class Node=ForwardNode<T> >
    class SingleLinkedList{
    public:
        typedef Node NodeCls;

        Node* head;
        SingleLinkedList();
        virtual ~SingleLinkedList();
        virtual Node* Push(T value);
        virtual T Head();
        virtual void Pop();
        virtual Node* Find(T value);
        virtual int Size();
        virtual string ToString();
    };

    //
    // Queue declare
    //
    template <typename T, class Node=ForwardNode<T> >
    class Queue:public SingleLinkedList<T, Node>{
    public:
        typedef Node NodeCls;
        Queue();
        virtual ~Queue();
        virtual Node* Push(T value);
        virtual T Head();
        virtual void Pop();
    };

    //
    // Stack declare
    //
    template <typename T, class Node=ForwardNode<T> >
    class Stack:public SingleLinkedList<T, Node>{
    public:
        typedef Node NodeCls;
        Stack();
        virtual ~Stack();
        virtual Node* Push(T value);
        virtual T Head();
        virtual void Pop();
    };

    //
    // Doubly linked list
    //
    template <typename T, class Node=CycleNode<T> >
    class DoublyLinkedList{
    public:
        /*
        class Node: public CycleNode<T>{
        public:
            Node(T value):CycleNode<T>(value){}
        };
        */
        typedef Node NodeCls;
        DoublyLinkedList();
        Node* head;
        Node* tail;
        virtual ~DoublyLinkedList();
        virtual Node* InsertAfter(Node* node, Node* new_node);
        virtual Node* InsertAfter(Node* node, T value);
        virtual Node* InsertBefore(Node* node, Node* new_node);
        virtual Node* InsertBefore(Node* node, T value);
        virtual Node* InsertBeginning(Node* new_node);
        virtual Node* InsertBeginning(T value);
        virtual Node* InsertEnd(Node* new_node);
        virtual Node* InsertEnd(T value);
        virtual Node* Find(T value);
        virtual Node* Remove(Node* node);
        virtual void RemoveBeginning();
        virtual void RemoveEnd();
        virtual T Head();
        virtual T Tail();
        virtual int Size();
        virtual string ToString();
    };

    //
    // Open Doubly Linked List
    //
    template <typename T, class Node=CycleNode<T> >
    class OpenDoublyLinkedList: public DoublyLinkedList<T,Node>{
    public:
        typedef Node NodeCls;
        OpenDoublyLinkedList();
        virtual ~OpenDoublyLinkedList();
        virtual Node* InsertBeginning(Node* new_node);
        virtual Node* InsertBeginning(T value);
        virtual Node* InsertEnd(Node* new_node);
        virtual Node* InsertEnd(T value);
        virtual void RemoveBeginning();
        virtual void RemoveEnd();
    };

    //
    // Circular Doubly Linked List
    //
    template <typename T, class Node=CycleNode<T> >
    class CircularDoublyLinkedList: public DoublyLinkedList<T,Node>{
    public:
        typedef Node NodeCls;
        CircularDoublyLinkedList();
        virtual ~CircularDoublyLinkedList();
        virtual Node* InsertBeginning(Node* new_node);
        virtual Node* InsertBeginning(T value);
        virtual Node* InsertEnd(Node* new_node);
        virtual Node* InsertEnd(T value);
        virtual void RemoveBeginning();
        virtual void RemoveEnd();
    };

    //
    // Priority Queue
    //
    template <typename T, class Comp=Utils::Comparator<T> >
    class PriorityQueue{
    public:
        PriorityQueue(int max_length);
        ~PriorityQueue();
        vector<T> heap;
        void Push(T value);
        T Head();
        void Pop();
        string ToString();
        int Size();
        T operator[](int pos);
        T Delete(int pos);
    private:
        int max_length;
        int current_length;
        void HeapifyUp(int pos);
        void HeapifyDown(int pos);
        Comp compar;
    };

    //
    // Hashmap
    //
    template <typename V>
    class HashEntryNode{
    public:
        HashEntryNode* next;
        HashEntryNode* prev;
        HashEntryNode(int index){
            this->value = index;
            this->next = this->prev = NULL;
        }

        HashEntryNode(int index, V real){
            this->value = index;
            this->real = real;
            this->next = this->prev = NULL;
        }

        int value;
        V real;

        bool operator==(HashEntryNode& A){
            return (this->value == A.value);
        }

        bool operator==(int index){
            return (this->value == value);
        }
    };

    template <typename K, typename V, class Hash=Utils::JenkinsHash<K> >
    class Hashmap{
    public:
        Hashmap(int bucket_length);
        ~Hashmap();
        CircularDoublyLinkedList<int, HashEntryNode<V> >** map;
        void Set(K key, V value);
        bool Get(K key, V& ret);
        bool Remove(K key);
        V& operator[](K key);
        //V& operator[](K key);
        int Size();
        string ToString();
    private:
        int bucket_length;
        Hash hash;
    };

    //Vector
    template <typename V>
    class Vector{
    public:
        Vector();
        Vector(int length);
        Vector(V* values, int length);
        Vector(V init_value, int length);
        ~Vector();

        int Size();
        int Resize(int length);
        int FindOnce(const V& value);
        void Insert(const V& value);
        void Delete(int position);
        void Delete(int first, int last);
        void RemoveOnce(const V& value);
        void RemoveAll(const V& value);
        Vector<V>& operator=(Vector<V>& x);
        V operator[](int index) const;
        V& operator[](int index);
        Vector<V>* Copy();

        vector<V>& GetStorage();

        string ToString();
    private:
        vector<V>& SetStorage(Vector<V>& x);
        vector<V> storage;
    };

    //
    // Matrix
    //
    template <typename V>
    class Matrix{
    public:
        Matrix(int n, int m);
        Matrix(Vector<V>* vectors, int nvec, bool with_col=true, bool check_square=false);
        ~Matrix();

        Vector<V>* GetStorage();

        bool DeleteColumn(int col);
        bool DeleteColumn(Vector<int> col);
        bool DeleteRow(int row);
        bool DeleteRow(const Vector<int> row);
        bool BindColumns(Vector<V>* columns, int numcol);
        bool BindColumns(Matrix<V>& m);
        bool BindRows(Vector<V>* rows, int numrow);
        bool BindRows(Matrix<V>& m);
        Matrix<V>& operator=(Matrix<V>& x);
        Vector<V>& operator[](int index);

        string ToString();
        void Size(int& n, int& m);
    protected:
        void SetStorage(Matrix<V>& x);

        int nrow;
        int ncol;
        Vector<V>* matrix;
    };

    // Graph, adjacency matrix
    class Graph:Matrix<double>{
    public:
        class Edge{
        public:
            Edge(){
                this->head = 0;
                this->tail = 0;
                this->weight = 0.0;
            }

            Edge(int head, int tail, double weight = 0.0){
                this->head = head;
                this->tail = tail;
                this->weight = weight;
            }

            bool operator >(Edge& e){
                return (this->weight > e.weight);
            }

            bool operator == (Edge& e){
                return (this->weight == e.weight);
            }

            double weight;
            int head;
            int tail;
        };

        Graph(int n_vertex, bool undirected);
        Graph(Vector<double>* vectors, int nvec);
        ~Graph();
        bool IsConnected();
        bool IsTree();
        bool DeleteEdge(Edge edge, bool undirected=true);
        bool DeleteEdge(Vector<Edge> edge, bool undirected=true);
        bool DeleteVertex(int vertex);
        bool DeleteVertex(Vector<int> vertex);
        int HasVertex(int vertex);
        int GetNumVertices();
        int FindNoIncomingVertex();
        Edge FindSmallestEdge();
        Edge FindBiggestEdge();

        bool AddEdge(Edge edge);
        bool AddVertex(int vertex);

        void FindAdjacencyVertices(int vertex, Vector<int>& ret);

        bool undirected;
        double GetEdgeW(int head, int tail);
        Graph& operator= (Graph& G);
        Vector<int> vertices;
    };
}


#endif /* DATA_STRUCTURES_HPP_ */
