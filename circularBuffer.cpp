#include <iostream>
#include <vector>
#include <mutex>


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
    CircularBuffer(size_t _capacity) : data(_capacity), head(0), tail(0), capacity(_capacity), count(0) {}

    void push(const T &value) {
        std::lock_guard<std::mutex> lock(mutex);
        if (isFull()) {
            //overwrite last element
            head = (head + 1) % capacity;
        }
        else{
            count++;
        }


        data[tail] = value;
        tail = (tail + 1) % capacity;


        for (T i: data) {
            std::cout << i << ' ';
        }
        std::cout << std::endl;


    }

    void printHT(){
        std::cout <<"head: " << head << "  tail: " << tail << std::endl;
    }

    void printCount(){
        std::cout << count << std::endl;
    }

    T pop() {
        std::lock_guard<std::mutex> lock(mutex);
        if (isEmpty()) {
            throw std::runtime_error("Circular buffer is empty");
        }

        count--;
        T returnValue = data[head];
        head = (head + 1) % capacity;
        return returnValue;

    }

    T getHeadValue(){
        return data[head];
    }

    T getTailValue(){
        return data[(tail-1)%capacity];
    }

    bool isFull() {
        return count == capacity;
    }

    bool isEmpty() {
        return count == 0;
    }
};