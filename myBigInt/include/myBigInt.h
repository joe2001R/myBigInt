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
        BigInt& operator-();

        private:
        std::string my_number{"0"};
        bool is_negative{false};
    };
    

    BigInt operator+(const BigInt& lo, const BigInt& ro);
    BigInt operator-(const BigInt& lo,const BigInt& ro);
    
    BigInt operator-(const BigInt& op);

    std::ostream& operator<<(std::ostream& out, const BigInt& bint);
}

#endif