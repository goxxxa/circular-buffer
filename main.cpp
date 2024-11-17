#include <iostream>
#include "circular_buffer.h"

using namespace std;

int main() {

    CircularBuffer circularBuffer = CircularBuffer(4);

    cout << circularBuffer.bufferLength << endl;
    circularBuffer.write(105);
    circularBuffer.write(106);
    circularBuffer.write(107);
    circularBuffer.write(108);
    circularBuffer.write(109);
    circularBuffer.write(110);

    cout << circularBuffer << endl;
    cout << circularBuffer[2] << endl;
    cout << circularBuffer.tail << endl;

    return 0;
}