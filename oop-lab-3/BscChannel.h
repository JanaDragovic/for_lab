#ifndef BSCCHANNEL_H
#define BSCCHANNEL_H

#include "Channel.h"

class BscChannel : public Channel
{
private: 

    // verovatnoca greske
    float errorRate;

public:

    // konstruktori
    BscChannel();
    BscChannel(float, int);

    // destruktor
    ~BscChannel() override;

    // definisanje funkcije koja unosi gresku
    void insertErrors() override;


};



#endif