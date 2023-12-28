#include <iostream>
#include <cstdlib>  
#include "TestClass.h"
using namespace std;

int main() {

    // definisanje promenljivih
    bool useBscChannel = true;  // treba staviti false ukoliko se koristi AWGN Channel
    float errorRate = 0.2;     
    float nV = 0.2; 
    int length = 10; 

    // kreiranje objekta TestClass-a
    TestClass testClass(useBscChannel, nV, errorRate, length);
    
    // Generisanje random binarne sekvence
    float* inputSequence = new float[length];
    for (int i = 0; i < length; i++) {
        inputSequence[i] = rand() % 2 == 0 ? 1.0f : -1.0f;
    }

    // simulacija transmisije i demapiranja
    testClass.simulateTransmission(length, inputSequence);

    // oslobadjanje memorije
    delete[] inputSequence;

    return 0;
}

