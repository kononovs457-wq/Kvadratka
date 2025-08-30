#include <TXLib.h>

const int SS_INF_ROOTS = -1;
const double ep = 1e-9;

typedef struct {
     double a, b, c;
     double x1, x2;
     int nRoots;
} DataTest;


int Solve_Kvadrat (double a, double b, double c,
                        double* x1, double* x2);
int All_Test ();
int All_Solve();
int Solve_linel (double b, double c, double *x1);
int compare_zero (double x);
int Solve_Square (double a, double b, double c,
                        double* x1, double* x2);
int input (double *a, double *b, double *c);
int output (int nRoots, double x1, double x2);
int Test_Solve(DataTest test);
int Choice();


int main(int argc, char *argv[])
{
    for ( int i = 0; i < argc; i++)
    {
        printf (" %s\n", argv[i]);
    }
    Choice();
    return 0;
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
    if (!(test.nRoots == 2 &&
         (compare_zero(test.x1 - test.x1)) &&
         (compare_zero(test.x2 - test.x2))))
        {
            printf ( "FAILED: Test_Solve( test.a, test.b, test.c, \
                      &(test.x1), &(test.x2) is test.nRoots, \
                      x1 = %lf, x2 = %lf ( should be x1 = %lf, x2 = %lf\n",
                      test.x1, test.x2, test.x1, test.x2);
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
            printf ("Введите новые коэффициеты : ");
            while (getchar() != '\n')
                ;
        }
    printf ("Введённые коэффициенты : a = %lg, b = %lg, c = %lg \n", *a, *b, *c);
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


int All_Test ()
{
    FILE *f = fopen("tests.txt", "r");
    if (f == NULL)
    {
        perror("Ошибка открытия файла");
    }
    DataTest tests [] = {};

    int size = sizeof(tests) / sizeof(tests[0]);
    int i = 0;
    while ((i < size) && ((fscanf(f, " %lg %lg %lg %lg %lg %d",
                           &(tests[i].a),
                           &(tests[i].b),
                           &(tests[i].c),
                           &(tests[i].x1),
                           &(tests[i].x2),
                           &(tests[i].nRoots))) == 6))
    {
        i++;
    }
    for ( int j = 0; j < size; j++)
    {
        Test_Solve(tests[j]);
    }
    printf ("Все тесты пройдены успешно!");
    return 1;
}

int Solve_Square (double a, double b, double c,
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

int All_Solve()
{
    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;
    input( &a, &b, &c);
    int nRoots = Solve_Square ( a, b, c, &x1, &x2);
    output(nRoots, x1, x2);
    return 1;
}

int Choice()
{
    int ch = 0;
    printf ("Эта программа может решать квадратные уравнения.\
             \nРешать уравнение с вашими коэффициентами или проверить программу?\
             \nИли введите 3 для выхода из программы (1/2/3)\n");
    do
    {
        scanf (" %d", &ch);
        switch (ch)
            {
                case 1: All_Solve();
                        break;

                case 2: All_Test();

                case 3: break;

                default: printf ("ERROR CHOISE PLEASE NEW DGIGIT\n");
                while (getchar() != '\n');
            }
    } while ( ch != 3);
    while (getchar() != '\n');
    return 1;
}
