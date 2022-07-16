#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int function(int*, int, int, int);
int main()
{
    int opt;

    printf("------------------------------\n");
    printf("Choose an option! <3\n");
    printf("Do you want to find your number using the:\n");
    printf("... liner searcher method for numbers in order? (from smaller to greater numbers) /type '1'\n");
    printf("... liner searcher method for numbers in order? (from greater to smaller numbers) /type '2'\n");
    printf("... liner searcher method for numbers not in order? /type '3'\n");
    printf("... binary method without recursion? /type '4'\n");
    printf("... binary method with recursion? /type '5'\n");
    printf("... exit? :o /type 6\n");
    printf("------------------------------\n");
    scanf("%d", &opt);

    switch (opt) {
        case (1): {
            int found = 0, i, count, a, x;
            int array[100];


            printf("how many numbers?\n");
            scanf("%d", &count);
            printf("enter %d numbers: (Click 'Enter' after every number)\n", count);
            for (i = 0; i < count; i++) {
                scanf("%d", &array[i]);
            }
            printf("what number are you looking for?\n");
            scanf("%d", &x);

            for (i = 0; i < count; i++)
            {
                if (array[i] == x) {
                    found = 1;
                    break;
                }
                else if (array[i] > x)
                    break;
            }
            if (found == 1)
                printf("yes!");
            else
                printf("sorry, its not here");
            }
            break;
        case (2): {
            int found = 0, i, count, a, x;
            int array[100];
            printf("how many numbers?\n");
            scanf("%d", &count);
            printf("enter %d numbers: (Click 'Enter' after every number)\n", count);
            for (i = 0; i < count; i++) {
                scanf("%d", &array[i]);
            }
            printf("what number are you looking for?\n");
            scanf("%d", &x);

            for (i = 0; i < count; i++)
            {
                if (array[i] == x) {
                    found = 1;
                    break;
                }
                else if (array[i] < x)
                    break;
            }
            if (found == 1)
                printf("yes!");
            else
                printf("sorry, its not here");
            }
            break;
        case (3): {
            int found = 0, i, count, a, x;
            int array[100];

            printf("how many numbers?\n");
            scanf("%d", &count);
            printf("enter %d numbers: (Click 'Enter' after every number)\n", count);
            for (i = 0; i < count; i++) {
                scanf("%d", &array[i]);
            }
            printf("what number are you looking for?\n");
            scanf("%d", &x);

            for (i = 0; i < count; i++)
                if (array[i] == x) {
                    found = 1;
                    break;
                }
            if (found == 1)
                printf("yes!");
            else
                printf("sorry, its not here");
            }
            break;
        case (4): {
            int i, low, high, mid, count, x;
            int array[100];

            printf("how many numbers?\n");
            scanf("%d", &count);
            printf("enter %d numbers: (Click 'Enter' after every number)\n", count);

            for (i = 0; i < count; i++)
                scanf("%d", &array[i]);
            printf("what number are you looking for?\n");
            scanf("%d", &x);


            low = 0;
            high = count - 1;
            mid = (low + high) / 2;

            while (low <= high) {
                if (array[mid] < x)
                    low = mid + 1;
                else if (array[mid] == x) {
                    printf("yes");
                    break;
                }
                else
                    high = mid - 1;
                mid = (low + high) / 2;
            }

            if (low > high) printf("sorry, its not here");
            }
            break;
    
        case (5): {
            int array[100], n, x;

            printf("how many numbers?\n");
            scanf("%d", &n);
            printf("enter %d numbers: (Click 'Enter' after every number)\n", n);

            for (int i = 0; i < n; i++)
                scanf("%d", &array[i]);

            printf("what number are you looking for?\n");
            scanf("%d", &x);

            int result = binary_search(array, 0, n - 1, x);
            (result == -1) ? printf("Element is not present in array") : printf("Element is present at index %d", result);
            }
            break;

        case (6):
            break;
       
    }
    return 0;
}

int binary_search(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binary_search(arr, l, mid - 1, x);
        return binary_search(arr, mid + 1, r, x);
    }
    return -1;
}


