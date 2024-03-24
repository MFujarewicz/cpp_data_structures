#pragma once

#define DEBUG_PRINT false


template<typename T>
QueueNode<T>::QueueNode(T _value):value(_value), next(nullptr) {

}

template<typename T>
T QueueNode<T>::getValue() {
    return value;
}

template<typename T>
void QueueNode<T>::setNext(QueueNode<T> *nextNode) {
    next = nextNode;

}

template<typename T>
QueueNode<T> *QueueNode<T>::getNext() {
    return next;
}


template<typename T>
Queue<T>::Queue():count(0), headPtr(nullptr), tailPtr(nullptr) {

    std::cout << "queue initialized" << std::endl;
}


template<typename T>
void Queue<T>::enqueue(const T &value) {

    QueueNode<T> *nodePtr = new QueueNode(value);

    if (isEmpty()) {
        headPtr = nodePtr;
        tailPtr = nodePtr;
    } else {
        headPtr->setNext(nodePtr);
        headPtr = nodePtr;
    }
    count++;
}


template<typename T>
T Queue<T>::dequeue() {

    if (isEmpty()) throw std::runtime_error("Queue buffer is empty");

    T returnValue = tailPtr->getValue();
    QueueNode<T> *oldTail = tailPtr;
    tailPtr = tailPtr->getNext();
    delete oldTail;

    count--;
    return returnValue;
}


template<typename T>
bool Queue<T>::isEmpty() {
    return count == 0;
}