#include <stdio.h>
#include <stdlib.h>

int main()
{
       int i, j, num;
       char name[100][100], t_name[100][100], n_name[100];

       printf("How many names do you want to sort in alphabetical order?\n");
       scanf("%d", &num);

       printf("Enter your names one by one (click Enter after every name)\n");

       for(i = 0; i < num; i++)
       {
          scanf("%s",name[i]);
          strcpy (t_name[i], name[i]);
       }

       for(i = 0; i < num - 1; i++)
       {
          for(j = i + 1; j < num; j++)
          {
             if(strcmp(name[i],name[j]) > 0)
             {
                 strcpy(n_name,name[i]);
                 strcpy(name[i],name[j]);
                 strcpy(name[j],n_name);
             }
          }
       }

       printf("Sorted names:\n");

       for(i = 0; i < num; i++){
          printf("%s\n",name[i]);
       }

    return 0;
}
