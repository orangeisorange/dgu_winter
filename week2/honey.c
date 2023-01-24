#include <stdio.h>


int main()
{
    int num;
    int former_front = 1;
    int front = 2;
    int passing = 1;
    scanf("%d", &num);
    if(num == 1) printf("1\n");
    else{
    for(passing;;passing++)
    {
        if(front > num && former_front <= num) break;
        former_front = front;
        front = front + 6 * passing; 
    }
    printf("%d\n", passing);
    }

    return 0;
}