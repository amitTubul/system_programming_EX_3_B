#include "Fraction.hpp"

using namespace std;
namespace ariel {
    Fraction::Fraction(int numerator, int denominator) : _numerator(numerator), _denominator(denominator) {
        if (_denominator==0){
            throw invalid_argument("denominator cannot be zero");
        }
        reduce();
    }

    Fraction::Fraction(float num) : _numerator(static_cast<int>((float) num * per)), _denominator(per) {
        reduce();
    }


    Fraction::Fraction():_numerator(0),_denominator(1){}

    int gcd(int num, int denom) {
       while(denom!=0){
           int temp=denom;
           denom = num % denom;
           num=temp;
       }
        return num;
    }

    void Fraction::reduce() {
       int gcd = ariel::gcd(_numerator,_denominator);
        _numerator/=gcd;
        _denominator/=gcd;
        if(_denominator<0&&_numerator>0){
            _denominator*=-1;
            _numerator*=-1;
        }
    }

    float Fraction::convertToFloat(const Fraction& frac) {
        return ((float)frac._numerator / (float)frac._denominator);
    }
    int Fraction::getNumerator() const {
        return this->_numerator;
    }
    int Fraction::getDenominator() const {
        return this->_denominator;
    }
    Fraction operator+(const Fraction& fraction1,const Fraction& fraction2){
        double checkF1=(double)fraction1._numerator / (double)fraction1._denominator;
        double checkF2=(double)fraction2._numerator / (double)fraction2._denominator;
        if (checkF1+checkF2>INT_MAX||checkF1+checkF2<INT_MIN) throw overflow_error("");
        if (checkF1+checkF2>INT_MAX||checkF1+checkF2<INT_MIN) throw overflow_error("");
        return {fraction1._numerator*fraction2._denominator+fraction1._denominator*fraction2._numerator,
                fraction1._denominator*fraction2._denominator} ;
    }
    Fraction operator-(const Fraction& fraction1,const Fraction& fraction2){
        return {fraction1+(fraction2*(-1))} ;
    }
    Fraction operator*(const Fraction& fraction1,const Fraction& fraction2){
        double checkNum=(double)fraction1._numerator * (double)fraction2._numerator;
        double checkDen=(double)fraction1._denominator * (double)fraction2._denominator;
        if (checkNum>INT_MAX||checkNum<INT_MIN) throw overflow_error("");
        if (checkDen>INT_MAX||checkDen<INT_MIN) throw overflow_error("");
        return {fraction1._numerator * fraction2._numerator,
                fraction1._denominator * fraction2._denominator} ;
    }
    Fraction operator/(const Fraction& fraction1,const Fraction& fraction2){
        double checkNum=(double)fraction1._numerator * (double)fraction2._denominator;
        double checkDen=(double)fraction1._denominator * (double)fraction2._numerator;
        if (checkNum>INT_MAX||checkNum<INT_MIN) throw overflow_error("");
        if (checkDen>INT_MAX||checkDen<INT_MIN) throw overflow_error("");
        if (Fraction::convertToFloat(fraction2)==0.0) throw runtime_error("");
        Fraction tempFraction(fraction2._denominator,fraction2._numerator);
        return {fraction1*tempFraction};
    }
    bool operator==(const Fraction& fraction1,const Fraction& fraction2){
        if(Fraction::convertToFloat(fraction1)==(Fraction::convertToFloat(fraction2))) return true;
        return false;
    }
    bool operator!=(const Fraction& fraction1,const Fraction& fraction2){
        return !(fraction1==fraction2);
    }
    bool operator<(const Fraction& fraction1,const Fraction& fraction2){
        float frac1=Fraction::convertToFloat(fraction1);
        float frac2=Fraction::convertToFloat(fraction2);
        return frac1<frac2;
    }
    bool operator>(const Fraction& fraction1,const Fraction& fraction2){
        float frac1=Fraction::convertToFloat(fraction1);
        float frac2=Fraction::convertToFloat(fraction2);
        return frac1>frac2;
    }
    bool operator<=(const Fraction& fraction1,const Fraction& fraction2){
        return (fraction1==fraction2)||(fraction1<fraction2);
    }
    bool operator>=(const Fraction& fraction1,const Fraction& fraction2){
        return (fraction1==fraction2)||(fraction1>fraction2);
    }
    std::ostream& operator<< (std::ostream& output, const Fraction& fraction){
        return output << fraction._numerator << "/" << fraction._denominator ;
    }
    std::istream& operator>> (std::istream& input , Fraction& fraction){
       int num, den;
       input >> num >> den;
       if(den == 0){
           throw runtime_error("");
       }
       if(input.fail()){
           throw runtime_error("");
       }
       if(den<0){
           num*=-1;
           den*= -1;
       }
       fraction._numerator=num;
       fraction._denominator=den;
       fraction.reduce();
        return input;
    }

    Fraction& Fraction::operator++() {
        this->_numerator+=this->_denominator;
        return *this;
    }
    const Fraction Fraction::operator++(int) {
        Fraction copy=*this;
        _numerator+=_denominator;
        return copy;
    }
    Fraction& Fraction::operator--() {
        this->_numerator-=this->_denominator;
        return *this;
    }

    const Fraction Fraction::operator--(int) {
        Fraction copy=*this;
        _numerator-=_denominator;
        return copy;
    }




}