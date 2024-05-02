#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>

class Matrix {
    int **mat;
    int row;
    int col;

public:
    // 생성자
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
    // 생성자(단위행렬, 영행렬)
    // type이 0이면 영행렬, 1이면 단위행렬
    Matrix(int row, int col, int type) : row(row), col(col) {
        mat = (int **)malloc(sizeof(int *) * row);
        for (int i = 0; i < row; i++)
            mat[i] = (int *)malloc(sizeof(int) * col);

        printf("[ %d X %d %s Matrix ]\n", row, col, (type ? "Identity" : "Zero"));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (type) {
                    if (i == j) mat[i][j] = 1;
                    else mat[i][j] = 0;
                }
                else {
                    mat[i][j] = 0;
                }
            }
        }
        printf("\n");
    }
    // 소멸자
    ~Matrix() {
        for (int i = 0; i < row; i++)
            free(mat[i]);
        free(mat);
    }

    int getRow() { return row; }
    int getCol() { return col; }

    void transpose() {
        int **ret = (int **)malloc(sizeof(int *) * col);
        for (int i = 0; i < col; i++)
            ret[i] = (int *)malloc(sizeof(int) * row);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++)
                ret[j][i] = mat[i][j];
        }

        int **tempMat = mat;
        mat = ret;
        ret = tempMat;
        for (int i = 0; i < row; i++)
            free(ret[i]);
        free(ret);

        int temp = row;
        row = col;
        col = temp;
    }

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
