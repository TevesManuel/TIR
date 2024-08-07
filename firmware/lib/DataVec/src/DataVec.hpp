#ifndef DATAVEC_HPP
#define DATAVEC_HPP

template <typename T>
class DataVec {
    private:
        typedef struct Node {
            T * data;
            Node * next;
        }Node;
        Node * mainNode;
        Node * createNode(T);
        Node * iterNode;
        Node * lastNode;
    public:
        int length;
        DataVec();
        void add(T);
        void printAll();
        T * iter(T*);
        void resetIter();
        void clean();
        T * lastItem();
};

#include "./DataVec.ipp"

#endif