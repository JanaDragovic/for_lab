#include "BscDemapper.h"

// konstruktori
BscDemapper::BscDemapper() {
    output = nullptr;
    outputCopy = nullptr;
}

BscDemapper::BscDemapper(int length) {
    this->length = length;
    output = new float[length];
    outputCopy = new float[length];
}

// destruktor
BscDemapper::~BscDemapper() {
    delete[] output;
    delete[] outputCopy;
}

// demapiranje primljenih simbola u zavisnosti od uslova zadatka
// ulaz=-1 izlaz=1, ulaz=1, izlaz=0
float* BscDemapper::demapp(float* sequence) {

    /*for (int i = 0; i < length; ++i) {
        if (outputCopy[i] == -1.0f) {
            output[i] = 1.0f;
        }
        else if (outputCopy[i] == 1.0f) {
            output[i] = 0.0f;
        }
        else {
            output[i] = -1.0f;
        }
    }*/

    
    float* izlaz = new float[length];
    for (int i = 0; i < length; i++)
    {
        if (sequence[i] > 0) {
            izlaz[i] = 0;
        }
        else izlaz[i] = 1;
    }
    return izlaz;
   
}
