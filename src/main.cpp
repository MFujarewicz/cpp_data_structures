#include <iostream>

#include "circularBuffer.hpp"

int main() {

    CircularBuffer<int> buffer(5);


    buffer.push(1);
    buffer.push(2);
    buffer.push(3);
    buffer.push(4);
    buffer.push(5);

    int a;
    a = buffer.pop();
    a = buffer.pop();
    a = buffer.pop();
//    a = buffer.pop();
    a = buffer.pop();


    std::cout << a  << std::endl;


    return 0;



}
