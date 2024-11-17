#include "circular_buffer.h"

CircularBuffer::CircularBuffer(int inputBufferLength) {
    bufferLength = inputBufferLength;
    buffer = new int[bufferLength];
}

CircularBuffer::~CircularBuffer() {
    delete[] buffer;
}

int CircularBuffer::read(int index) {
    return buffer[index];
}

void CircularBuffer::write(int value) {
    if (tail >= bufferLength) {
        tail = 0;
    }
    if (tail == head) {
        head++;
    }
    buffer[tail] = value;
    tail++;
}

std::ostream &operator<<(std::ostream &os, CircularBuffer &circularBuffer) {
    os << "[ ";
    for(size_t i = 0; i < circularBuffer.bufferLength; ++i) {
        os << circularBuffer.buffer[i];
        (i != circularBuffer.bufferLength - 1) ? os << ", " : os << "";
    }
    os << " ]";
    return os;
}

int &CircularBuffer::operator[](int index) const {
    if (index < 0 && index >= bufferLength) {
        throw "Invalid index value";
    }
    return buffer[index];
}
