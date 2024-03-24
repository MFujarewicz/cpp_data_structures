#pragma once

#include <mutex>
#include <iostream>
#include <stdexcept>

template<typename T>
class QueueNode {
private:
    T value;
    QueueNode<T>* next;
public:
    QueueNode(T value);
    T getValue();
    void setNext(QueueNode<T>* nextNode);
    QueueNode<T>* getNext();
};




template<typename T>
class Queue {
private:
    size_t count;
    std::mutex mutex;
    QueueNode<T>* headPtr;
    QueueNode<T>* tailPtr;

public:
    Queue();

    void enqueue(const T &value);

    T dequeue();

    bool isEmpty();
};



#include "queue.ipp"

