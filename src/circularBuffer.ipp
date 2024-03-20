#pragma once
#define DEBUG_PRINT false



template<typename T>
CircularBuffer<T>::CircularBuffer(size_t _capacity):
        data(_capacity), head(0), tail(0), capacity(_capacity), count(0) {}


template<typename T>
void CircularBuffer<T>::push(const T &value) {
    std::lock_guard<std::mutex> lock(mutex);
    if (isFull()) {
        //overwrite last element
        head = (head + 1) % capacity;
    } else {
        count++;
    }


    data[tail] = value;
    tail = (tail + 1) % capacity;


    if (DEBUG_PRINT) {
        for (T i: data) {
            std::cout << i << ' ';
        }
        std::cout << std::endl;
    }
}


template<typename T>
T CircularBuffer<T>::pop() {
    std::lock_guard<std::mutex> lock(mutex);
    if (isEmpty()) {
        throw std::runtime_error("Circular buffer is empty");
    }

    count--;
    T returnValue = data[head];
    head = (head + 1) % capacity;
    return returnValue;
}

template<typename T>
T CircularBuffer<T>::getHeadValue() {
    return data[head];
}

template<typename T>
T CircularBuffer<T>::getTailValue() {
    return data[(tail - 1) % capacity];
}


template<typename T>
bool CircularBuffer<T>::isFull() {
    return count == capacity;
}

template<typename T>
bool CircularBuffer<T>::isEmpty() {
    return count == 0;
}

