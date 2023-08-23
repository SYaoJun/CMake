#include <iostream>

#ifdef ENABLE_FEATURE_A
void featureA() {
    std::cout << "Feature A is enabled." << std::endl;
}
#endif

int main() {
#ifdef ENABLE_FEATURE_A
    featureA();
#else
    std::cout << "Feature A is disabled." << std::endl;
#endif

    return 0;
}