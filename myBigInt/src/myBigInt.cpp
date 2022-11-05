#include <myBigInt.h>
#include <algorithm>
#include <stdexcept>

namespace
{
    const size_t BRANCH_FACTOR{32};
    static_assert(sizeof(uint32_t)==4);
    std::string trimLeadingZeroes(const std::string& string)
    {
        std::string out = string;

        out.erase(out.begin(),std::find_if(out.begin(),out.end(),[](const unsigned char c)
        {
            return c!='0';
        }
        ));
        
        if(out.empty())
        {
            return "0";
        }

        return out;
    }

    std::string trimTrailingZeroes(const std::string &string)
    {
        std::string out = string;

        auto pivot = std::find_if(std::rbegin(out),std::rend(out),[](const unsigned char c)
        {
            return c != '0'; 
        });
        
        out.erase(pivot.base(),out.end()); //what if pivot = rbegin?

        if (out.empty())
        {
            return "0";
        }

        return out;
    }

    std::pair<std::string, std::string> divisionStep(const std::string& dividend,uint32_t _divisor,uint32_t _base) //helper for DecToBinConv
    {
        const uint32_t divisor = _divisor;
        const uint32_t base = _base;

        uint32_t t = 0;

        std::string quotient;
        
        for(auto d : dividend)
        {
            t*=base;
            t += (d - '0');
            quotient.push_back((t / divisor) + '0');
            t %= divisor;
        }
        quotient = trimLeadingZeroes(quotient);

        return {std::move(quotient),std::to_string(t)};
    }

    std::string baseConverter(const std::string &number, uint32_t from_base, uint32_t to_base)
    {
        auto qr = divisionStep(number, to_base, from_base);

        std::string res;

        while (qr.first != "0")
        {
            res.push_back(qr.second[0]);
            qr = divisionStep(qr.first, to_base, from_base);
        }
        res.push_back(qr.second[0]);

        std::reverse(res.begin(), res.end());

        return res;
    }

    std::string naiveBinStrAdd(const std::string &str1, const std::string &str2) // assumes str1.size >= str2.size
    {
        std::string res = str1;
        for(int i=0;i<str2.size();i++)
        {
            res[i] += (str2[i] - '0');
        }
        
        return res;
    }

    std::string parseCarryBinStr(const std::string& str)
    {
        std::string res = str;

        for(int i=0;i<res.size()-1;i++)
        {
            res[i + 1] += ((res[i] - '0') / 2);
            res[i] = '0' + (res[i] - '0') % 2;
        }

        if (res.back() > '1')
        {
            res.push_back( ((res.back() - '0') /2) + '0');
            res[res.size()-2]='0' + (res[res.size()-2] - '0')%2;
        }
        return res;
    }

    std::string binStrAdd(const std::string& str1, const std::string& str2) //assumes str1.size >= str2.size
    {
        std::string res = str1;

        res = naiveBinStrAdd(str1,str2);
        res = parseCarryBinStr(res);

        return res;
    }

    std::string twosComplement(const std::string &number)
    {
        std::string out = number;
        auto itr = std::begin(out);
        for (; itr != std::end(out) && *itr == '0'; itr++)
            ;

        if (itr == std::end(out))
        {
            return out;
        }

        itr++;

        for (; itr != std::end(out); itr++)
        {
            *itr = (*itr == '0' ? '1' : '0');
        }

        return out;
    }

    bool positivePositive(std::string& my_number, std::string& op1, std::string& op2)
    {
        if (op1.size() > op2.size())
        {
            my_number = binStrAdd(op1, op2);
        }
        else
        {
            my_number = binStrAdd(op2, op1);
        }

        return false;
    }

    bool positiveNegative(std::string& my_number, std::string& op1, std::string& op2)
    {
        if (op1.size() > op2.size())
        {
            op2.resize(op1.size() + 1, '0');
            op1.resize(op1.size() + 1, '0');

            op2 = twosComplement(op2);

            my_number = binStrAdd(op1, op2);
            my_number.pop_back();
            my_number = trimTrailingZeroes(my_number);
            
            return false;
        }
        else if (op1.size() < op2.size())
        {
            op1.resize(op2.size() + 1, '0');
            op2.resize(op2.size() + 1, '0');

            op2 = twosComplement(op2);

            my_number = binStrAdd(op1, op2);
            my_number = twosComplement(my_number);
            my_number = trimTrailingZeroes(my_number);

            return true;
        }
        else
        {
            op1.push_back('0');
            op2.push_back('0');

            op2 = twosComplement(op2);

            my_number = binStrAdd(op1, op2);
            if (my_number.size() > op1.size())
            {
                my_number.pop_back();
                my_number = trimTrailingZeroes(my_number);
                return false;
            }
            else if (my_number.size() == op1.size())
            {
                my_number = twosComplement(my_number);
                my_number = trimTrailingZeroes(my_number);

                return true;
            }
            else
            {
                throw std::runtime_error{"possibility not took into consideration"};
            }
        }
    }
}

namespace mybigint
{
    std::string DecToBinConverter(const std::string &number)
    {
        return baseConverter(number,10,2);
    }

