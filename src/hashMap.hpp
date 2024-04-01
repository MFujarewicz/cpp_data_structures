#pragma once

#include <mutex>
#include <iostream>
#include <stdexcept>

template<typename KeyType, typename ValueType>
class Node {
private:
    KeyType key;
    ValueType value;
    Node<KeyType, ValueType>* next;
public:
    Node(KeyType _key, ValueType _value);
    ValueType getValue();
    KeyType getKey();
    void setNext(Node<KeyType, ValueType>* _next);
    void setValue(const ValueType &value);
    Node<KeyType, ValueType>* getNext();
};


template<typename KeyType, typename ValueType>
class HashMap {
private:
    size_t count;
    std::mutex mutex;
    Node<KeyType, ValueType>** buckets;
    size_t capacity;
    void resize();

    static const int INITIAL_CAPACITY = 16;
    constexpr static const double LOAD_FACTOR_THRESHOLD = 0.75;

public:
    HashMap();

    size_t getCurrentSize();

    size_t getCount();

    void put(const KeyType &key, const ValueType &value);

    ValueType get(const KeyType &key);

    bool isEmpty();
};




#include "hashMap.ipp"

