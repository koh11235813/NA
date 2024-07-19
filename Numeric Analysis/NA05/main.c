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
        if (x[i][i] == 0.0) {
            //exchange row
            for (j = i; j < DIM; j++) {
                if (x[j][i] != 0.0) {
                    printf("--- exchanging row_%d and row?%d\n", i, j);
                    for(k = i; k<= DIM; k++) {
                        d = x[i][k];
                        x[i][k] = x[j][k];
                        x[j][k] = d;
                    }
                    break;
                }
            }
            if ( j == DIM) {
                //no non-zero pivot is available
                printf("There is no non-zero pivot. Aborting...\n");
                exit(-1);
            }
        }
        d = x[i][i];
        for(k = i; k <=DIM; k++){
            x[i][k] /= d;
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
}

int main(void)
{

    return 0;
}
