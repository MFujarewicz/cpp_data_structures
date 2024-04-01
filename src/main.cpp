#include <iostream>
#include <unordered_map>
#include "circularBuffer.hpp"
#include "queue.hpp"
#include "hashMap.hpp"

int main() {

//
//    std::unordered_map<std::string, int> map;

    HashMap<int, int> map;

    for (int i=0; i<50; i++){
        map.put(i, i);
    }

    for (int i=0; i<20; i++){
        std::cout << map.get(i) << std::endl;
    }

    std::cout << map.getCurrentSize() << std::endl;








//    Queue<int> queue;
//    queue.enqueue(1);
//    queue.enqueue(2);
//    auto a = queue.dequeue();
//    auto b = queue.dequeue();
//    queue.enqueue(3);
//    auto c = queue.dequeue();
//
//
//    std::cout << a << std::endl;
//    std::cout << b << std::endl;
//    std::cout << c << std::endl;
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
//
//
//    std::cout << a  << std::endl;


    return 0;



}
