#include <numeric>
#include <iostream>
#include <climits>

namespace ariel{
    class Fraction{
    private:
        int _numerator, _denominator;
        static const int per=1000;
    public:
        Fraction(int , int );// classic constructor
        Fraction(float);// float constructor
        Fraction();// empty constructor
        void reduce();// reduce the fraction
        static float convertToFloat(const Fraction& frac);// convert fraction into a float
        int getNumerator() const;
        int getDenominator() const;
        friend Fraction operator+(const Fraction &,const Fraction &);
        friend Fraction operator-(const Fraction &,const Fraction &);
        friend Fraction operator*(const Fraction &,const Fraction &);
        friend Fraction operator/(const Fraction &,const Fraction &);
        friend bool operator==(const Fraction &,const Fraction &);
        friend bool operator!=(const Fraction &,const Fraction &);
        friend bool operator<(const Fraction &,const Fraction &);
        friend bool operator>(const Fraction &,const Fraction &);
        friend bool operator<=(const Fraction &,const Fraction &);
        friend bool operator>=(const Fraction &,const Fraction &);

        Fraction& operator++();// prefix increment
        const Fraction operator++(int) ; // postfix increment
        Fraction& operator--(); // prefix subtract
        const Fraction operator--(int) ; // postfix subtract

        friend std::ostream& operator<< (std::ostream&, const Fraction&);
        friend std::istream& operator>> (std::istream&, Fraction&);

    };
    int gcd(int, int);
}