#include "complex.h"

void test01(){
    complex c1(1, 2);
    complex c2(1, 0);

    if(c1 != c2){
        std::cout << "complex class test01-1 success! \n";
    }else{
        std::cout << "complex class test01-1 fail! \n";
    }

    complex c3(0, 2);
    c2 += c3;
    if(c1 == c2){
        std::cout << "complex class test01-2 success! \n";
    }else{
        std::cout << "complex class test01-2 fail! \n";
    }
}

// void test02(){
//     //complex* pc = new Complex(1, 2);
//     complex* pc;
//     void* mem = operator new(sizeof(complex));/*call malloc function to allocate a chunk of memory*/
//     pc = static_cast<complex*>(mem);/*type conversion*/
//     pc->complex::complex(1, 2);/*call constructor*/

//     //delete pc;
//     pc->complex::~complex();/*call deconstructor*/
//     operator delete(pc);/*call free to free memory*/
// }

int main(){
    
    test01();

    return 0;
}