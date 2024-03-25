#pragma once

#include <vector>
#include <mutex>
#include <iostream>
#include <stdexcept>


template<typename T>
class CircularBufferAbstract {
public:

    virtual void push(const T& value) = 0;

    virtual T pop() = 0;

    virtual T getHeadValue() = 0;

    virtual T getTailValue() = 0;

    virtual bool isFull() = 0;

    virtual bool isEmpty() = 0;
};

template<typename T>
class CircularBuffer : public CircularBufferAbstract<T>{
private:
    std::vector<T> data;
    size_t head;
    size_t tail;
    size_t capacity;
    size_t count;
    std::mutex mutex;
public:
    CircularBuffer(size_t _capacity);

    void push(const T &value);

    T pop();

    T getHeadValue();

    T getTailValue();

    bool isFull();

    bool isEmpty();
};

#include "circularBuffer.ipp"

