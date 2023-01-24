#include <stdio.h>


int main()
{
    int num[10001] = {0};
    int N;
    int tmp;
    int counting = 0;
    int t = 1;

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &tmp);
        num[tmp]++;
    }
    
    while(counting != N)
    {
        if(num[t] != 0)
        {
            printf("%d\n",t);
            num[t]--;
            counting++;
        }
        else
            t++;
    }

    return 0;
}