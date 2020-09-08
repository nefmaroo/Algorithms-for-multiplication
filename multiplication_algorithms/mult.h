#ifndef WORKSHOP01_ALG_H
#define WORKSHOP01_ALG_H

#include <iostream>
#include <string>
#include <random>
#include "number.h"

struct Num;

class Multiplicator
{
public:
    typedef unsigned short Short;
    typedef unsigned int Byte;
    typedef std::pair<Num, Num> Halves;
    typedef std::vector<Num> Nums;

    static Num createNumber(Short k);
    static Byte baseMult(Byte d1, Byte d2, Byte& carry);                    // multiply two digits
    static Byte baseAdd(Byte, Byte, Byte&);                                 // add two digits
    static Byte baseSubstraction(Byte d1, Byte d2, Byte& carry);            // substraction of digits d1 and d2
    static Num gradeSchoolMultiplication(const Num& n1, const Num& n2);
    static Num calcNums(const Nums& numbers);                               // add several numbers from vector
    static Num divideAndConquer(const Num& n1, const Num& n2);
    static Num karatsubaAlgorithm(const Num& n1, const Num& n2);
}; //class Multiplicator


#endif //WORKSHOP01_ALG_H
