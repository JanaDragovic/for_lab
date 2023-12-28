#include "TestClass.h"
#include "BscChannel.h"
#include "AWGNChannel.h"
#include "BscDemapper.h"
#include "AWGNDemapper.h"
#include <iostream>

using namespace std;

// konstruktor 
//kreira objekte u zavisnosti od toga koji se kanal koristi
TestClass::TestClass(bool useBscChannel, float nv, float er, int len) {
    if (useBscChannel==true) {

        channel = new BscChannel(nv, len);

        demapper = new BscDemapper(len);
    }
    else {
        channel = new AWGNChannel(er, len);
        demapper = new AWGNDemapper(len);
    }
}

// simulacija transmisije
void TestClass::simulateTransmission(int len, float* inputSymbols) {

    // ispunjavanje kanala unesenim simbolima
    channel->fillChannel(len, inputSymbols);
    float* receivedSymbols = channel->getOutput();

    // ucitavanje primljenog niza simbola
    demapper->fillDemapper(len, receivedSymbols);
    float* outputSymbols = demapper->getOutput();

    //int size = demapper->getLength();
    
    

    // prebrojavanje greski u kanalu
    int errorCount = 0;
    for (int i = 0; i < len; i++) {
        if (inputSymbols[i] != outputSymbols[i]) {
            errorCount++;
        }
    }

    std::cout << "Input Sequence: ";
    for (int i = 0; i < len; ++i) {
        std::cout << inputSymbols[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Received Sequence: ";
    for (int i = 0; i < len; ++i) {
        std::cout << receivedSymbols[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Demapped Sequence: ";
    for (int i = 0; i < len; ++i) {
        std::cout << outputSymbols[i] << " ";
    }
    std::cout << std::endl;
   std::cout << "Number of Errors: " << errorCount << std::endl;
}


    

