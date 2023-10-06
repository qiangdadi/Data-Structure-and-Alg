#pragma once
#include <iostream>

struct base1 {
    int base1_var;

    virtual void base1_func() { }            
    virtual void print() { std::cout << "This is base1\n";}
};

struct base2 {
    int base2_var;
    
    virtual void base2_func() { }
    virtual void print() { std::cout << "This is base2\n"; }
};

struct derived : base1, base2 {
    int derived_var;

    void print() { std::cout << "This is derived\n";}
};