#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, char *agrv[])
{
  FILE *fp, *lg, *mi;
  struct column
  {
    char code1[15];
    char code[100];
    char qty[100];
    char night[100];
    char usually[100];
  };
  struct column date[1000];
  char s, s1, buffer[150], *chk;
  int i = 0, k = 0, l = 1, p = 0, m = 0;
  bool yes_no = true, no_yes, yes_no2, win = true;
  if ((fp = fopen("census.csv", "r+")) == NULL)
  {
    printf("FILE IS NOT OPEN :(");
    getchar();
    return 0;
  }
  fp = fopen("census.csv", "r+");
  lg = fopen("fscanf.txt", "a+");
  while (fscanf(fp, "%c", &s) != EOF)
  {
    if (s == '"' || ((s == ',') && (s1 == '"' || s1 == ' ' || s1 == '0' || s1 == '1' || s1 == '2' || s1 == '3' || s1 == '4' || s1 == '5' || s1 == '6' || s1 == '7' || s1 == '8' || s1 == '9')))
    {
      fprintf(lg, "%c", ' ');
      s1 = s;
    }
    else
    {
      if (s == ',')
      {
        fprintf(lg, "%c", s);
        s1 = s;
      }
    }
    if (s == ' ')
    {
      if (s1 != ',')
      {
        fprintf(lg, "%c", '_');
        s1 = s;
      }
    }
    if (s != '"' && s != ',' && s != ' ')
    {
      fprintf(lg, "%c", s);
      s1 = s;
    }
  }
  fclose(fp);
  fclose(lg);
  lg = fopen("fscanf.txt", "r");
  while (fscanf(lg, "%s%s%s%s", &date[i].code, &date[i].qty, &date[i].night, &date[i].usually) != EOF)
  {
    i++;
  }
  for (int l = 0; l < i; l++)
  {
    for (int m = 0; m < strlen(date[l].qty); m++)
    {
      if (date[l].qty[m] == '_')
      {
        date[l].qty[m] = ' ';
      }
    }
  }
  fclose(lg);
  remove("fscanf.txt");

  while (yes_no)
  {
    if (l == 1)
    {
      printf("What do you want? Pls enter the number of variant\n");
      printf("1. Find information\n2. Exit the program\n");
      while (win)
      {
        do
        {
          printf("Choose number 1 or 2\n|: ");
          fflush(stdout);
          if (fgets(buffer, sizeof buffer, stdin) != NULL)
          {
            m = (int)strtol(buffer, &chk, 10);
          }
        } while (!isspace(*chk) && *chk != 0);

        if (m == 1 || m == 2)
        {
          win = false;
        }
      }
      l = 2;
    }
    else
    {
      printf("1. Enter another value\n2. Exit the program\n");
      win = true;
      m = 0;
      while (win)
      {
        do
        {
          fflush(stdout);
          if (fgets(buffer, sizeof buffer, stdin) != NULL)
          {
            m = (int)strtol(buffer, &chk, 10);
          }
          if (m == 1 || m == 2)
          {
          }
          else
          {
            printf("Choose number 1 or 2\n|:");
          }
        } while (!isspace(*chk) && *chk != 0);
        if (m == 1 || m == 2)
        {
          win = false;
        }
      }
    }
    switch (m)
    {
    case 1:
    {
      yes_no2 = true;
      while (yes_no2)
      {
        printf("You can get information by entering\n 1. Enter the code |XXXX|:\n 2. Enter the |TotalStated|:\n 3. Enter the |Total|:\n|: ");
        scanf("%s", &date->code1);
        if (strcmp(date[i - 2].code, date->code1) == 0)
        {
          yes_no2 = false;
        }
        else
        {
          if (strcmp(date[i - 1].code, date->code1) == 0)
          {
            yes_no2 = false;
          }
          else
          {
            if (strlen(date->code1) != 4)
            {
              printf("Pls enter the correct information\n");
            }
            else
            {
              for (int i = 0; i < 4; i++)
              {
                if (date->code1[i] == '0' || date->code1[i] == '1' || date->code1[i] == '2' || date->code1[i] == '3' || date->code1[i] == '4' || date->code1[i] == '5' || date->code1[i] == '6' || date->code1[i] == '7' || date->code1[i] == '8' || date->code1[i] == '9')
                {
                  yes_no2 = false;
                }
                else
                {
                  yes_no2 = true;
                }
              }
            }
          }
        }
      }
      k = 0;
      p = 0;
      while (k < i)
      {
        if (strcmp(date[k].code, date->code1) == 0)
        {
          p = 1;
          printf("Code : %s\nBirthplace : %s\nCensus_night_population_count:%s\nCensus_usually_resident_population_count : %s\n\n", date[k].code, date[k].qty, date[k].night, date[k].usually);
          break;
        }
        k++;
      }
      if (p == 0)
      {
        printf("Information with such a code does not exist\n\n");
      }
      break;
    }
    case 2:
    {
      printf("Exit successful...");
      return (0);
    }
    }
  }
  return 0;
}
