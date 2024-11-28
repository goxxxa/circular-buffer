#include <iostream>
#include "circular_buffer.h"
#include <chrono>
#include <vector>
#include "thread"

std::chrono::duration<int, std::ratio<1, 1000>> readerDuration(50), writerDuration(40);

CircularBuffer::CircularBuffer(int inputBufferLength) {
    bufferLength = inputBufferLength;
    buffer = new int[bufferLength];
    for (size_t i = 0; i < bufferLength; ++i) {
        buffer[i] = 0;
    }
}

CircularBuffer::~CircularBuffer() {
    delete[] buffer;
}

void CircularBuffer::read(int numberOfIteration, std::vector<int> &copyBuffer) {
    for (size_t i = 0; i < numberOfIteration; ++i) {
        std::this_thread::sleep_for(readerDuration);
        copyBuffer.push_back(buffer[tail]);
        tail++;

        if (tail == bufferLength) {
            tail = 0;
        }
    }
    std::cout << "Reading completed" << std::endl;
}

void CircularBuffer::write(int numberOfIteration) {
    for (size_t i = 0; i < numberOfIteration; ++i) {
        std::this_thread::sleep_for(writerDuration);

        int randomValue = rand() / 100;

        buffer[head] = randomValue;
        std::cout << buffer[head] << ", ";
        head++;

        if (head == bufferLength) {
            head = 0;
        }
    }
    std:: cout << std::endl;
    std::cout << "Writing completed" << std::endl;
}

std::ostream &operator<<(std::ostream &os, CircularBuffer &circularBuffer) {
    os << "[ ";
    for (size_t i = 0; i < circularBuffer.bufferLength; ++i) {
        os << circularBuffer.buffer[i];
        (i != circularBuffer.bufferLength - 1) ? os << ", " : os << "";
    }
    os << " ]";
    return os;
}

int &CircularBuffer::operator[](int index) const {
    if (index < 0 || index >= bufferLength) {
        throw std::out_of_range("Invalid index value");
    }
    return buffer[index];
}
