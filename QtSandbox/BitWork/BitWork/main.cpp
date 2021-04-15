#include <iostream>
#include <bitset>
#define INT_SIZE 32

//A collection of Bit manipulation functions

//Set the bit in the referenced value
void setBit(int bit, int &value)
{
    int temp = 1 << bit;
    value |= temp;
}

//Clear the bit in the referenced value
void clearBit(int bit, int &value)
{
    int temp = 1 << bit;
    temp = ~temp;
    value &= temp;
}

//Take an 32-bit integer and turn it into an array
void getBoolArray(int value, bool (&array)[INT_SIZE])
{
    for(int i = 0; i < INT_SIZE; i++) {
        array[i] = (value >> i & 1);
    }
}

//Human read print of the boolean array
void printBoolArray(bool (&array)[INT_SIZE]) {

    std::cout << "Pringing bool array" << std::endl;
    auto __begin = std::begin(array);
    auto __end = std::end(array);
    for( ; __begin != __end; __begin++) { std::cout << *__begin; }
    std::cout << std::endl;
}

//Convert the bool array back into a 32 bit int
int getIntFromBoolArray(bool (&array)[INT_SIZE]) {

    int value = 0;
    for(int i = 0; i < INT_SIZE; i++) {

        if(array[i])
            setBit(i, value);
    }

    return value;
}

int main()
{

    for(int i = 0; i < INT_SIZE; i++) {

        int v = 0x00000000;
        setBit(i, v);
        std::cout << "Set Bit " << i << " : " << std::bitset<32>(v) << std::endl;
    }

    for(int i = 0; i < INT_SIZE; i++) {
        int v = 0xffffffff;
        clearBit(i, v);
        std::cout << "Clear Bit " << i << " : " << std::bitset<32>(v) << std::endl;
    }

    bool boolArray[INT_SIZE];

    getBoolArray(0x5555aaaa, boolArray);

    printBoolArray(boolArray);

    int bees = getIntFromBoolArray(boolArray);
    std::cout << "0x" << std::hex << bees << std::endl;
    return 0;
}

