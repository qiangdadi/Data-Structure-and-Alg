#include "complex.h"

void test(){
    complex c1(1, 2);
    complex c2(1, 0);

    if(c1 != c2){
        std::cout << "complex class test1 success! \n";
    }else{
        std::cout << "complex class test1 fail! \n";
    }

    complex c3(0, 2);
    c2 += c3;
    if(c1 == c2){
        std::cout << "complex class test2 success! \n";
    }else{
        std::cout << "complex class test2 fail! \n";
    }
}

int main(){
    
    test();

    return 0;
}