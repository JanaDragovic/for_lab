
#ifndef BSC_DEMAPPER_H
#define BSC_DEMAPPER_H

#include "Demapper.h"

class BscDemapper : public Demapper {
public:

    // konstruktori
    BscDemapper();
    BscDemapper(int);

    // destruktori
    ~BscDemapper() override;

    // demapiranje primljenih simbola
    float* demapp(float*) override;


};

#endif 