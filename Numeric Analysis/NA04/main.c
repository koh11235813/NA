#include <stdio.h>

#define DIM 4

void init(double x[DIM][DIM])
{
    int i, j;

    for (i = 0; i < DIM; i++) {
        for (j = 0; j < DIM; j++)
        {
            x[i][j] = i + j*0.1 + 1.1; // (1)
        }
    }
}

void dump(double x[DIM][DIM])
{
    int i, j;

    for (i = 0; i < DIM; i++) {
        for (j = 0; j < DIM; j++)
        {
            printf("%8.1f ",x[i][j]);
        }
        printf("\n");
    }
    puts("end\n");
}

void func1(double x[DIM][DIM])
{
    int i, j;
    double t;

    for (i = 0; 2*i < DIM; i++) {
        for ( j = 0; j < DIM; j++) {
            t = x[i][j];
            x[i][j] = x[DIM - i - 1][j];
            x[DIM - i - 1][j] = t;
        }
    }
}

void func2(double x[DIM][DIM])
{
    int i, j;
    double t;

    for (j = 0; 2*j < DIM; j++) {
        for (i = 0; i < DIM; i++) {
            t = x[i][j];
            x[i][j] = x[i][DIM - j - 1];
            x[i][DIM - j - 1] = t;
        }
    }
}

void func3(double x[DIM][DIM])
{
    int i, j;
    double t;

    for (i = 0; i < DIM; i++) {
        for (j = i + 1; j < DIM; j++) {
            t = x[i][j];
            x[i][j] = x[j][i];
            x[j][i] = t;
        }
    }
}

int main(void)
{
    double a[DIM][DIM];

    init(a);
    dump(a);
    func1(a);
    puts("(2)");
    dump(a);        //(2)
    func2(a);
    puts("(3)");
    dump(a);        //(3)

    init(a);
    func3(a);
    puts("(4)");
    dump(a);        //(4)

    return 0;
}