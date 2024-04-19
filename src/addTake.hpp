#pragma once

#include <mutex>
#include <iostream>
#include <stdexcept>


template<typename T>
class AddTake {

public:

    /**
     * @brief Sprawdza czy kolejka jest pusta.
     *
     * @return true Jeśli kolejka jest pusta.
     * @return false Jeśli kolejka nie jest pusta.
     */
    virtual bool isEmpty() = 0;


    /**
    * @brief Dodaje element na koniec kolejki.
    *
    * @param value Wartość do dodania.
    */
    virtual void add(const T &value) = 0;


    /**
    * @brief Usuwa i zwraca element z początku kolejki.
    *
    * @return Usunięta wartość.
    */
    virtual T take() = 0;
};



