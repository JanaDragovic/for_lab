#ifndef DEMAPPER_H
#define DEMAPPER_H

#include "Demapper_Interface.h"

class Demapper : public Demapper_Interface {
protected:
    float* output;
    float* outputCopy;
    int length;
    float* niz;

public:
    // konstruktori
    Demapper(int);
    Demapper();
    ~Demapper() override;

    // naslednjene funkcije
    void fillDemapper(int, float*) override;
    float* getOutput() override;
    int getLength()  override;

    // virtuelna funkcija za demapiranje
    virtual float* demapp(float*) = 0; 

};

#endif 