#ifndef MYBIGINT_H
#define MYBIGINT_H

#include <string>
#include <vector>
#include <iostream>

namespace mybigint
{
    std::string DecToBinConverter(const std::string& number);
    std::string BinToDecConverter(const std::string& number);
    std::vector<uint32_t> binStringToBinVec(const std::string& number);


    class BigInt
    {
        public:
        BigInt() = default;
        BigInt(const std::string& integer);
        
        bool isNegative() const;
        std::string getNumber() const;

        BigInt& operator+=(const BigInt& rop);
        BigInt& operator-=(const BigInt& rop);
        BigInt& operator*=(const BigInt& rop);
        BigInt& operator/=(const BigInt& rop);
        BigInt& operator%=(const BigInt &ro);
        BigInt& operator-();

        BigInt operator<<(size_t shiftAmount) const;
        BigInt operator>>(size_t shiftAmount) const;

        private:
        std::string my_number{"0"};
        bool is_negative{false};

        friend BigInt slowMult(const std::string& lop, const std::string& rop);
        friend std::pair<BigInt,BigInt> splitIntoTwoParts(const BigInt& num, size_t lowerPartSize);
    };
    
    bool isNull(const BigInt& op);
    BigInt operator+(const BigInt& lo, const BigInt& ro);
    BigInt operator-(const BigInt& lo,const BigInt& ro);
    BigInt operator*(const BigInt& lo, const BigInt& ro);
    BigInt operator/(const BigInt &lo, const BigInt &ro);
    BigInt operator%(const BigInt &lo, const BigInt &ro);

    BigInt operator-(const BigInt& op);

    bool operator==(const BigInt& lo, const BigInt& ro);
    bool operator!=(const BigInt &lo, const BigInt &ro);
    bool operator>=(const BigInt &lo, const BigInt &ro);
    bool operator>(const BigInt &lo, const BigInt &ro);
    bool operator<=(const BigInt &lo, const BigInt &ro);
    bool operator<(const BigInt &lo, const BigInt &ro);

    std::ostream& operator<<(std::ostream& out, const BigInt& bint);
}

#endif