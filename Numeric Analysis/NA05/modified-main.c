#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int dim; //dimention

void show_array(double x[dim][dim + 1]);

void init(double x[dim][dim + 1])
{

    int i, j;
    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim + 1; j++) {
            printf("x[%d][%d]:", i, j);
            scanf("%lf", &x[i][j]);
        }
    }
    puts("");
    show_array(x);
}
void show_array(double x[dim][dim + 1])
{
    int i, j;
    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim + 1; j++) {
            printf("  %10.2f",x[i][j]);
        }
        printf("\n");
    }
}

void CopyArray(double to[dim][dim + 1], double from[dim][dim + 1])
{
    int i, j;

    for (i = 0; i < dim; i++) {
        for (j = 0; j <=dim; j++) {
            to[i][j] = from[i][j];
        }
    }
}

void CheckArray(double after[dim][dim + 1], double before[dim][dim + 1])
{
    int i, j;
    double s;

    printf("=== Residue Check ===\n");
    for(i = 0; i < dim; i++) {
        s = 0.0;
        for (j = 0; j < dim; j++) {
            s += -after[j][dim] * before[i][j];
        }
        s += before[i][dim];
        printf("%+e\n", s);
    }
}

void solvearray(double x[dim][dim+1])
{
    int i, j, k;
    double d;

    for(i = 0; i < dim; i++){
        if (x[i][i] == 0.0) {
            //exchange row
            for (j = i; j < dim; j++) {
                if (x[j][i] != 0.0) {
                    printf("--- exchanging row_%d and row?%d\n", i, j);
                    for(k = i; k<= dim; k++) {
                        d = x[i][k];
                        x[i][k] = x[j][k];
                        x[j][k] = d;
                    }
                    break;
                }
            }
            if ( j == dim) {
                //no non-zero pivot is available
                printf("There is no non-zero pivot. Aborting...\n");
                exit(-1);
            }
        }
        d = x[i][i];
        for(k = i; k <=dim; k++){
            x[i][k] /= d;
            for (j = i + 1; j < dim; j++){
                d = x[j][i];
                for(k = i; k <= dim; k++) {
                    x[j][k] -= x[i][k]*d;
                }
            }
        }
    }
    for(i = dim - 1; i >= 0; i--) {
        for(j = i - 1; j >= 0; j--) {
            x[j][dim] -= x[i][dim]*x[j][i];
        }
    }
}

int main(void)
{
    printf("What's dimention:");
    scanf("%d",&dim);

    printf("dim = %d\n", dim);
    char check = 'n';
    double x[dim][dim + 1], xcp[dim][dim + 1];

    do{
        init(x);

        fflush(stdin); // scanfのバッファをフラッシュ

        printf("Are you OK? (y/n):");
        scanf("%c", &check);
    }while(check !='y');

    CopyArray(xcp, x);

    solvearray(x);

    show_array(x);
    CheckArray(x, xcp);

    return 0;
}
