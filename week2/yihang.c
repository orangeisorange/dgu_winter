#include <stdio.h>


int main()
{
    int n, k;
    int ans = 1;
    scanf("%d%d", &n, &k);

    if(k == 0) printf("1\n");
    else
    {
        for(int i = k; i > 0; i--)
        {
            ans *= (n + i - k);
        }
        for(int i = k; i > 0; i--)
        {
            ans = ans / i;
        }
        printf("%d", ans);
    }
    
    return 0;
}