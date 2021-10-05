#ifndef complex
#define complex

#include <iostream>
#include <cmath>


struct ComplexNumber
{
    double re;
    double im;

    ComplexNumber (double re, double im);
    ComplexNumber (const ComplexNumber &other);
    ComplexNumber ();
    ~ComplexNumber ();

    double abs () const;
    double Re () const;
    double Im () const;
    double arg () const;
    ComplexNumber complex_pow (const double power) const;    

    ComplexNumber& operator = (const ComplexNumber& other);
    ComplexNumber operator + (const ComplexNumber& other) const;
    ComplexNumber operator - (const ComplexNumber& other) const;
    ComplexNumber operator * (const ComplexNumber& other) const;
    ComplexNumber operator / (const ComplexNumber& other) const;

    ComplexNumber operator + (const double other) const;
    ComplexNumber operator - (const double other) const;
    ComplexNumber operator * (const double other) const;
    ComplexNumber operator / (const double other) const;
    
    ComplexNumber& operator += (const ComplexNumber& other);
    ComplexNumber& operator -= (const ComplexNumber& other);
    ComplexNumber& operator *= (const ComplexNumber& other);
    ComplexNumber& operator /= (const ComplexNumber& other);
    ComplexNumber& operator += (const double other);
    ComplexNumber& operator -= (const double other);
    ComplexNumber& operator *= (const double other);
    ComplexNumber& operator /= (const double other);

    ComplexNumber operator + () const;
    ComplexNumber operator - () const;

    bool operator<  (const ComplexNumber&) = delete;
    bool operator>  (const ComplexNumber&) = delete;
    bool operator<= (const ComplexNumber&) = delete;
    bool operator>= (const ComplexNumber&) = delete;

    bool operator<  (double) = delete;
    bool operator>  (double) = delete;
    bool operator<= (double) = delete;
    bool operator>= (double) = delete;
};

std::istream &operator >> (std::istream& is, ComplexNumber& number);
std::ostream &operator << (std::ostream& os, const ComplexNumber& number);

ComplexNumber operator + (double value, const ComplexNumber& other);
ComplexNumber operator - (double value, const ComplexNumber& other);
ComplexNumber operator * (double value, const ComplexNumber& other);
ComplexNumber operator / (double value, const ComplexNumber& other);

#endif //complex