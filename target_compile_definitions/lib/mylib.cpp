#include "mylib.h"
#include <iostream>

#ifndef USE_A
void featureXFunction() {
    std::cout << "Not Use Feature X" << std::endl;
}
#endif

#ifdef USE_A
void featureXFunction() {
    std::cout << "Feature X is enabled" << std::endl;
}
#endif