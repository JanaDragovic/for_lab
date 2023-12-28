#ifndef DEMAPPER_INTERFACE_H
#define DEMAPPER_INTERFACE_H

#include <iostream>

class Demapper_Interface{
public:

    // funkcija koja ucitava primljeni niz simbola
    virtual void fillDemapper(int, float*) = 0;

    // funkcija koja vraca vrednosti procenjenih simbola
    virtual float* getOutput() = 0;

    // virtuelni destruktor
    virtual ~Demapper_Interface() {};

    // dohvatanje duzine niza
    virtual int getLength() = 0;
};

#endif