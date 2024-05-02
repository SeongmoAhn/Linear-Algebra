#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>

class Matrix {
    int **mat;
    int row;
    int col;

public:
    Matrix(int row, int col) : row(row), col(col) {
        mat = (int **)malloc(sizeof(int *) * row);
        for (int i = 0; i < row; i++)
            mat[i] = (int *)malloc(sizeof(int) * col);

        printf("[ %d X %d Matrix ]\n", row, col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++)
                scanf("%d", &mat[i][j]);
        }
        printf("\n");
    }
    ~Matrix() {
        for (int i = 0; i < row; i++)
            free(mat[i]);
        free(mat);
    }

    int getRow() { return row; }
    int getCol() { return col; }

    // 행렬 출력
    void print() {
        printf("= %d X %d Matrix =\n", row, col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (j == 0) {
                    if (i == 0) printf("┌ ");
                    else if (i == row - 1) printf("└ ");
                    else printf("│ ");
                }
                printf("%d ", mat[i][j]);
                if (j == col - 1) {
                    if (i == 0) printf("┐\n");
                    else if (i == row - 1) printf("┘\n");
                    else printf("│\n");
                }
            }
        }
        printf("\n");
    }
};

#endif
