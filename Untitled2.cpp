#include <TXLib.h>

int SolveSquare (double a, double b, double c,
                        double* x1, double* x2);
const int SS_INF_ROOTS = -1;
int main()
{
    printf ("# Enter a, b, c: ");
    double a = 0, b = 0, c = 0;
    scanf ("%lg %lg %lg", &a, &b, &c);
    double x1 = 0, x2 = 0;
    int nRoots = SolveSquare (a, b, c, &x1, &x2);
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
        return 1;
    }
}
int SolveSquare (double a, double b, double c,
                        double* x1, double* x2)
    {
    if (a == 0)
        {
        if (b == 0)
            {
            return (c == 0)? SS_INF_ROOTS : 0;
            }
        else /* if (b != 0) */
        {
            *x1 = - c / b;
            return 1;
        }
        }
    double d = b*b - 4*a*c;
    if (d == 0)
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
