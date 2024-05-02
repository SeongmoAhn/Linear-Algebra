#include <iostream>
#include <vector>

#include "matrix.h"

using namespace std;

int main() {
    Matrix m1(3, 3);
    Matrix m2(3, 2);

    // m1 행렬 추가
    m1.print();

    // m2 행렬 추가
    m2.print();

    return 0;
}
