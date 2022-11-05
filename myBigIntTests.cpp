#include <gtest/gtest.h>

#include <sstream>


#include <myBigInt.h>

using namespace mybigint;

TEST(myBigInt, converting_from_dec_to_binary_21)
{
    EXPECT_EQ("10101",DecToBinConverter("21"));
}

TEST(myBigInt, converting_from_bin_to_dec_21)
{
    EXPECT_EQ("21", BinToDecConverter("10101"));
}

TEST(myBigInt, converting_from_dec_to_binary_0)
{
    EXPECT_EQ("0", DecToBinConverter("0"));
}

TEST(myBigInt, converting_from_bin_to_dec_0)
{
    EXPECT_EQ("0", DecToBinConverter("0"));
}

TEST(myBigInt, converting_from_dec_to_binary_32)
{
    EXPECT_EQ("100000", DecToBinConverter("32"));
}

TEST(myBigInt, converting_from_bin_to_dec_32)
{
    EXPECT_EQ("32", BinToDecConverter("100000"));
}

TEST(myBigInt, converting_from_dec_to_binary_7413)
{
    EXPECT_EQ("1110011110101", DecToBinConverter("7413"));
}

TEST(myBigInt, converting_from_bin_to_dec_7413)
{
    EXPECT_EQ("7413", BinToDecConverter("1110011110101"));
}

TEST(myBigInt, converting_bin_string_to_vec_string)
{
    EXPECT_EQ(7413, binStringToBinVec("1110011110101")[0]);
}

TEST(myBigInt,add_two_small_numbers)
{
    std::ostringstream ss;

    BigInt a{"42"};
    BigInt b{"8"};
    a+=b;
    ss<<a;

    EXPECT_EQ("50",ss.str());
}

TEST(myBigInt, add_two_big_numbers)
{
    std::ostringstream ss;

    BigInt a{"40030133113"};
    BigInt b{"41341341341323"};
    ss << (a+b);

    EXPECT_EQ("41381371474436", ss.str());
}

TEST(myBigInt, adding_zero_to_a_number)
{
    std::ostringstream ss;

    BigInt a{"134"};
    BigInt b;
    ss << (a + b);

    EXPECT_EQ("134", ss.str());
}

TEST(myBigInt, adding_a_small_negative_number_to_a_positive_number)
{
    std::ostringstream ss;

    BigInt a{"134"};
    BigInt b{"-3"};
    ss << (a + b);

    EXPECT_EQ("131", ss.str());
}

TEST(myBigInt, adding_a_big_negative_number_to_a_positive_number)
{
    std::ostringstream ss;

    BigInt a{"124"};
    BigInt b{"-140"};
    ss << (a + b);

    EXPECT_EQ("-16", ss.str());
}

TEST(myBigInt, adding_a_negative_number_to_a_positive_number_of_same_size)
{
    std::ostringstream ss;

    BigInt a{"134"};
    BigInt b{"-140"};
    ss << (a + b);

    EXPECT_EQ("-6", ss.str());
}

TEST(myBigInt, substracting_same_number)
{
    std::ostringstream ss;

    BigInt a{"140"};
    BigInt b{"-140"};
    ss << (a + b);

    EXPECT_EQ("0", ss.str());
}

TEST(myBigInt, adding_a_positive_number_to_a_negative_number_of_same_size)
{
    std::ostringstream ss;

    BigInt a{"134"};
    BigInt b{"-140"};
    ss << (b + a);

    EXPECT_EQ("-6", ss.str());
}

TEST(myBigInt, adding_a_small_positive_number_to_a_negative_number)
{
    std::ostringstream ss;

    BigInt a{"124"};
    BigInt b{"-140"};
    ss << (a + b);

    EXPECT_EQ("-16", ss.str());
}

TEST(myBigInt, adding_a_big_positive_number_to_a_negative_number)
{
    std::ostringstream ss;

    BigInt a{"134"};
    BigInt b{"-3"};
    ss << (b + a);

    EXPECT_EQ("131", ss.str());
}

TEST(myBigInt, negating_a_positive_number)
{
    std::ostringstream ss;
    BigInt a{"431"};
    ss << -a;

    EXPECT_EQ("-431", ss.str());
}

TEST(myBigInt, negating_a_positive_number_twice)
{
    std::ostringstream ss;

    BigInt a{"431"};
    ss << -(-a);

    EXPECT_EQ("431", ss.str());
}

TEST(myBigInt, substracting_two_numbers)
{
    std::ostringstream ss;

    BigInt a{"934"};
    BigInt b{"34"};

    auto r=a-b;
    ss << r;

    EXPECT_EQ("900",ss.str());
}

TEST(myBigInt, multiplying_two_positive_numbers)
{
    std::ostringstream ss;

    BigInt a{"9"};
    BigInt b{"6"};

    a*=b;

    ss << a;

    EXPECT_EQ("54", ss.str());
}

TEST(myBigInt, multiplying_two_negative_numbers)
{
    std::ostringstream ss;

    BigInt a{"-9"};
    BigInt b{"-6"};

    a *= b;

    ss << a;

    EXPECT_EQ("54", ss.str());
}

TEST(myBigInt, multiplying_two_numbers_of_opposite_sign)
{
    std::ostringstream ss;

    BigInt a{"-1514131211"};
    BigInt b{"12131415"};

    ss << a * b;

    EXPECT_EQ("-18368554085093565", ss.str());
}

TEST(myBigInt, left_shifting_2_by_2)
{
    std::ostringstream ss;

    BigInt a{"2"};

    ss << (a << 2);

    EXPECT_EQ("8", ss.str());
}

TEST(myBigInt, right_shifting_16_by_2)
{
    std::ostringstream ss;

    BigInt a{"16"};

    ss << (a >> 2);

    EXPECT_EQ("4", ss.str());
}

TEST(myBigInt, right_shifting_16_by_5)
{
    std::ostringstream ss;

    BigInt a{"16"};

    ss << (a >> 5);

    EXPECT_EQ("0", ss.str());
}

TEST(myBigInt, right_shifting_16_by_4)
{
    std::ostringstream ss;

    BigInt a{"16"};

    ss << (a >> 4);

    EXPECT_EQ("1", ss.str());
}

TEST(myBigInt, spliting_32_into_two_2_equal_halves)
{
    std::ostringstream ss;

    BigInt a{"32"};

    auto pair= splitIntoTwoParts(a,3);

    ss << pair.first;
    EXPECT_EQ("4", ss.str());
    ss.str(std::string{});

    ss<<pair.second;
    EXPECT_EQ("0",ss.str());
}

TEST(myBigInt, spliting_4_into_two_halves)
{
    std::ostringstream ss;

    BigInt a{"4"};

    auto pair = splitIntoTwoParts(a, 2);

    ss << pair.first;
    EXPECT_EQ("1", ss.str());
    ss.str(std::string{});

    ss << pair.second;
    EXPECT_EQ("0", ss.str());
}

TEST(myBigInt, multiplying_two_huge_numbers_of_opposite_sign)
{
    std::ostringstream ss;

    BigInt a{"-1514131211452451234515145143"};
    BigInt b{"12131415524525252451343511"};

    ss << a * b;

    EXPECT_EQ("-18368554884782494624721116408367698691001027516217073", ss.str());
}