
#ifndef AWGN_DEMAPPER_H
#define AWGN_DEMAPPER_H

#include "Demapper.h"

class AWGNDemapper : public Demapper {
public:

    // konstruktori
    AWGNDemapper();
    AWGNDemapper(int);

    // destruktor
    ~AWGNDemapper() override;

    // demapiranje primljenih simbola
    float* demapp(float*) override;
    
};

#endif 