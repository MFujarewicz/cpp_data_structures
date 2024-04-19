#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>
#include "circularBuffer.hpp"
#include "queue.hpp"
#include "hashMap.hpp"
#include "tester.hpp"
#include <chrono>

int HASHMAP_BENCHMARK = 50000000;
int QUEUE_BENCHMARK = 50000000;

void benchmarkQueue(){

    auto start = std::chrono::high_resolution_clock::now();

    Queue<int> queue;


    //time enqueue
    for (int i=0; i<QUEUE_BENCHMARK; i++){
        queue.add(i);
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

    CircularBuffer<int> circularBuffer;
    std::string circularBufferTestName = "Circular Buffer Test";

    Queue<int> queue;
    std::string queueTestName = "Queue Test";


    Tester<int> testerQueue(queue, queueTestName);
    Tester<int> testerBuffer(circularBuffer, circularBufferTestName);

    testerQueue.runTests();
    testerBuffer.runTests();



//    benchmarkHashMap();
//    benchmarkQueue();

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
////
//    Queue<int> queue;
//    queue.add(1);
//    queue.add(2);
//    auto a = queue.take();
//    auto b = queue.take();
//    queue.add(3);
//    auto c = queue.take();
//
//
//    std::cout << a << std::endl;
//    std::cout << b << std::endl;
//    std::cout << c << std::endl;
////
//
//
//
//
////
//    CircularBuffer<int> circularBuffer;
//    AddTake<int>& addTake = circularBuffer;
//
//
//    addTake.add(1);
//    addTake.add(2);
//    addTake.add(3);
//    addTake.add(4);
//    addTake.add(5);
//
//    int d;
//    d = addTake.take();
//    d = addTake.take();
//    d = addTake.take();
//    d = addTake.take();
//    d = addTake.take();
//
//
//    std::cout << d  << std::endl;
//
//
//    return 0;



}
