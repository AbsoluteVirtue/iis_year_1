#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


void input() {

    char line[256];
    int i;
    if (fgets(line, sizeof(line), stdin)) {
        if (1 != sscanf(line, "%d", &i)) {
            printf("input error!");
            return;
        }
    }
}


void array_allocation (int size) {

    char * pa = (char *) malloc(size + 1);

    if (pa != NULL) {

        for(int i = 0; i < size; i += 1) {
            char ch;
            if (scanf("%c", &ch) == 1) {
                pa[i] = ch;
            }
        }
        pa[size] = '\0';

        printf("%s", pa);
    }

    free(pa);

}

int main(int argc, char const *argv[])
{
    int a = 88;
    int * pa = &a;
    int * pz = pa + 1;
    // *pz = 88;
    int r = (pz - pa);

}
