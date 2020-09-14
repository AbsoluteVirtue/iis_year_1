#include <stdio.h>
#include <math.h>
#include <string.h>

float function_set(float x, float a, float b, float c) {
    
    float result = 0.0;

    if ((x + a) < 0.0 && c == 0.0) {
        result = (1.0/(a * x)) - b;
    } else if ((x + a) > 0.0 && c != 0.0) {
        result = (x - a)/sin(x);
    } else {
        result = (x * 10.0)/(c - 6.0);
    };

    return result;

}


void print(const char * str) {

    _Bool a = '\0';

    for (int idx=0; str[idx]; idx += 1) {

        printf("%c", str[idx]);

    }

}


int main(int argc, char *argv[]) {


    print("hello");


    char line[256];
    int i, ii;
    if (fgets(line, sizeof(line), stdin)) {
        if (2 != sscanf(line, "%d %d", &i, &ii)) {
            printf("error!");
            return 0;
        }
    }

    int value = 0;

    while (value >= 0) {
        printf("Enter a number: ");
        if (scanf("%d",&value) != 1) {
            printf("error: invalid input\n");
            return 1;
        }
        printf("The number you entered is %d\n", value);
    }

    if (argc < 6) {
        fputs("invalid argument count\n", stderr);
        return 1;
    }

    float k = (float)atof(argv[1]);
    float h = (float)atof(argv[2]);

    if (h <= k) {
        fputs("Xh less than Xk\n", stderr);
        return 1;
    }

    float step;

    printf("Enter step size: ");

    if (scanf("%f", &step) != 1) {
        fputs("error: invalid input\n", stderr);
        return 1;
    }

    for (k; k <= h; k += step) {
        float var = function_set(k, (float)atof(argv[3]), (float)atof(argv[4]), (float)atof(argv[5]));
    
        printf("%.2f\n", var);
    }

    return 0;
}
