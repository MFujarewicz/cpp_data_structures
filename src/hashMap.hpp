#pragma once

#include <mutex>
#include <iostream>
#include <stdexcept>

/**
 * @brief Węzeł do użycia w HashMapie, przechowujący parę klucz-wartość oraz wskaźnik na następny węzeł.
 *
 * @tparam KeyType Typ klucza.
 * @tparam ValueType Typ wartości.
 */
template<typename KeyType, typename ValueType>
class Node {
private:
    KeyType key; ///< Klucz węzła.
    ValueType value; ///< Wartość przechowywana w węźle.
    Node<KeyType, ValueType> *next; ///< Wskaźnik na następny węzeł.
public:
    /**
     * @brief Konstruktor węzła.
     *
     * @param _key Klucz.
     * @param _value Wartość.
     */
    Node(KeyType _key, ValueType _value);

    /**
     * @brief Pobiera wartość węzła.
     *
     * @return ValueType Wartość.
     */
    ValueType getValue();

    /**
     * @brief Pobiera klucz węzła.
     *
     * @return KeyType Klucz.
     */
    KeyType getKey();

    /**
     * @brief Ustawia wskaźnik na następny węzeł.
     *
     * @param _next Wskaźnik na następny węzeł.
     */
    void setNext(Node<KeyType, ValueType> *_next);

    /**
     * @brief Ustawia wartość węzła.
     *
     * @param value Nowa wartość.
     */
    void setValue(const ValueType &value);

    /**
     * @brief Pobiera wskaźnik na następny węzeł.
     *
     * @return Node<KeyType, ValueType>* Wskaźnik na następny węzeł.
     */
    Node<KeyType, ValueType> *getNext();
};

/**
 * @brief Klasa implementująca hashmapę.
 *
 * @tparam KeyType Typ klucza.
 * @tparam ValueType Typ wartości.
 */
template<typename KeyType, typename ValueType>
class HashMap {
private:
    size_t count; ///< Liczba elementów w hashmapie.
    std::mutex mutex; ///< Mutex do synchronizacji.
    Node<KeyType, ValueType> **buckets; ///< Tablica wskaźników na węzły.
    size_t capacity; ///< Aktualna pojemność hashmapy.
    void resize(); ///< Metoda do zmiany rozmiaru tablicy węzłów.

    static const int INITIAL_CAPACITY = 16; ///< Początkowa pojemność hashmapy.
    constexpr static const double LOAD_FACTOR_THRESHOLD = 0.75; ///< Granica załadowania, po której przekroczeniu hashmapa rośnie.

public:
    /**
     * @brief Konstruktor hashmapy.
     */
    HashMap();

    /**
     * @brief Pobiera aktualny rozmiar tablicy węzłów.
     *
     * @return size_t Aktualny rozmiar.
     */
    size_t getCurrentSize();

    /**
     * @brief Pobiera liczbę elementów w hashmapie.
     *
     * @return size_t Liczba elementów.
     */
    size_t getCount();

    /**
     * @brief Wstawia parę klucz-wartość do hashmapy.
     *
     * @param key Klucz.
     * @param value Wartość.
     */
    void put(const KeyType &key, const ValueType &value);

    /**
     * @brief Pobiera wartość na podstawie klucza.
     *
     * @param key Klucz.
     * @return ValueType Wartość.
     */
    ValueType get(const KeyType &key);

    /**
     * @brief Sprawdza, czy hashmapa jest pusta.
     *
     * @return true Jeśli hashmapa jest pusta.
     * @return false Jeśli hashmapa nie jest pusta.
     */
    bool isEmpty();
};

#include "hashMap.ipp"

