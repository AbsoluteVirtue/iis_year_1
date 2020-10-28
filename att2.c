#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 80
#define ROWS 4


int has_str(char * src_str, char * cmp_str) {

    char * items [ROWS] = {};

    char * tmp_str = (char *)malloc(strlen(src_str) + 1);
    strcpy(tmp_str, src_str);

    char * token = strtok(tmp_str, ",");
    int i = 0;
    while (token != NULL) {

        items[i++] = token;
        token = strtok(NULL, ",");

    }

    free(tmp_str);

    char * fmt_str;
    sprintf(fmt_str, "%s,%s", items[0], items[1]);

    if (!strcmp(fmt_str, cmp_str)) {
        return 1;
    }

    return 0;
}


int main(int argc, char const *argv[]) {

    FILE * input = fopen("test.csv", "r");
    if (input == NULL) {
        return 1;
    }

    char line [MAX_LINE] = {};

    while(fgets(line, MAX_LINE, input)) {
        printf("%s", line);
    }

    fclose(input);
}
