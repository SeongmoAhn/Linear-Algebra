#include <iostream>

#include "matrix.h"

using namespace std;

int main() {
    Matrix m1(3, 3, 0);
    Matrix m2(3, 2, 1);

    m1.print();
    m2.print();

    return 0;
}
