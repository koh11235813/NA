#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define DIM 2

void clean_stdin(void)
{
    double c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void show_array(double x[DIM][DIM + 1]);

void init(double x[DIM][DIM + 1])
{

    int i, j;
    for (i = 0; i < DIM; i++) {
        for (j = 0; j < DIM + 1; j++) {
            printf("x[%d][%d]:", i, j);
            scanf("%lf", &x[i][j]);
        }
    }
    puts("");
    show_array(x);
}
void show_array(double x[DIM][DIM + 1])
{
    int i, j;
    for (i = 0; i < DIM; i++) {
        for (j = 0; j < DIM + 1; j++) {
            printf("  %10.2f",x[i][j]);
        }
        printf("\n");
    }
}

void CopyArray(double to[DIM][DIM + 1], double from[DIM][DIM + 1])
{
    int i, j;

    for (i = 0; i < DIM; i++) {
        for (j = 0; j <=DIM; j++) {
            to[i][j] = from[i][j];
        }
    }
}

void CheckArray(double after[DIM][DIM + 1], double before[DIM][DIM + 1])
{
    int i, j;
    double s;

    printf("=== Residue Check ===\n");
    for(i = 0; i < DIM; i++) {
        s = 0.0;
        for (j = 0; j < DIM; j++) {
            s += -after[j][DIM] * before[i][j];
        }
        s += before[i][DIM];
        printf("%+e\n", s);
    }
}

void solvearray(double x[DIM][DIM+1])
{
    int i, j, k, l, m;
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
        }
        for (j = i + 1; j < DIM; j++){
            d = x[j][i];
            for(k = i; k <= DIM; k++) {
                x[j][k] -= x[i][k]*d;
            }
        }
    }
    for(i = DIM - 1; i >= 0; i--) {
        for(j = i - 1; j >= 0; j--) {
            x[j][DIM] -= x[i][DIM]*x[j][i];
        }
    }
}

int main(void)
{
    char check = 'n';
    double x[DIM][DIM + 1] = {{2, -1, 1}, {1, 3, 11}};
    double xcp[DIM][DIM + 1];
/*
    do{
        init(x);

        clean_stdin(); // scanfのバッファをフラッシュ

        printf("Are you OK? (y/n):");
        scanf("%c", &check);
        printf("\n");
    }while(check !='y');
*/

    CopyArray(xcp, x);

    solvearray(x);

    show_array(x);
    CheckArray(x, xcp);

    return 0;
}
