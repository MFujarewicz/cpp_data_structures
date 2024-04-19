#pragma once

#include <mutex>
#include <iostream>
#include <stdexcept>

/**
 * @brief Węzeł kolejki przechowujący wartość i wskaźnik na kolejny węzeł.
 *
 * @tparam T Typ danych przechowywanych w węźle.
 */
template<typename T>
class QueueNode {
private:
    T value; ///< Wartość przechowywana w węźle.
    QueueNode<T> *next; ///< Wskaźnik na następny węzeł.

public:
    /**
     * @brief Konstruktor węzła kolejki.
     *
     * @param value Wartość węzła.
     */
    QueueNode(T value);

    /**
     * @brief Pobiera wartość węzła.
     *
     * @return Wartość przechowywana w węźle.
     */
    T getValue();

    /**
     * @brief Ustawia wskaźnik na następny węzeł w kolejce.
     *
     * @param nextNode Wskaźnik na następny węzeł.
     */
    void setNext(QueueNode<T> *nextNode);

    /**
     * @brief Pobiera wskaźnik na następny węzeł w kolejce.
     *
     * @return Wskaźnik na następny węzeł.
     */
    QueueNode<T> *getNext();
};

/**
 * @brief Kolejka zbudowana z węzłów ze wskaźnikami na koleje węzły.
 *
 * @tparam T Typ danych przechowywanych w kolejce.
 */
template<typename T>
class Queue {
private:
    size_t count; ///< Liczba elementów w kolejce.
    std::mutex mutex; ///< Mutex do synchronizacji dostępu do kolejki.
    QueueNode<T> *headPtr; ///< Wskaźnik na początek kolejki.
    QueueNode<T> *tailPtr; ///< Wskaźnik na koniec kolejki.

public:
    /**
     * @brief Konstruktor kolejki.
     */
    Queue();

    /**
     * @brief Dodaje element na koniec kolejki.
     *
     * @param value Wartość do dodania.
     */
    void enqueue(const T &value);

    /**
     * @brief Usuwa i zwraca element z początku kolejki.
     *
     * @return Usunięta wartość.
     */
    T dequeue();

    /**
     * @brief Sprawdza czy kolejka jest pusta.
     *
     * @return true Jeśli kolejka jest pusta.
     * @return false Jeśli kolejka nie jest pusta.
     */
    bool isEmpty();
};

#include "queue.ipp"

