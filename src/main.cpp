#include <iostream>
#include <unordered_map>
#include "circularBuffer.hpp"
#include "queue.hpp"
#include "hashMap.hpp"

int main() {

//
//    std::unordered_map<std::string, int> map;

    HashMap<std::string, int> map;

    map.put("aa", 1);
    map.put("bb", 2);
    map.put("cc", 3);
    map.put("aa", 4);


    std::cout << map.get("aa") << std::endl;
    std::cout << map.get("bb") << std::endl;
    std::cout << map.get("cc") << std::endl;





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
