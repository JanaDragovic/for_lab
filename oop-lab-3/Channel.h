#ifndef CHANNEL_H 
#define CHANNEL_H

#include "Channel_Interface.h"

class Channel : public Channel_Interface
{
protected:
    float* output;
    float* outputCopy;
    int length;

public:

    // konstruktori
    Channel();
    Channel(int);

    // nasledjene funkcije
    void fillChannel(int, float*) override;
    float* getOutput() override;

    // destruktor
    ~Channel() override;
 
    // virtuelna funkcija za unosenje greske
    virtual void insertErrors() = 0;
};


#endif