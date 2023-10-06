#include "base.h"

void test01(){
    base2* pb = new derived();
    pb->print();
    pb->base2_var = 2;

    base1*pb1 = new derived();
    pb1->base1_var = 1;
}

int main(){

    test01();

    return 0;
}