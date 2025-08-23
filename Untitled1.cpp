#include <stdio.h>
#include <math.h>

double solve_equations (double a, double b, double c, double *x1, double *x2);


const int INF = -1;
int main ()
{
  printf ( " This program can solve quadratic equations \n");
  printf ( " Enter three coeff \n");
double a = 0, b = 0, c = 0;
double x1 = 0, x2 = 0;
scanf("%lg %lg %lg", &a, &b, &c);
solve_equations( a, b, c, &x1, &x2 );
printf ("x1 = %lg, x2 = %lg \n", &x1, &x2);
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

double solve_equations (double a, double b, double c, double *x1, double *x2)
{
  double d = b*b - 4*a*c;
  double sqrt_d = sqrt(d);
  if ( a == 0) {
      if ( b == 0)  {
          return (c == 0) ? INF : 0;
        }
      else
      {
        *x1 = - c / b;
        return 1;
       }
}
   if (d > 0) {
       *x1 = ( - b + sqrt_d ) / (2*a);
       *x2 = ( - b - sqrt_d ) / (2*a);
       return 2;
}
  if (d == 0) {
       *x1 = *x2 = - b / (2 * a);
       return 1;
     }
 if (d < 0) {
     printf ( "This equations haven't any solves");
     return 0;
 }
}
