#include <omp.h>
#include <iostream>
using namespace std;
int main() {
    omp_set_num_threads(2);
#pragma omp parallel for schedule(static)
    for (int i = 0; i < 8; i++) cout << omp_get_thread_num() << endl;
}