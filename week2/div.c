#include <stdio.h>

int main()
{
    int a, b;
    int tmp;
    int gcd=0;
    int lcm=0;

    scanf("%d%d", &a, &b);

    if(a < b)
    {
        tmp = a;
        a = b;
        b = tmp;
    }

    for(int i = 1; i <= b / 2; i++)
    {
        if(a%i == 0 && b%i == 0) gcd = i;
    }
    if(a%b == 0) gcd = b;

    lcm = (a / gcd) * (b / gcd) * gcd;

    printf("%d\n%d", gcd, lcm);

    return 0;
}