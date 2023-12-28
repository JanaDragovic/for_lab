#ifndef CHANNEL_INTERFACE_H
#define CHANNEL_INTERFACE_H

#include <iostream>

class Channel_Interface {
public:

    // funkcija koja ispunjava kanal ulaznim nizom simbola na koji se dodaju greske
    virtual void fillChannel(int, float*) = 0;

    // funkcija koja na izlaz kanala prosledjuje niz simbola sa greska 
    virtual float* getOutput() = 0;

    // virtuelni destruktor
    virtual ~Channel_Interface() {};
};

#endif