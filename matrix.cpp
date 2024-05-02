#include <iostream>

#include "matrix.h"

using namespace std;

int main() {
    Matrix m1(3, 4);

    printf("기존 행렬\n");
    m1.print();
    m1.transpose();
    printf("전치 행렬\n");
    m1.print();

    return 0;
}
