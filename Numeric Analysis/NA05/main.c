#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define DIM 3

void solvearray(x)
double x[DIM][DIM+1];
{
    int i, j, k;
    double d;

    for(i = 0; i < DIM; i++){

    }
    d = x[i][i];
    for(k = i; k <=DIM; i++){
        for (j = 0; j < DIM; j++){
            if(i != j)  {
                d = x[j][i];
                for(k = i; k <= DIM; k++) {
                    x[j][k] -= x[i][k]*d;
                }
            }
        }
    }
}
int main(void)
{

    return 0;
}
