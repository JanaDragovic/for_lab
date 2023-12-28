#ifndef AWGNCHANNEL_H
#define AWGNCHANNEL_H


#include "Channel.h"
#include <random>
#include <chrono>

class AWGNChannel : public Channel {
private:

    // varijansa suma
    float noiseVar; 

public:

    // konstruktori
    AWGNChannel();
    AWGNChannel(float, int);

    // destruktor
    ~AWGNChannel() override;

    // definisanje funkcije koja unosi gresku
    void insertErrors() override;


};


#endif