#include <iostream>
#include <thread>
#include <random>
#include <chrono>
#include "circular_buffer.h"

#define NUMBER_OF_ITERATION 500

using namespace std;

void printVector(vector<int> &vector) {
    cout << "[ ";
    for (size_t i = 0; i < vector.size(); ++i) {
        cout << vector[i];
        if (i != vector.size() - 1) {
            std::cout << ", ";
        }
    }
    cout << " ]" << endl;
}

int main() {
    srand((unsigned) time(NULL));
    CircularBuffer circularBuffer = CircularBuffer(50);
    vector<int> copyBuffer;

    thread th1(&CircularBuffer::read, &circularBuffer, NUMBER_OF_ITERATION, std::ref(copyBuffer));
    thread th2(&CircularBuffer::write, &circularBuffer, NUMBER_OF_ITERATION);

    th1.join();
    th2.join();

    printVector(copyBuffer);
    return 0;
}