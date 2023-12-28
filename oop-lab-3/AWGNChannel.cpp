#include "AWGNChannel.h"
#include <math.h>
#include <random>
#include <chrono>

// konstruktori
AWGNChannel::AWGNChannel()
{
    noiseVar = 0;
    output = nullptr;
    outputCopy = nullptr;
    length = 0;
}

AWGNChannel::AWGNChannel(float nV, int length)
{
    noiseVar = nV;
    output = new float[length];
    outputCopy = new float[length];
    this->length = length;

}

// destruktor
AWGNChannel::~AWGNChannel() {

    delete[] output;
    delete[] outputCopy;
}

// unosenje greske
void AWGNChannel::insertErrors()
{
    
    /*int* noise = new int[length];
    float sigma = sqrt(noiseVar);
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::default_random_engine generator(seed);
    std::normal_distribution<float> distribution(0.0, sigma);
    
    for (int i = 0; i < length; i++) {
        noise[i] = distribution(generator);
        output[i] += noise[i];
        outputCopy[i] += noise[i];
    }

    delete[] noise;*/

    float sigma = sqrt(noiseVar);

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::normal_distribution<float> distribution(0.0, sigma);
    for (int i = 0; i < length; ++i) {
        output[i] = output[i] + distribution(generator);
        outputCopy[i] = output[i];
    }
    /*
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);

    for (int i = 0; i < length; ++i) {
        double randNum = static_cast<double>(rand()) / RAND_MAX;
        if (randNum < noiseVar) {
            output[i] = 1 - outputCopy[i];
        }
        else {
            output[i] = outputCopy[i];
        }
    }
    */

    
}