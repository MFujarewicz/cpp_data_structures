#include <thread>
#include <vector>
#include <cassert>

#include "addTake.hpp"

template<typename T>
class Tester {
public:

    /**
    * @brief Konstruuje obiekt Tester do testowania kontenera AddTake.
    * @param _container Referencja do obiektu który ma być testowany.
    * @param name Nazwa testu.
    */
    Tester(AddTake<T>& _container, std::string& name);


    /**
    * @brief Uruchamia test na kontenerze AddTake
    */
    void runTests();

private:
    AddTake<T>& container;
    std::string name;
};


#include "tester.ipp"