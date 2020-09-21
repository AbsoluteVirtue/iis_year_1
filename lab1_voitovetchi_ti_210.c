#include <stdio.h>
#include <math.h>
    double fun(double a, double b, double x, double c) {

        double res;

        if (x<0 && b!=0) {
            if (c*x-a!=0) {
                  res=-(2*x-c)/(c*x-a);
             }
            else  res=0;

        }
        else if (x>0 && b==0) {
            if (x-c!=0) {
                  res=(x-a)/(x-c);
             }
            else res=0;

        }
        else {
            if(c!=0 || x!=0) {
                res=(-x/c)+(-c/2*x);
            }
            else res=0;

        }
        return res;

    }
    int main() {

        double a, b, c, Xfirst, Xlast, dx;

        printf("Enter: a, b, c, Xfirst, Xlast, dx \n");
        scanf("%lf" "%lf" "%lf" "%lf" "%lf" "%lf", &a, &b, &c, &Xfirst, &Xlast, &dx);


        for(double x = Xfirst; x <= Xlast; x += dx) {
                        if (!(((int)floor(a) | (int)floor(b)) & ((int)floor(a) | (int)floor(c))))
                            printf("x = %.2f\tresult: %.0f\n", x, fun(a,b,x,c));
                        else
                            printf("x = %.2f\tresult: %.2f\n", x, fun(a,b,x,c));
        }

        return 0;
    }
