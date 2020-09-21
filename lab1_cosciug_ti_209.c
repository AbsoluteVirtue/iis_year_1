#include <stdio.h>
#include <math.h>
float StartX, EndX, StepX, res;  
float function (float a, float b, float c, float x) {
      if (x < 0 && b != 0) 
        res = a-x/(10+b);
     else if (x > 0 && b == 0)
       res = (x-a)/(x-c);
     else 
        res = 3*x + 2/c;
  }  
int main(){
    float a,b,c,x;
      printf("\nEnter: \n");
      printf("\t a = "); scanf("%f", &a);
      printf("\t b = "); scanf("%f", &b);
      printf("\t c = "); scanf("%f", &c);
      printf("\t Xstart = "); scanf("%f", &StartX);
      printf("\t Xend = "); scanf("%f", &EndX);
      printf("\t dX = "); scanf("%f", &StepX);

      if (EndX < StartX)
        printf("EndX is less than StartX");
      
        for (x = StartX; x <= EndX; x += StepX) {
           float result = function(a, b, c, x);
              if (((long)floor(a) | (long)floor(b)) & (long)floor(c) != 0)
                printf("x = %.2f\tF = %.2f\n", x, res);
             else
                printf("x = %.2f\tF = %.0f\n", x, res);
        }
  return 0;
}
