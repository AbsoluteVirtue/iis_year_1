#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef unsigned short uint8;


struct book
{
    char * author;
    char * title;
    uint yop;
};


void init(struct book * bp)
{
    bp->author = NULL;
    bp->title = NULL;
    bp->yop = 0;
}


void fill(struct book * bp, const char * a, const char * t, uint8 y) 
{
    bp->yop = y;
    bp->author = (char *)malloc(strlen(a) + 1);
    if (bp->author)
    {
        strcpy(bp->author, a);
    }
    bp->title = (char *)malloc(strlen(t) + 1);
    if (bp->title)
    {
        strcpy(bp->title, t);
    }
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


int main(int argc, char const *argv[])
{
    struct book b1, b2;
    init(&b1);
    fill(&b1, "John Milton", "Paradise Lost", 2020);
    
    init(&b2);
    fill(&b2, "James Joyce", "Ulysses", 2019);

    struct book * sob = (struct book *)malloc(2 * sizeof(struct book));
    sob[0] = b1;
    sob[1] = b2;

    for (size_t i = 0; i < 2; i++)
    {
        printf("%s, \"%s\" (%d)\n",
            sob[i].author, sob[i].title, sob[i].yop);
    }

    b1.yop = 1965;

    clear(&b1);
    clear(&b2);
}
