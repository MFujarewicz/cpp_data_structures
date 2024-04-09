#pragma once

#include <vector>
#include <mutex>
#include <iostream>
#include <stdexcept>

/**
 * @brief Klasa abstrakcyjna definiująca interfejs dla bufora cyklicznego.
 *
 * @tparam T Typ danych przechowywanych w buforze.
 */
template<typename T>
class CircularBufferAbstract {
public:
    /**
     * @brief Wstawia element do bufora.
     *
     * @param value Wartość do wstawienia.
     */
    virtual void push(const T& value) = 0;

    /**
     * @brief Usuwa i zwraca element z początku bufora.
     *
     * @return T Usunięty element.
     */
    virtual T pop() = 0;

    /**
     * @brief Zwraca wartość elementu na początku bufora.
     *
     * @return T Wartość na początku bufora.
     */
    virtual T getHeadValue() = 0;

    /**
     * @brief Zwraca wartość elementu na końcu bufora.
     *
     * @return T Wartość na końcu bufora.
     */
    virtual T getTailValue() = 0;

    /**
     * @brief Sprawdza, czy bufor jest pełny.
     *
     * @return true Jeśli bufor jest pełny.
     * @return false Jeśli bufor nie jest pełny.
     */
    virtual bool isFull() = 0;

    /**
     * @brief Sprawdza, czy bufor jest pusty.
     *
     * @return true Jeśli bufor jest pusty.
     * @return false Jeśli bufor nie jest pusty.
     */
    virtual bool isEmpty() = 0;
};

/**
 * @brief Implementacja bufora cyklicznego.
 *
 * @tparam T Typ danych przechowywanych w buforze.
 */
template<typename T>
class CircularBuffer : public CircularBufferAbstract<T>{
private:
    std::vector<T> data; ///< Dane przechowywane w buforze.
    size_t head; ///< Indeks początku bufora.
    size_t tail; ///< Indeks końca bufora.
    size_t capacity; ///< Maksymalna pojemność bufora.
    size_t count; ///< Aktualna liczba elementów w buforze.
    std::mutex mutex; ///< Mutex do synchronizacji dostępu.
public:
    /**
     * @brief Konstruktor bufora cyklicznego.
     *
     * @param _capacity Maksymalna pojemność bufora.
     */
    CircularBuffer(size_t _capacity);

    /**
     * @brief Wstawia element do bufora.
     *
     * @param value Wartość do wstawienia.
     */
    void push(const T &value);

    /**
     * @brief Usuwa i zwraca element z początku bufora.
     *
     * @return T Usunięty element.
     */
    T pop();

    /**
     * @brief Zwraca wartość elementu na początku bufora.
     *
     * @return T Wartość na początku bufora.
     */
    T getHeadValue();

    /**
     * @brief Zwraca wartość elementu na końcu bufora.
     *
     * @return T Wartość na końcu bufora.
     */
    T getTailValue();

    /**
     * @brief Sprawdza, czy bufor jest pełny.
     *
     * @return true Jeśli bufor jest pełny.
     * @return false Jeśli bufor nie jest pełny.
     */
    bool isFull();

    /**
     * @brief Sprawdza, czy bufor jest pusty.
     *
     * @return true Jeśli bufor jest pusty.
     * @return false Jeśli bufor nie jest pusty.
     */
    bool isEmpty();
};

#include "circularBuffer.ipp"

