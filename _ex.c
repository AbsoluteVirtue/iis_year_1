#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned short uint8;

struct book
{
    char * title;
    char * author;
    uint8 year;
};


void init(struct book * bp)
{
    bp->author = NULL;
    bp->title = NULL;
    bp->year = 0;
}


void fill(  struct book * bp, 
            const char * a, 
            const char * t, 
            uint8 y) 
{
    bp->author = (char *)malloc(strlen(a) + 1);
    if(bp->author) 
    {
        strcpy(bp->author, a);
    }
    bp->title = (char *)malloc(strlen(t) + 1);
    if(bp->title) 
    {
        strcpy(bp->title, t);
    }
    bp->year = y;
}


void clear(struct book * bp) 
{
    bp->year = 0;
    if(bp->author) 
    {
        free(bp->author);
        bp->author = NULL;
    }
    if(bp->title) 
    {
        free(bp->title);
        bp->title = NULL;
    }
}


int comp(const void * a, const void * b) 
{
    return (((struct book *)a)->year) - (((struct book *)b)->year);
}


int main(int argc, char const *argv[])
{
    struct book b1, b2;
    init(&b1);
    init(&b2);

    fill(&b2, "Алексей Толстой", "Князь Серебряный", 1900);
    fill(&b1, "Владимир Маяковский", "Облако в штанах", 1920);

    struct book * sob = (struct book *)malloc(
        2 * sizeof(struct book));

    sob[0] = b1;
    sob[1] = b2;

    for (size_t i = 0; i < 2; i++)
    {
        printf( "%s \"%s\" (%d)\n", 
                sob[i].author, sob[i].title, sob[i].year);
    }

    qsort(sob, 2, sizeof(struct book), comp);

    for (size_t i = 0; i < 2; i++)
    {
        printf( "%s \"%s\" (%d)\n", 
                sob[i].author, sob[i].title, sob[i].year);
        clear(&sob[i]);
    }

    free(sob);
}
