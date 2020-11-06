
#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main()
{

    FILE* file = fopen("census.csv", "r");

    int count=0;
    char codenum[5];

    bool play=true;
    while(play)
    {
        printf("Vvedite cod regiona\n");

        fgets(codenum, 5, stdin);

        while(!feof(file))
        {
            char tempnum[200] = {};
            count=0;
            fgets(tempnum, 200, file);
            int j=0;

            for(int i=1;i<6;i++)
            {
                if(tempnum[i]==codenum[j])
                {
                    count++;
                    j++;
                    if(j==4)
                    { 
                        fgets(tempnum,100,file);	
                        break;
                    }
                } else {
                    break;
                }
            }

            if(count==4)
            {
                printf("%s", tempnum);
                break;
            }
        }

        if(count!=4)
        {
            printf("Net Takogo znacenia\n");
            printf("Poprobuite eshe raz\n");
        }
        else
        {
            play=false;
        }
    }

    fclose(file);
}
