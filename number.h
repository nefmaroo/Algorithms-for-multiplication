#ifndef WORKSHOP01_NUMBER_H
#define WORKSHOP01_NUMBER_H

#include "mult.h"

struct Num
{
    typedef unsigned short Short;
    typedef unsigned int Byte;
    typedef std::pair<Num, Num> Halves;

    Num() : size(0), base("") {}                // default constructor
    ~Num() {}                                   // default destructor
    Num(Short length, Byte dig);                // constructor that create a number of a given length consisting of a certain digit
    Num(std::string& str, Short k);             // constructor that create number using a string

    Short getSize() const;
    Byte getDigit(Short k) const;
    void setDigit(Short k, Byte dig);


    void addZeros(Short left, Short right);                // function for adding zeros to a number to a given place
    Halves getHalf(Short length) const;                // separate number to halves and return them as a pair of numbers
    Num multiplyByPowerOfTen(Short length) const;      // function of multiplication a number by certain power of ten
    Num operator+(const Num& n2) const;         // add two numbers
    Num operator-(const Num& n2) const;         // substract one number from another
    void operator=(const Num&);
    static void delereZeros(Num&);              // delete insignificant zeros
    std::ostream& operator<<(std::ostream& s);  // output a number

    Short size;
    std::string base;
}; //class Num

std::ostream& operator<<(std::ostream& s, Num&);

#endif //WORKSHOP01_NUMBER_H
