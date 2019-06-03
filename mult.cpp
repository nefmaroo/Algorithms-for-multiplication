#include <utility>
#include <iostream>
#include <random>
#include <climits>
#include <string>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include "mult.h"

Num Multiplicator::createNumber(Short k)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::string a;
    if (k == 1)
    {
        std::uniform_int_distribution<> d2(0, 9);
        a.push_back(static_cast<char>(48 + d2(gen)));
    }
    else
    {
        std::uniform_int_distribution<> d1(1, 9);
        std::uniform_int_distribution<> d2(0, 9);
        for (int i = 0; i < k - 1; ++i)
        {
            a.push_back(static_cast<char>(48 + d2(gen)));
        }
        a.push_back(static_cast<char>(48 + d1(gen)));
    }
    Num number(a, k);
    return number;
}


Num::Byte Multiplicator::baseMult(Byte d1, Byte d2, Byte& carry) // const
{
    Byte mult = (d1 * d2) + carry;
    carry = (Byte) (mult / 10);
    return (Byte) (mult % 10);
}

Multiplicator::Byte Multiplicator::baseAdd(Byte d1, Byte d2, Byte& carry)
{
    Byte sum = (d1 + d2) + carry;
    carry = (Byte) (sum / 10);
    return (Byte) (sum % 10);
}

Multiplicator::Byte Multiplicator::baseSubstraction(Byte d1, Byte d2, Byte& carry)
{
    Byte sub = 0;
    //std::cout << d1 - carry << " " << d2 << " " << carry << "\n";
    if (d1 - carry < d2 || (d1 == 0 && carry == 1))
    {
        sub = (10 - d2 + d1) - carry;
        carry = 1;
    }
    else
    {
        sub = d1 - d2 - carry;
        carry = 0;
    }
    return sub;
}

Num Multiplicator::calcNums(const Nums& numbers) //const
{
    Short k = numbers[0].size;
    Num result(k, 0);
    result = numbers[0];
    for (Short i = 1; i < k / 2; ++i)
        result = result + numbers[i];
    return result;
}

Num Multiplicator::gradeSchoolMultiplication(const Num& n1, const Num& n2)// const
{
    Short m = std::max(n1.size, n2.size);
    Nums res(m);
    Num k(2 * m, 0);
    for (Short i = 0; i < m; ++i)
    {
        res[i] = k;
        Byte carry = 0;
        Num& add = res[i];
        for (Short j = 0; j < m; ++j)
        {
            add.addZeros(0, i);
            Byte dig = baseMult(n1.getDigit(i), n2.getDigit(j), carry);
            add.setDigit(i + j, dig);
        }
        add.setDigit(i + m, carry);
        add.addZeros(m + i + 1, 2 * m);
    }
    return calcNums(res);
}


Num Multiplicator::divideAndConquer(const Num& n1, const Num& n2) //const
{
    if (n1.size == 1 || n2.size == 1)
        return gradeSchoolMultiplication(n1, n2);
    Short m = std::max(n1.size, n2.size);
    Halves a, b;
    a = n1.getHalf(m);
    b = n2.getHalf(m);
    if (m % 2)
        --m;
    Num x1, x2, x3, x4;
    x1 = divideAndConquer(a.second, b.second);
    x2 = divideAndConquer(a.first, b.second);
    x3 = divideAndConquer(a.second, b.first);
    x4 = divideAndConquer(a.first, b.first);
    return x1.multiplyByPowerOfTen(m) + (x2 + x3).multiplyByPowerOfTen(m / 2) + x4;
}


Num Multiplicator::karatsubaAlgorithm(const Num& n1, const Num& n2) //const
{
    if (n1.getSize() == 1 || n2.getSize() == 1)
        return gradeSchoolMultiplication(n1, n2);
    Short m = std::max(n1.getSize(), n2.getSize());
    Halves a, b;
    a = n1.getHalf(m);
    b = n2.getHalf(m);
    if (m % 2)
        --m;
    Num x1, x2, x3;
    x1 = karatsubaAlgorithm(a.second, b.second);
    x2 = karatsubaAlgorithm(a.first + a.second, b.first + b.second);
    x3 = karatsubaAlgorithm(a.first, b.first);
    Num x4 = x1.multiplyByPowerOfTen(m) + (x2 - x1 - x3).multiplyByPowerOfTen(m / 2) + x3;
    return x4;
}