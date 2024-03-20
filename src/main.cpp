#include <iostream>

#include "circularBuffer.cpp"

int main() {

    CircularBuffer<int> buffer(5);

    buffer.push(1);
    buffer.push(2);
    buffer.push(3);
    buffer.push(4);
    buffer.push(5);
    buffer.printHT();

    int a;
    a = buffer.pop();
    a = buffer.pop();
    a = buffer.pop();
//    a = buffer.pop();
    a = buffer.pop();

    buffer.printHT();
    buffer.printCount();

    std::cout << a  << std::endl;


    return 0;


}
