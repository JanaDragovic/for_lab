#include "Channel.h"

// konstruktori klase Channel
Channel::Channel() {
    length = 0;
    output = nullptr;
    outputCopy = nullptr;
}

Channel::Channel(int length) {
    this->length = length;
    output = new float[length];
    outputCopy = new float[length];
}

// ispunjavanje kanala poslatom sekvencom
void Channel::fillChannel(int length, float* sequence) {
    
    this->length = length;
    output = new float[length];

	for (int i = 0; i < length; i++) {
        output[i] = sequence[i];
    }

}

// funkcija za dohvatanje outputa
float* Channel::getOutput()
{
    outputCopy = new float[length];
    insertErrors();
    for (int i = 0; i < length; i++)
    {
        outputCopy[i] = output[i];
    }

    return outputCopy;
}

//destruktor
Channel::~Channel()
{
    delete[] output;
    delete[] outputCopy; 
}
