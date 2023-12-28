// TestClass.h

#ifndef TEST_CLASS_H
#define TEST_CLASS_H

#include "Channel_Interface.h"
#include "Demapper_Interface.h"

class TestClass {
public:
    TestClass(bool, float, float, int);

    // simulacija transmisije
    void simulateTransmission(int, float*);

    Channel_Interface* channel;
    Demapper_Interface* demapper;
};

#endif 
