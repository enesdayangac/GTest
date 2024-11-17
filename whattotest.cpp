#include "whattotest.hpp"

double squareRoot(const double a) {
    double b = sqrt(a);
    if(b != b) { // nan check
        return -1.0;
    }else{
        return sqrt(a);
    }
}

double squareRootOfsquareRoot(const double a)
{
    squareRoot(a);
}