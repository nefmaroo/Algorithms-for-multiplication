#include "number.h"
#include <string>

Num::Num(Short length, Byte dig)
{
    size = length;
    base.append(length, (char) dig);
}

Num::Num(std::string& str, Short k)
{
    size = k;
    base = str;
}

Num::Short Num::getSize() const
{
    return base.size();
}

Num::Byte Num::getDigit(Short k) const
{
    if (k < getSize())
        return (Byte) (base[k] - 48);
    return 0;
}

void Num::setDigit(Short k, Byte dig)
{
    base[k] = (char) (dig + 48);
}

void Num::addZeros(Short r, Short l)
{
    while (r < l)
    {
        this->setDigit(r, 0);
        ++r;
    }
}


void Num::delereZeros(Num& number)
{
    Num::Short k = number.getSize();
    while (number.getDigit(k - 1) == 0)
    {
        if ((k == 1 && number.base == "0") || (number.base == "" && k == 0))
            break;
        number.base.erase(k - 1);
        --k;
    }
    number.size = number.base.size();
}

Num::Halves Num::getHalf(Short m) const
{
    Short k = m / 2;
    Halves pair;
    std::string s1, s2;
    if (m % 2)
    {
        for (Short i = 0; i < k; ++i)
            s1 += (getDigit(i) + '0');
        for (Short i = k; i <= 2 * k; ++i)
            s2 += (getDigit(i) + '0');
        pair = {Num(s1, k), Num(s2, k + 1)};
    }
    else
    {
        for (Short i = 0; i < k; ++i)
            s1 += (getDigit(i) + '0');
        for (Short i = k; i < 2 * k; ++i)
            s2 += (getDigit(i) + '0');
        pair = {Num(s1, k), Num(s2, k)};
    }
    return pair;
}

Num Num::multiplyByPowerOfTen(Short k) const
{
    Num res;
    res.base.append(k, '0');
    res.base += base;
    delereZeros(res);
    res.size = res.getSize();
    return res;
}

void Num::operator=(const Num& number)
{
    size = number.size;
    base = number.base;
}


Num Num::operator+(const Num& n2) const
{
    Short m = std::max(size, n2.size);
    Num result(m + 1, 0);
    Byte carry = 0;
    for (Short i = 0; i <= m; ++i)
    {
        Byte dig = Multiplicator::baseAdd(getDigit(i), n2.getDigit(i), carry);
        result.setDigit(i, dig);
    }
    delereZeros(result);
    return result;
}


Num Num::operator-(const Num& n2) const
{
    Short m = std::max(size, n2.size);
    Num result(m, 0);
    Byte carry = 0;
    for (Short i = 0; i < m; ++i)
    {
        Byte dig = Multiplicator::baseSubstraction(getDigit(i), n2.getDigit(i), carry);
        result.setDigit(i, dig);
    }
    delereZeros(result);
    return result;
}

std::ostream& Num::operator<<(std::ostream& s)
{
    Num number = *this;
    Num::Short k = number.getSize();
    while (number.getDigit(k - 1) == 0)
    {
        if ((k == 1 && number.base == "0") || (number.base == "" && k == 0))
            break;
        number.base.erase(k - 1);
        --k;
    }
    std::reverse(number.base.begin(), number.base.end());
    s << number.base;
    return s;

}

std::ostream& operator<<(std::ostream& s, Num& num)
{
    Num number = num;
    Num::delereZeros(number);
    std::reverse(number.base.begin(), number.base.end());
    s << number.base;
    return s;

}