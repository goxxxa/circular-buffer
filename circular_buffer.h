#ifndef GRAPHICS_CIRCULAR_BUFFER_H
#define GRAPHICS_CIRCULAR_BUFFER_H

#include <cstdio>
#include <ostream>

class CircularBuffer {
public:
    size_t bufferLength;
    int* buffer;
    size_t tail{}, head{};
public:
    explicit CircularBuffer(int bufferLength);
    ~CircularBuffer();

    int read(int index);
    void write(int value);

    int &operator[](int index) const;

    friend std::ostream &operator<<(std::ostream &os, CircularBuffer &circularBuffer);
};

#endif //GRAPHICS_CIRCULAR_BUFFER_H
