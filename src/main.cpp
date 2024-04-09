#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>
#include "circularBuffer.hpp"
#include "queue.hpp"
#include "hashMap.hpp"
#include <chrono>

int HASHMAP_BENCHMARK = 50000000;
int QUEUE_BENCHMARK = 50000000;

void benchmarkQueue(){

    auto start = std::chrono::high_resolution_clock::now();

    Queue<int> queue;


    //time enqueue
    for (int i=0; i<QUEUE_BENCHMARK; i++){
        queue.enqueue(i);
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "My queue enqueue time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    //time dequeue
    for (int i=0; i<QUEUE_BENCHMARK; i++){
        queue.dequeue();
    }
    end = std::chrono::high_resolution_clock::now();

    std::cout << "My queue dequeue time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms" << std::endl;

    std::unordered_map<int, int> mapStd;

    std::queue<int> StdQueue;

    start = std::chrono::high_resolution_clock::now();
    for (int i=0; i<QUEUE_BENCHMARK; i++){
        StdQueue.push(i);
    }
    end = std::chrono::high_resolution_clock::now();

    std::cout << "Std queue enqueue time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    //time dequeue
    for (int i=0; i<QUEUE_BENCHMARK; i++){
        StdQueue.pop();
    }
    end = std::chrono::high_resolution_clock::now();

    std::cout << "Std queue dequeue time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms" << std::endl;




}

void benchmarkHashMap(){



    HashMap<int, int> map;

    auto start = std::chrono::high_resolution_clock::now();
    //time put
    for (int i=0; i<HASHMAP_BENCHMARK; i++){
        map.put(i, i);
    }
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "My hashmap put time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms" << std::endl;


    start = std::chrono::high_resolution_clock::now();
    //time get
    for (int i=0; i<HASHMAP_BENCHMARK; i++){
        map.get(i);
    }
    end = std::chrono::high_resolution_clock::now();

    std::cout << "My hashmap get time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms" << std::endl;

    std::unordered_map<int, int> mapStd;

    start = std::chrono::high_resolution_clock::now();
    //time put
    for (int i=0; i<HASHMAP_BENCHMARK; i++){
        mapStd[i] = i;
    }
    end = std::chrono::high_resolution_clock::now();

    std::cout << "std hashmap put time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    //time get
    for (int i=0; i<HASHMAP_BENCHMARK; i++){
        mapStd[i];
    }
    end = std::chrono::high_resolution_clock::now();

    std::cout << "std hashmap get time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms" << std::endl;

}

int main() {

    benchmarkHashMap();
    benchmarkQueue();

//
//    std::unordered_map<std::string, int> map;

//    HashMap<int, int> map;
//
//    for (int i=0; i<50; i++){
//        map.put(i, i);
//    }
//
//    for (int i=0; i<20; i++){
//        std::cout << map.get(i) << std::endl;
//    }

//    std::cout << map.getCurrentSize() << std::endl;
//
//    std::string str = "aaaa";
//
//
//
//    std::cout << str.max_size() << std::endl;
//    std::cout << str.size() << std::endl;
//    std::cout << str << std::endl;
//    std::cout << sizeof(str) << std::endl;




//
//
////    Queue<int> queue;
////    queue.enqueue(1);
////    queue.enqueue(2);
////    auto a = queue.dequeue();
////    auto b = queue.dequeue();
////    queue.enqueue(3);
////    auto c = queue.dequeue();
////
////
////    std::cout << a << std::endl;
////    std::cout << b << std::endl;
////    std::cout << c << std::endl;
////
//
//
//
//
//
//    CircularBuffer<int> buffer(5);
//
//
//    buffer.push(1);
//    buffer.push(2);
//    buffer.push(3);
//    buffer.push(4);
//    buffer.push(5);
//
//    int a;
//    a = buffer.pop();
//    a = buffer.pop();
//    a = buffer.pop();
////    a = buffer.pop();
//    a = buffer.pop();


//    std::cout << a  << std::endl;


    return 0;



}
