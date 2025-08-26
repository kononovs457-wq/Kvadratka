#include <TXLib.h>

const int SS_INF_ROOTS = -1;
const double ep = 1e-9;

typedef struct DataTest;
int Solve_linel (double a, double b, double c, double *x1);
int compare_zero (double x);
int SolveSquare (double a, double b, double c,
                        double* x1, double* x2);
int input (double *a, double *b, double *c);
int output (int nRoots, double x1, double x2);
int Test_Solve(double x1, double x2);

int main()
{
    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;
    input( &a, &b, &c);
    //Test_Solve( x1, x2);
    int nRoots = SolveSquare ( a, b, c, &x1, &x2);
    output(nRoots, x1, x2);
}
int SolveSquare (double a, double b, double c,
                        double* x1, double* x2)
    {
    double d = b*b - 4*a*c;
    if ( fabs(d) < ep)
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
int Test_Solve(double x1, double x2)
{
 int nRoots = SolveSquare ( 1, -5, 6, &x1, &x2);
 if (!( nRoots == 2 && ( fabs(x1 - 2) < ep) && ( fabs(x2 - 3) < ep)))
    {
    printf ( "FAILED: Test_Solve( 1, -5, 6, &x1, &x2) is 2, x1 = %lf, x2 = %lf ( should be x1 = 2, x2 = 3\n", x1, x2);
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
   if (fabs(x) > ep)
        {
            return 1;
        }
    return 0;
}

int Solve_linel (double a, double b, double c, double *x1)
    {
        if ( fabs(a) < ep)
            {
                if ( fabs(b) < ep)
                    {
                        return ( fabs(c) < ep)? SS_INF_ROOTS : 0;
                    }
                else /* if (b != 0) */
                    {
                        *x1 = - c / b;
                        return 1;
                    }
            }
}

/*typedef struct DataTest
    {
     double a, b, c;
     double x1, x2;
     int nRoots;
    }
 */
