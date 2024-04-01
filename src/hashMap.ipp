#pragma once

#define DEBUG_PRINT false


template<typename KeyType, typename ValueType>
Node<KeyType, ValueType>::Node(KeyType _key, ValueType _value):value(_value), key(_key), next(nullptr) {}

template<typename KeyType, typename ValueType>
ValueType Node<KeyType, ValueType>::getValue() {
    return value;
}

template<typename KeyType, typename ValueType>
void Node<KeyType, ValueType>::setNext(Node<KeyType, ValueType> *_next) {
    next = _next;
}

template<typename KeyType, typename ValueType>
void HashMap<KeyType, ValueType>::resize() {

    size_t newCapacity = capacity * 2;
    Node<KeyType, ValueType> **newBuckets = new Node<KeyType, ValueType> *[newCapacity];

    for (size_t i = 0; i < newCapacity; i++) {
        newBuckets[i] = nullptr;
    }

    for (size_t i = 0; i < capacity; i++) {
        Node<KeyType, ValueType> *oldNode = buckets[i];
        while (oldNode != nullptr) {
            size_t newIndex = std::hash<KeyType>{}(oldNode->getKey()) % newCapacity;

            Node<KeyType, ValueType> *nextNode = oldNode->getNext();
            oldNode->setNext(newBuckets[newIndex]);
            newBuckets[newIndex] = oldNode;

            oldNode = nextNode;
        }
    }

    delete[] buckets;
    buckets = newBuckets;
    capacity = newCapacity;
}


template<typename KeyType, typename ValueType>
Node<KeyType, ValueType> *Node<KeyType, ValueType>::getNext() {
    return next;
}

template<typename KeyType, typename ValueType>
void Node<KeyType, ValueType>::setValue(const ValueType &_value) {
    value = _value;
}

template<typename KeyType, typename ValueType>
KeyType Node<KeyType, ValueType>::getKey() {
    return key;
}


template<typename KeyType, typename ValueType>
HashMap<KeyType, ValueType>::HashMap():count(0), capacity(INITIAL_CAPACITY) {


    buckets = new Node<KeyType, ValueType> *[capacity];

    for (size_t i = 0; i < capacity; i++) {
        buckets[i] = nullptr;
    }


    std::cout << "hashmap initialized" << std::endl;
}


template<typename KeyType, typename ValueType>
void HashMap<KeyType, ValueType>::put(const KeyType &key, const ValueType &value) {


    size_t index = std::hash<KeyType>{}(key) % capacity;


    if (buckets[index] == nullptr) {
        Node<KeyType, ValueType> *nodePtr = new Node(key, value);
        buckets[index] = nodePtr;
        count++;
    } else {
        Node<KeyType, ValueType> *node = buckets[index];

        do {
            if (node->getKey() == key) {
                node->setValue(value);
                return;
            }
            node = node->getNext();
        } while (node->getNext() != nullptr);

        Node<KeyType, ValueType> *nodePtr = new Node(key, value);
        node->setNext(nodePtr);
        count++;

    }

    if (capacity*LOAD_FACTOR_THRESHOLD<=count) {
        resize();
    }


}

template<typename KeyType, typename ValueType>
ValueType HashMap<KeyType, ValueType>::get(const KeyType &key) {

    size_t index = std::hash<KeyType>{}(key) % capacity;

    if (buckets[index] == nullptr) {
        throw std::runtime_error("No such key in map");
    }

    Node<KeyType, ValueType> *node = buckets[index];

    do {
        if (node->getKey() == key) {
            return node->getValue();
        }
        node = node->getNext();
    } while (node->getNext() != nullptr);

    throw std::runtime_error("No such key in map");

}


template<typename KeyType, typename ValueType>
bool HashMap<KeyType, ValueType>::isEmpty() {
    return count == 0;
}

template<typename KeyType, typename ValueType>
size_t HashMap<KeyType, ValueType>::getCurrentSize() {
    return capacity;
}

template<typename KeyType, typename ValueType>
size_t HashMap<KeyType, ValueType>::getCount() {
    return count;
}