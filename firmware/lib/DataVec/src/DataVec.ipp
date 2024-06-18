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
            this->lastNode->next = createNode(data);
            this->lastNode = this->lastNode->next;
        }
        this->length++;
    }
}

template <typename T>
T * DataVec<T>::iter(T*iteratorAdress)
{
    if(this->iterNode == nullptr)
    {
        this->iterNode = this->mainNode;
    }
    else
    {
        this->iterNode = this->iterNode->next;
        if(this->iterNode == nullptr)
        {
            this->resetIter();
            return nullptr;
        }
    }
    *iteratorAdress = *this->iterNode->data;
    return this->iterNode->data;
}

template <typename T>
void DataVec<T>::resetIter()
{
    this->iterNode = nullptr;
}

template <typename T>
void DataVec<T>::clean()
{
    Node * next = this->mainNode;//Head address of last vec
    while (next != nullptr)
    {
        Node* nextPtr = next->next;
        if (next->data != nullptr)
        {
            delete next->data;
            next->data = nullptr;
        }
        delete next;
        next = nextPtr;
    }

    this->mainNode = new Node;
    this->mainNode->data = nullptr;
    this->mainNode->next = nullptr;
    this->lastNode = this->mainNode;
    this->resetIter();
    this->length = 0;
}

template <typename T>
T * DataVec<T>::lastItem()
{
    return this->lastNode->data;
}