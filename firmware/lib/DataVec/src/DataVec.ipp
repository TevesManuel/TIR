#include <DataVec.hpp>

template <typename T>
DataVec<T>::DataVec()
{
    this->resetIter();
    this->mainNode = new Node;
    this->mainNode->data = nullptr;
    this->mainNode->next = nullptr;
    this->lastNode = this->mainNode;
    this->length = 0;
}

template <typename T>
typename DataVec<T>::Node * DataVec<T>::createNode(T data)
{
    Node * newNode = new Node;
    newNode->data = new T;
    *newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

template <typename T>
void DataVec<T>::add(T data)
{
    if(this->mainNode != nullptr)
    {
        if(this->mainNode->data == nullptr)
        {
            this->mainNode->data = new T;
            *this->mainNode->data = data;
        }
        else
        {
            Node * next = this->mainNode;
            while(next->next != nullptr)
            {
                next = next->next;
            }
            next->next = createNode(data);
            this->lastNode = next->next;
        }
        this->length++;
    }
}

template <typename T>
T * DataVec<T>::iter(T*iteratorAdress)
{
    if(this->iterNode == NULL)
    {
        this->iterNode = this->mainNode;
        *iteratorAdress = *this->iterNode->data;
        return this->iterNode->data;
    }
    else
    {
        this->iterNode = this->iterNode->next;
        *iteratorAdress = *this->iterNode->data;
        return this->iterNode->data;    
    }
}

template <typename T>
void DataVec<T>::resetIter()
{
    this->iterNode = NULL;
}

template <typename T>
void DataVec<T>::clean()
{
    Node * next = this->mainNode;//Head address of last vec

    this->mainNode = new Node;
    this->mainNode->data = nullptr;
    this->mainNode->next = nullptr;
    this->lastNode = this->mainNode;
    this->resetIter();
    this->length = 0;

    do {        
        Node * nextPtr = next->next;//Next node address
        delete next->data;// Liberate data memory
        next->data = nullptr;
        next->next = nullptr;
        delete next;//Liberate next memory
        next = nextPtr;
    }
    while(next != NULL);
}

template <typename T>
T * DataVec<T>::lastItem()
{
    return this->lastNode->data;
}