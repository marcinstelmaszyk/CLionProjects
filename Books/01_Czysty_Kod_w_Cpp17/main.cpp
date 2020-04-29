#include <iostream>
#include "gtest/gtest.h"

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

std::string convertArabicToRoman(unsigned int arabic) {
    std::string romanNumeral;
    while (arabic >= 10) {
        romanNumeral += "X";
        arabic -= 10;
    }
    while (arabic--) {
        romanNumeral += "I";
    }
    return romanNumeral;
}

class RomanNumeralAssert {
public:
    RomanNumeralAssert() = delete;
    explicit RomanNumeralAssert(const unsigned int arabic) :
        arabicNumberToConvert(arabic) {}
    void isConvertedTo(const std::string& expectedRomanNumeral) const {
        ASSERT_EQ(expectedRomanNumeral, convertArabicToRoman(arabicNumberToConvert));
    }
private:
    unsigned int arabicNumberToConvert;
};

RomanNumeralAssert assertThat(const unsigned int arabicNumber) {
    RomanNumeralAssert assert {arabicNumber};
    return assert;
}

TEST(TestSuite, conversionWorks) {
    assertThat(1).isConvertedTo("I");
    assertThat(2).isConvertedTo("II");
    assertThat(3).isConvertedTo("III");
    assertThat(10).isConvertedTo("X");
    assertThat(20).isConvertedTo("XX");
    assertThat(30).isConvertedTo("XXX");
    assertThat(33).isConvertedTo("XXXIII");
}
