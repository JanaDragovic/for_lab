
#include "Demapper.h"
#include <cstring>

// konstruktori
Demapper::Demapper(int length)
{
    output = new float[length];
    outputCopy = new float[length];
    niz = new float[length];
    this->length = length;
    
}

Demapper::Demapper() {
    output = nullptr;
    outputCopy = nullptr;
    length = 0;
    niz = new float[length];

}

// destruktor
Demapper::~Demapper() {
    delete[] output;
    delete[] outputCopy;
    delete[] niz;
}

// ucitavanje primljenog niza simbola
void Demapper::fillDemapper(int length, float* receivedSymbols) {
    this->length = length;
    output = new float[length];
    niz = new float[length];
    niz = demapp(receivedSymbols);


    for (int i = 0; i < length; i++) {
        output[i] = niz[i];
    }
}

// procenjene vrednosti simbola
float* Demapper::getOutput() {
    outputCopy = new float[length];

    for (int i = 0; i < length; i++)
    {
        outputCopy[i] = output[i];
    }

    return outputCopy;
}

// dohvatanje duzine sekvence
int Demapper::getLength()
{
    return length;
}
