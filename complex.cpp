#include "complex.h"

const double ACCURACY = 0.00001;

ComplexNumber::ComplexNumber (double number_re, double number_im): re (number_re), im (number_im) {} 

ComplexNumber::ComplexNumber (const ComplexNumber &other): re (other.re), im (other.im) {}

ComplexNumber::ComplexNumber (): re (0), im (0) {}

ComplexNumber::~ComplexNumber ()
{
    re = 0;
    im = 0;
};

double ComplexNumber::abs () const
{
    return sqrt(this->re * this->re + this->im * this->im);
}

double ComplexNumber::Re () const
{
    return re;
}

double ComplexNumber::Im () const
{
    return im;
}

double ComplexNumber::arg () const
{
    double abs = this->abs();
    if (abs == 0)
        return abs;
    double sinArg = asin (im/abs);
    double cosArg = acos (re/abs);
    double arg = 0;
    if (sinArg >= 0)
        arg = cosArg;
    else
        arg = -cosArg;
    return arg;
}

ComplexNumber ComplexNumber::complex_pow (const double power) const
{
    double arg = this->arg ();
    double abs = this->abs ();
    abs = pow (abs, power);
    arg *= power;
 
    return {abs * cos (arg), abs * sin (arg)};
}

ComplexNumber& ComplexNumber::operator = (const ComplexNumber &other) 
{
    re = other.re;
    im = other.im;
    return *this;
}

ComplexNumber ComplexNumber::operator + (const ComplexNumber &other) const
{
    ComplexNumber temp;
    temp.re = re + other.re;
    temp.im = im + other.im;
    return temp;
}

ComplexNumber ComplexNumber::operator - (const ComplexNumber &other) const
{
    ComplexNumber temp;
    temp.re = re - other.re;
    temp.im = im - other.im;
    return temp;
}

ComplexNumber ComplexNumber::operator * (const ComplexNumber &other) const
{
    ComplexNumber temp;
    temp.re = re * other.re - im * other.im;
    temp.im = im * other.re + re * other.im;
    return temp;
}

ComplexNumber ComplexNumber::operator / (const ComplexNumber &other) const
{
    ComplexNumber temp (0, 0);
    if (sqrt(other.re * other.re + other.im * other.im) < ACCURACY)
        return temp;
    else
    {
        temp.re = (re * other.re + im * other.im) / ((other.re * other.re) + (other.im * other.im));
        temp.im = (im * other.re - re * other.im) / ((other.re * other.re) + (other.im * other.im)); 
    }
    return temp;
}

ComplexNumber ComplexNumber::operator + (double other) const
{
    return {re + other, im};
}

ComplexNumber ComplexNumber::operator - (double other) const
{
    return {re - other, im};
}

ComplexNumber ComplexNumber::operator * (double other) const
{
    return {re * other, im * other};
}

ComplexNumber ComplexNumber::operator / (double other) const
{
    if (other == 0)
        return {0 , 0};
    return {re / other, im / other};
}

ComplexNumber operator + (double value, const ComplexNumber& other) 
{
    return {value + other.re, other.im};
}
ComplexNumber operator - (double value, const ComplexNumber& other) 
{
    return {value - other.re, - other.im};
}
ComplexNumber operator * (double value, const ComplexNumber& other) 
{
    return {value * other.re, value * other.im};
}

ComplexNumber operator / (double value, const ComplexNumber& other) 
{
    double sqrAbs = other.re * other.re + other.im * other.im;
    return {(value * other.re) / sqrAbs, (-other.im * value) / sqrAbs};
}

ComplexNumber& ComplexNumber::operator += (const ComplexNumber& other)
{
    re = re + other.re;
    im = im  + other.im;
    return *this;
}

ComplexNumber& ComplexNumber::operator -= (const ComplexNumber& other)
{
    re = re - other.re;
    im = im  - other.im;
    return *this;
}

ComplexNumber& ComplexNumber::operator *= (const ComplexNumber& other)
{
    double tempreal = re;
    re = re * other.re - im * other.im;
    im = im * other.re + tempreal * other.im;
    return *this;
}

ComplexNumber& ComplexNumber::operator /= (const ComplexNumber& other)
{
    double tempreal = re;
    re = (re * other.re + im * other.im) / (other.re * other.re + other.im * other.im);
    im = (im * other.re - other.im * tempreal) / (other.re * other.re + other.im * other.im);
    return *this;
}

ComplexNumber& ComplexNumber::operator += (double other) 
{
    re += other;
    return *this;
}

ComplexNumber& ComplexNumber::operator -= (double other) 
{
    re -= other;
    return *this;
}

ComplexNumber& ComplexNumber::operator *= (double other) 
{
    re *= other;
    im *= other;
    return *this;
}

ComplexNumber& ComplexNumber::operator /= (double other) 
{
    re /= other;
    im /= other;
    return *this;
}

ComplexNumber ComplexNumber::operator + () const
{
    return {re, im};
}

ComplexNumber ComplexNumber::operator - () const
{
    return {-re, -im};
}

std::istream &operator >> (std::istream &is, ComplexNumber &number)
{
    is >> number.re >> number.im;    
    return is;
}

std::ostream &operator << (std::ostream &os, const ComplexNumber &number)
{
    os << "( " << number.re << " : " << number.im << " )";    
    return os;
}



