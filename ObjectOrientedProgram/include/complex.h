#pragma once /*guard declaration*/

#include <iostream>

/*
A good defined class:
    Trait 1:parameter pass by reference and even return by reference if allowed.
    Trait 2:construct function uses list initialization.
    Trait 3:for member function which will not change the data member in the class, use const to modify.
*/
class complex
{
public:
    complex (double r = 0, double i = 0)
      : re (r), im (i)
    { }

    int func(const complex& param){return param.re + param.im;}/*the objects created from the same class are friends.*/

    complex& operator += (const complex& r);
    double real () const {return re;}
    double imag () const {return im;}
private:
    double re, im;

    friend complex& __doapl (complex*, const complex&);/*friend has the right to get private data, faste than get value by member function*/
};

complex& __doapl(complex* ths, const complex& r){
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

inline complex& 
complex::operator += (const complex& r){
    return __doapl(this, r);
}

inline double 
imag(const complex& x){
    return x.imag();
}

inline double
real(const complex& x){
    return x.real();
}

/*operator override using non-member function*/
inline complex
operator + (const complex& x, const complex& y){
    return complex(real (x) + real (y),
                   imag (x) + imag (y));/*temp object*/
}

inline complex
operator + (const complex& x){
    return x;
}

inline complex 
operator - (const complex& x){
    return complex(-real(x), -imag(x));
}

inline bool
operator == (const complex& x, const complex& y){
    return real(x) == real (y) && imag(x) == imag(y); /*min the double comparision*/
}

inline bool
operator == (const complex& x, double y){
    return real(x) == y && imag(x) == 0;
}

inline bool
operator == (double x, const complex& y){
    return x == real (y) && imag(y) == 0;
}

inline bool
operator != (const complex& x, const complex& y){
    return real(x) != real (y) || imag(x) != imag(y); /*min the double comparision*/
}

inline bool
operator != (const complex& x, double y){
    return real(x) != y || imag(x) != 0;
}

inline bool
operator != (double x, const complex& y){
    return x != real (y) || imag(y) != 0;
}

std::ostream&
operator << (std::ostream& os, const complex& x){
    return os << '(' << real(x) << ',' << imag(x) << ")\n";
}
