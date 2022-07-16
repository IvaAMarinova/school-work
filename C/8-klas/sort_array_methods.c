#include <stdio.h>
#include <stdlib.h>

int main()
{
    int option;

    printf("------------------------------------------\n");
    printf("Type 1 for the bubble sort method!\n");
    printf("Type 2 for the insertion sort method!\n");
    printf("Type 3 for the selection sort method!\n");
    printf("Type 4 to exit!\n");
    printf("------------------------------------------\n");
    printf("I want option: ");
    scanf("%d", &option);

    if(option == 4)
        printf("okay, bye!");
        else
            printf("\nhere we go..... \n");

    switch(option){
    case(1):{

        int array[100];
        int a, b, i;
        int count;

        printf("how many numbers?\n");
        scanf("%d", &count);
        printf("enter %d numbers: (Click 'Enter' after every number)\n", count);
        for (a = 0; a < count; a++){
            scanf("%d", &array[a]);
        }
        for(a = 1; a < count; a++){
            for(b = count - 1; b >= a; b--){
                if(array[b - 1] > array[b]){
                    i = array[b - 1];
                    array[b - 1] = array[b];
                    array[b] = i;
                }
            }
        }
        printf("order of sorted numbers: ");
        for(i = 0; i < count; i++)
        printf("%d ", array[i]);

    break;
    }

    case(2):
        {
        int i, j, count, num, array[100];

       printf("how many numbers?\n");
       scanf("%d", &count);

       printf("enter %d numbers: (Click 'Enter' after every number)\n", count);
       for(i = 0; i < count; i++)
          scanf("%d", &array[i]);

       for(i = 1; i < count; i++){
          num = array[i];
          j = i - 1;
          while((num < array[j]) && (j>=0)){
             array[j + 1] = array[j];
             j = j - 1;
          }
          array[j + 1] = num;
       }

       printf("order of sorted numbers: ");
       for(i = 0;i < count; i++)
          printf("%d ", array[i]);

    break;
    }
    case(3):
        {
        int array[100], count, i, d, position, t;

          printf("how many numbers?\n");
          scanf("%d", &count);

          printf("enter %d numbers: (Click 'Enter' after every number)\n", count);

          for (i = 0; i < count; i++)
            scanf("%d", &array[i]);

          for (i = 0; i < (count - 1); i++)
          {
            position = i;

            for (d = i + 1; d < count; d++)
            {
              if (array[position] > array[d])
                position = d;
            }
            if (position != i)
            {
              t = array[i];
              array[i] = array[position];
              array[position] = t;
            }
          }

        printf("order of sorted numbers: ");
        for(i = 0;i < count ; i++)
            printf("%d ", array[i]);

        }

    case(4):
           break;
    }
    return 0;
}
