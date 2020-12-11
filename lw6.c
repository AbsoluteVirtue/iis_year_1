#include <iso646.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned short uint8;

struct book
{
    char *author;
    char *title;
    uint8 yop;
};

void init(struct book * bp);
void fill(struct book * bp, const char * a, const char * t, uint8 y);
void clear(struct book * bp);
int comp(const void * a, const void * b);
void generate_author(char * tmp);
void generate_title(char * tmp);

int main(int argc, char const * argv[])
{
    #define NO_OF_BOOKS 10

    struct book * sob = (struct book *)malloc(NO_OF_BOOKS * sizeof(struct book));

    for (size_t i = 0; i < NO_OF_BOOKS; i++)
    {
        struct book b;
        init(&b);
        char tmp_a[10] = {};
        generate_author(tmp_a);
        char tmp_t[10] = {};
        generate_title(tmp_t);
        fill(&b, tmp_a, tmp_t, 1900 + (rand() % 100));
        printf(
            "%s: \"%s\" (%d)\n",
            b.author,
            b.title,
            b.yop);
        sob[i] = b;
    }

    sob[0].yop = 1965;

    qsort(sob, NO_OF_BOOKS, sizeof(struct book), comp);

    printf("-----------------------------\n");

    for (size_t i = 0; i < NO_OF_BOOKS; i++)
    {
        printf(
            "%s: \"%s\" (%d)\n",
            sob[i].author,
            sob[i].title,
            sob[i].yop);
        clear(&sob[i]);
    }

    free(sob);
}

void init(struct book * bp)
{
    bp->author = NULL;
    bp->title = NULL;
    bp->yop = 0;
}

void fill(struct book * bp, const char * a, const char * t, uint8 y)
{
    bp->yop = y;
    bp->author = strdup(a);
    bp->title = strdup(t);
}

void clear(struct book * bp)
{
    if (bp->author)
    {
        free(bp->author);
    }
    if (bp->title)
    {
        free(bp->title);
    }
    init(bp);
}

int comp(const void * a, const void * b)
{
    return *(((struct book *)a)->author) - *(((struct book *)b)->author);
}

int _get_random_range(int lower, int upper)
{
    return lower + (rand() % (upper - lower));
}

void generate_author(char * tmp)
{
    for (size_t i = 0; i < 9; i++)
    {
        if (i == 0 or i == 6)
        {
            tmp[i] = (char)_get_random_range((int)'A', (int)'Z');
        }
        else if (i == 4)
        {
            tmp[i] = ',';
        }
        else if (i == 5)
        {
            tmp[i] = ' ';
        }
        else
            tmp[i] = (char)_get_random_range((int)'a', (int)'z');
    }
    tmp[9] = '\0';
}

void generate_title(char * tmp)
{
    tmp[0] = (char)_get_random_range(65, 90);
    for (size_t i = 1; i < 9; i++)
    {
        tmp[i] = (char)_get_random_range(97, 122);
    }
    tmp[9] = '\0';
}
