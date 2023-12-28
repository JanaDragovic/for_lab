#include "BscChannel.h"

#include <random>
#include <chrono>

// konstruktori
BscChannel::BscChannel()
{
    errorRate = 0;
    output = nullptr;
    outputCopy = nullptr;
    length = 0;
}

BscChannel::BscChannel(float er, int length)
{
    errorRate = er;
    output = new float[length];
    outputCopy = new float[length];
    this->length = length;
}

// destruktori
BscChannel::~BscChannel() {
    delete[] output;
    delete[] outputCopy;
}

// unosenje greske invertovanjem 
void BscChannel::insertErrors() {

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);

    for (int i = 0; i < length; ++i) {
        double randNum = static_cast<double>(rand()) / RAND_MAX; 
        if (randNum < errorRate) {
            output[i] = 1 - outputCopy[i];
        }
        else {
            output[i] = outputCopy[i];
        }
    }
}