    std::string BinToDecConverter(const std::string &number)
    {
        return baseConverter(number,2,10);
    }

    std::vector<uint32_t> binStringToBinVec(const std::string &number)
    {
        std::vector<uint32_t> res;
        for(int endi=number.size()-1;endi>=0;endi-=32)
        {
            res.push_back(std::stoull(number.substr(std::max(0,endi-32),32),nullptr,2));
        }

        return res;
    }

    BigInt& BigInt::operator-()
    {
        this->is_negative=!this->is_negative;
        return *this;
    }

    BigInt& BigInt::operator+=(const BigInt &rop)
    {
        std::string op1 = my_number;
        std::string op2 = rop.my_number;

        switch(this->isNegative()*2 + rop.isNegative())
        {
            case 0:
            this->is_negative = positivePositive(this->my_number,op1,op2);
            break;
            
            case 1:
            this->is_negative =positiveNegative(this->my_number,op1,op2);
            break;

            case 2:
            this->is_negative=positiveNegative(this->my_number,op2,op1);
            break;

            case 3:
            this->is_negative=!positivePositive(this->my_number,op1,op2);
            break;
        }

        return *this;
    }
    
    BigInt slowMult(const std::string& lop, const std::string& rop) 
    {
        BigInt temp{};
        BigInt out{};

        for (int i = 0; i < lop.size(); i++)
        {
            if (lop[i] == '0')
            {
                continue;
            }

            temp.my_number = std::string(i, '0');
            temp.my_number += rop;

            out += temp;
        }

        return out;
    }


    BigInt BigInt::operator<<(size_t shiftAmount) const
    {
        if(isNull(*this))
        {
            return {};
        }

        BigInt temp{*this};

        temp.my_number= std::string(shiftAmount,'0') + temp.my_number;

        return temp;
    }

    BigInt BigInt::operator>>(size_t shiftAmount) const
    {
        if(isNull(*this))
        {
            return {};
        }

        if(shiftAmount >= my_number.size() )
        {
            return {};
        }

        BigInt temp{*this};

        temp.my_number = temp.my_number.substr(shiftAmount);

        return temp;
    }
    BigInt& BigInt::operator*=(const BigInt& rop)
    {

        if(std::min(this->my_number.size(),rop.my_number.size()) < BRANCH_FACTOR)
        {
            BigInt out = slowMult(this->my_number, rop.my_number);

            out.is_negative = this->isNegative() ^ rop.isNegative();

            *this = std::move(out);

            return *this;
        }

        size_t lowerPartSize = std::max(this->my_number.size(),rop.my_number.size())/2;

        auto upperLowerPairOp1 = splitIntoTwoParts(*this,lowerPartSize); 
        auto upperLowerPairOp2 = splitIntoTwoParts(rop,lowerPartSize);

        BigInt t=((upperLowerPairOp1.first + upperLowerPairOp1.second)*(upperLowerPairOp2.first + upperLowerPairOp2.second));
        BigInt upperupper = upperLowerPairOp1.first * upperLowerPairOp2.first;
        BigInt lowerlower = upperLowerPairOp1.second * upperLowerPairOp2.second;

        BigInt p1 = upperupper << (lowerPartSize * 2);
        BigInt p2 =  (t - (upperupper + lowerlower))<<lowerPartSize;
        BigInt p3 = std::move(lowerlower);

        *this = (p1 + p2 + p3);

        return *this;
    }

    bool isNull(const BigInt &op)
    {
        return op.getNumber()=="0";
    }

    std::pair<BigInt, BigInt> splitIntoTwoParts(const BigInt &num, size_t lowerPartSize)
    {
        BigInt upper = num >> lowerPartSize;

        BigInt lower{};
        lower.my_number = trimTrailingZeroes(num.my_number.substr(0,std::min(lowerPartSize,num.my_number.size())));
        lower.is_negative=num.is_negative;

        return {std::move(upper),std::move(lower)};
    }

    std::string BigInt::getNumber() const
    {
        auto res = my_number;
        std::reverse(res.begin(),res.end());
        
        return res;
    }

    std::ostream &operator<<(std::ostream &out, const BigInt &bint)
    {
        out << (bint.isNegative()?"-":"") << BinToDecConverter(bint.getNumber());
        
        return out;
    }

    BigInt operator*(const BigInt &lo, const BigInt &ro)
    {
        BigInt temp{lo};

        return temp*=ro;
    }

    BigInt::BigInt(const std::string& integer) : my_number{integer}
    {
        if(my_number[0]=='-')
        {
            this->is_negative=true;
            my_number.erase(0,1);
        }

        my_number=DecToBinConverter(my_number);
        std::reverse(my_number.begin(),my_number.end());
    }

    BigInt operator+(const BigInt &lo, const BigInt &ro)
    {
        BigInt temp{lo};

        return temp+=ro;
    }

    BigInt operator-(const BigInt &lo, const BigInt &ro)
    {
        return lo + (-ro);
    }

    BigInt operator-(const BigInt &op)
    {
        BigInt temp{op};
        return -temp;
    }

    bool BigInt::isNegative() const
    {
        return is_negative;
    }
}