#include <iostream>
#include <fstream>
#include <ctime>
#include "mult.h"
#include "number.h"

void test1()
{
    Num n1, n2, n3;
    Multiplicator p;
    n1 = Multiplicator::createNumber(3);
    n2 = Multiplicator::createNumber(4);
    n3 = p.gradeSchoolMultiplication(n1, n2);
    std::cout << n1 << "\n" << n2 << "\n" << n3 << "\n";
}

void test2()
{
    Num n1, n2, n3;
    Multiplicator p;
    n1 = Multiplicator::createNumber(3);
    n2 = Multiplicator::createNumber(2);
    n3 = p.divideAndConquer(n1, n2);
    std::cout << n1 << "\n" << n2 << "\n" << n3 << "\n";
}

void test3(int k)
{
    Num n1, n2, n3;
    Multiplicator p;
    n1 = Multiplicator::createNumber(k);
    n2 = Multiplicator::createNumber(k);
    n3 = p.karatsubaAlgorithm(n1, n2);
    std::cout << n1 << "\n" << n2 << "\n" << n3 << "\n";
}

void test4()
{
    std::string k2 = "52019", k1 = "82866";
    Num y2(k2, 5), y1(k1, 5), y3 = y2 - y1;
    std::cout << y3;
    std::string s2 = "3821890069327520194547697288043", s3 = "1848978510057006585459418955744", s1 = "023218500004828662281329484743";
    Num x2(s2, 31), x3(s3, 31), x1(s1, 31), x4 = x2 - x1 - x3, x5 = x2 - x1;
    std::cout << x5;

}


void mainTest(int k, std::ofstream& out)
{
    Num n1, n2, n3, n4, n5;
    Multiplicator p;

    n1 = Multiplicator::createNumber(k);
    n2 = Multiplicator::createNumber(k);


    clock_t start = clock();
    n3 = p.gradeSchoolMultiplication(n1, n2);
    clock_t end = clock();

    double timeinsec = (double) (end - start) / CLOCKS_PER_SEC;
    out << k << ", " << timeinsec;

    start = clock();
    n4 = p.divideAndConquer(n1, n2);
    end = clock();

    timeinsec = (double) (end - start) / CLOCKS_PER_SEC;
    out << ", " << timeinsec;

    start = clock();
    n5 = p.karatsubaAlgorithm(n1, n2);
    end = clock();

    timeinsec = (double) (end - start) / CLOCKS_PER_SEC;
    out << ", " << timeinsec << "\n";
}

void mainTestAverage(int k, std::ofstream& outaverage)
{
    Num n1, n2, n3, n4, n5;
    Multiplicator p;
    double timeinsec1 = 0, timeinsec2 = 0, timeinsec3 = 0;
    for(int i = 0; i < 5; ++i)
    {
        n1 = Multiplicator::createNumber(k);
        n2 = Multiplicator::createNumber(k);


        clock_t start1 = clock();
        n3 = p.gradeSchoolMultiplication(n1, n2);
        clock_t end1 = clock();

        timeinsec1 += (double) (end1 - start1) / CLOCKS_PER_SEC;

        clock_t start2 = clock();
        n4 = p.divideAndConquer(n1, n2);
        clock_t end2 = clock();

        timeinsec2 += (double) (end2 - start2) / CLOCKS_PER_SEC;

        clock_t start3 = clock();
        n5 = p.karatsubaAlgorithm(n1, n2);
        clock_t end3 = clock();

        timeinsec3 += (double) (end3 - start3) / CLOCKS_PER_SEC;

    }
    outaverage << k << ", " << timeinsec1 / 5;
    outaverage << ", " << timeinsec2 / 5;
    outaverage << ", " << timeinsec3 / 5 << "\n";
}



int main()
{
    std::ofstream out("/Users/macbook/Desktop/dat.csv");
    for (int i = 1; i <= 20; ++i)
        mainTest(20 * i, out);
    std::ofstream outaverage("/Users/macbook/Desktop/file.csv");
    for (int i = 1; i <= 20; ++i)
        mainTestAverage(20 * i, outaverage);
    return 0;
}
