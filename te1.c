#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iso646.h>

#define MAX_LINE 5

int main(int argc, char const *argv[])
{
    FILE *input = fopen("census.csv", "r");
    if (input == NULL)
    {
        return 1;
    }

    char *search_term = (char *)malloc(MAX_LINE); // 1599
    char buffer[MAX_LINE];
    if (fgets(buffer, sizeof(buffer), stdin))
    {
        if (1 != sscanf(buffer, "%s", search_term))
        {
            printf("input error!");
            return -1;
        }
    }

    char *constructed_string = (char *)malloc(MAX_LINE + 2);
    if (constructed_string == NULL)
    {
        printf("memory allocation error!");
        return -1;
    }

    strcpy(constructed_string, "\"");
    strcat(constructed_string, search_term);
    strcat(constructed_string, "\"\0");

    char line[80] = {};
    while (fgets(line, 80, input))
    {
        int cmp = strncmp(constructed_string, line, MAX_LINE + 1);
        if (!cmp)
        {
            printf("%s", line);
            rewind(input);
            break;
        }
    }

    free(search_term);
    free(constructed_string);
    fclose(input);
}
