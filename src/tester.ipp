#include <thread>
#include <vector>
#include <cassert>
#include "addTake.hpp"

int BENCHMARK_SIZE = 50000000;

template<typename T>
Tester<T>::Tester(AddTake<T> &_container, std::string &_name): container(_container), name(_name) {}


template<typename T>
void Tester<T>::runTests() {

    auto start = std::chrono::high_resolution_clock::now();


    for (int i = 0; i < BENCHMARK_SIZE / 20; i++) {
        for (int i = 0; i < 20; i++) {
            container.add(i);
        }

        for (int i = 0; i < 20; i++) {
            container.take();
        }

    }


    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "time for "
              << name + " "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms" << std::endl;


}

