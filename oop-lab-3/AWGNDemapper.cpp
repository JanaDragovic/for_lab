
#include "AWGNDemapper.h"

// konstruktori
AWGNDemapper::AWGNDemapper() {
    output = nullptr;
    outputCopy = nullptr;
    length = 0;
}

AWGNDemapper::AWGNDemapper(int length) {
    output = new float[length];
    outputCopy = new float[length];
    this->length = length;
}

// destruktor
AWGNDemapper::~AWGNDemapper() {
    delete[] output;
    delete[] outputCopy;
}

// demapiranje primljenih simbola u zavisnosti od uslova zadatka
//ulaz=-1 izlaz = 1, ulaz = 1, izlaz = 0
float* AWGNDemapper::demapp(float* sequence) {
    float* izlaz = new float[length];
    for (int i = 0; i < length; i++)
    {
        if (sequence[i] > 0) {
            izlaz[i] = 0;
        }
        else izlaz[i] = 1;
    }
    return izlaz;

    /*for (int i = 0; i < length; ++i) {
        float sign = (sequence[i] >= 0.0f) ? 1.0f : -1.0f;
        if (sign == -1.0f) {
            izlaz[i] = 1.0f;
        }
        else if (sign == 1.0f) {
            izlaz[i] = 0.0f;
        }
        else {
            izlaz[i] = -1.0f;
        }

        return izlaz;*/

    /*float* izlaz = new float[length];
    for (int i = 0; i < length; i++)
    {
        if (sequence[i] > 0) {
            izlaz[i] = 0;
        }
        else izlaz[i] = 1;
    }
    return izlaz;
    */

}
