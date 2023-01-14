#include <stdio.h>

int main()
{
    int first, second, third;

    scanf("%d%d%d", &first, &second, &third);

    if(first == second && first == third)
        printf("%d\n", 10000 + first * 1000);
    else if(first == second || first == third)
        printf("%d\n", 1000 + first * 100);
    else if(second == third)
        printf("%d\n", 1000 + second * 100);
    else
    {
        if(first > second && first > third)
            printf("%d\n", first * 100);
        else if( second > first && second > third)
            printf("%d\n", second * 100);
        else if(third > first && third > second)
            printf("%d\n", third * 100);
    }

    return 0;
}