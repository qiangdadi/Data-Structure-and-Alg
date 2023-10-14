#include "randomGeneration.h"

int generateARandom(int m, int n){
    mt19937 mt{ static_cast<mt19937::result_type>(
            steady_clock::now().time_since_epoch().count()
    )};

    uniform_int_distribution die{m, n};

    return die(mt);
}