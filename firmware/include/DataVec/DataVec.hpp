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
    public:
        DataVec();
        void add(T);
        void printAll();
};

#endif