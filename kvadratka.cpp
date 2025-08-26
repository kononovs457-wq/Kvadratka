#include <TXLib.h>

const int SS_INF_ROOTS = -1;
const double ep = 1e-9;

typedef struct DataTest
{
     double a, b, c;
     double x1, x2;
     int nRoots;
};


int Solve_Kvadrat (double a, double b, double c,
                        double* x1, double* x2);
int AllTest ();
int Test();
int Solve_linel (double b, double c, double *x1);
int compare_zero (double x);
int SolveSquare (double a, double b, double c,
                        double* x1, double* x2);
int Test();
int input (double *a, double *b, double *c);
int output (int nRoots, double x1, double x2);
int Test_Solve(DataTest test);

int main()
{
    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;
    input( &a, &b, &c);
    int nRoots = SolveSquare ( a, b, c, &x1, &x2);
    output(nRoots, x1, x2);
    Test();
}

int Solve_Kvadrat (double a, double b, double c,
                        double* x1, double* x2)
    {
    double d = b*b - 4*a*c;
    if (compare_zero(d))
    {
        *x1 = *x2 = - b / (2*a);
        return 1;
    }
    else
    {
        double sqrt_d = sqrt (d);
        *x1 = (-b - sqrt_d) / (2*a);
        *x2 = (-b + sqrt_d) / (2*a);
        return 2;
    }
}

int Test_Solve(DataTest test)
{
    int nRoots = SolveSquare (test.a, test.b, test.c, &(test.x1), &(test.x2));
    if (!( test.nRoots == 2 && ( compare_zero(test.x1 - test.x1)) && ( compare_zero(test.x2 - test.x2))))
        {
            printf ( "FAILED: Test_Solve( test.a, test.b, test.c, &(test.x1), &(test.x2) is test.nRoots, x1 = %lf, x2 = %lf ( should be x1 = %lf, x2 = %lf\n", test.x1, test.x2, test.x1, test.x2);
            return 0;
        }
    else
        {
            return 1;
        }
    return 0;
}

int output (int nRoots, double x1, double x2)
{
    switch (nRoots)
        {
            case 0: printf ("No roots\n");
                break;

            case 1: printf ("x = %lg\n", x1);
                break;

            case 2: printf ("x1 = %lg, x2 = %lg\n", x1, x2);
                break;

            case SS_INF_ROOTS: printf ("Any number");
                break;

            default: printf ("main(): ERROR: nRoots = %d\n",
                            nRoots);
            }
    return 0;
}

int input (double *a, double *b, double *c)
{
    printf ("# Enter a, b, c: ");
    while (scanf ("%lg %lg %lg", a, b, c) != 3)
        {
            printf ("¬ведите новые коэффициеты : ");
            while (getchar() != '\n');
        }
    printf ("¬ведЄнные коэффициенты : a = %lg, b = %lg, c = %lg \n", *a, *b, *c);
    return 1;
}

int compare_zero (double x)
{
   if (fabs(x) < ep)
        {
            return 1;
        }
    return 0;
}

int Solve_linel ( double b, double c, double *x1)

{
    if (compare_zero(b))
        {
            return (compare_zero(c))? SS_INF_ROOTS : 0;
        }
    else /* if (b != 0) */
        {
            *x1 = - c / b;
            return 1;
        }
}


int AllTest ()
{
    DataTest tests [] = {{.a = 1,       .b = -5,          .c = 6,             .x1 = 2,       .x2 = 3,       .nRoots = 2},
                         {.a = -114.00, .b = -50844.00,   .c = -5669106.00,   .x1 = -223.00, .x2 = -223.00, .nRoots = 2},
                         {.a = 793.00,  .b = 1054690.00,  .c = 350684425.00,  .x1 = -665.00, .x2 = -665.00, .nRoots = 2},
                         {.a = -508.00, .b = -356616.00,  .c = -62586108.00,  .x1 = -351.00, .x2 = -351.00, .nRoots = 2},
                         {.a = -638.00, .b = -1241548.00, .c = -604013102.00, .x1 = -973.00, .x2 = -973.00, .nRoots = 2}};

    int size = sizeof(tests) / sizeof(tests[0]);
    for ( int i = 0; i < size; i++)
            {
                Test_Solve(tests [i]);
            }
    return 1;
}

int SolveSquare (double a, double b, double c,
                        double* x1, double* x2)
{
    if (compare_zero(a))
    {
        Solve_linel(b, c, x1);
    }
    else
    {
        Solve_Kvadrat(a, b, c, x1, x2);
    }
    return 2;
}

int Test()
{
    printf ("’отите ли проверить другие решени€? (Y/N)\n");
    char ch = ' ';
    scanf (" %c", &ch);
    if (ch == 'Y')
    {
        AllTest();
    }
    return 1;
}
