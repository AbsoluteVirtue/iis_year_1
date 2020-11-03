
#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include <stdio.h>
#include <string.h>


int main()
{

    FILE* file;
    char name[] = "census.csv";

    int count=0;
    char codenum[5];
    char tempnum[5];

    bool play=true;
    while(play==true)
    {
        file = fopen(name, "r");

        printf("Vvedite cod regiona\n");

        gets(codenum);

        while(!feof(file))
        {
            count=0;
            fgets(tempnum,6,file);	
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
                printf(tempnum);
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
}
