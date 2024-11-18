
// https://www.hackerrank.com/contests/w35/challenges/triple-recursion
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void fillMatrix(int matrix[100][100], int n, int m, int k, int i, int j)
{
    if (i >= n || j >= n)
        return;

    if (i == 0 && j == 0)
    {
        matrix[i][j] = m;
    }
    else if (i == j)
    {
        matrix[i][j] = matrix[i - 1][j - 1] + k;
    }
    else if (i > j)
    {
        matrix[i][j] = matrix[i - 1][j] - 1;
    }
    else
    {
        matrix[i][j] = matrix[i][j - 1] - 1;
    }

    if (j + 1 < n)
    {
        fillMatrix(matrix, n, m, k, i, j + 1);
    }
    else
    {
        fillMatrix(matrix, n, m, k, i + 1, 0);
    }
}

void tripleRecursion(int n, int m, int k)
{
     

     int matrix[100][100]; 

    fillMatrix(matrix, n, m, k, 0, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    int m;
    int k;
    scanf("%i %i %i", &n, &m, &k);
    tripleRecursion(n, m, k);
    return 0;
}