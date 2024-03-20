#pragma once

#include <vector>
#include <mutex>
#include <iostream>
#include <stdexcept>



    template<typename T>
    class CircularBuffer {
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

