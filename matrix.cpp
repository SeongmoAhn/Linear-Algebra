#include <iostream>

#include "matrix.h"

using namespace std;

int main() {
    Matrix m1(3, 4);
    Matrix m2(3, 3);

    if (m1 == m2) printf("m1과 m2는 같은 행렬\n");
    else printf("m1과 m2는 다른 행렬\n");

    return 0;
}
