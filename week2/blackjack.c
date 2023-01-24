#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *cards;
    int n, ans;
    int tmp, tmp1;

    scanf("%d%d", &n, &ans);

    cards = (int*)malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d",&tmp);
        cards[i] = tmp;
    }
    tmp = cards[0]+cards[1]+cards[2];
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            for(int k = j+1; k < n; k++)
            {
                tmp1 = cards[i]+ cards[j] + cards[k];
                if(tmp > ans && tmp1 <= ans) tmp = tmp1;
                if(tmp < tmp1 && tmp1 <= ans)
                    tmp = tmp1;
                
            }
        }
    }
    printf("%d\n", tmp);

    return 0;

}