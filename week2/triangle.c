#include <stdio.h>

void traingle_check(int a, int b, int c);
int main()
{
    int a, b, c;
    
    while(1)
    {
        scanf("%d%d%d", &a, &b, &c);
        if(a == 0 && b == 0 && c == 0) break;

        traingle_check(a, b, c);
    }

}

void traingle_check(int a, int b, int c)
{
    if(a == 0 || b == 0 || c == 0)
    {
        printf("wrong\n");
        return;
    }
    if(a >= b)
    {
        if(a >= c)
        {
            if(a * a == b * b + c * c) printf("right\n");
            else printf("wrong\n");
            return;
        }
        else
        {
            if(c * c == b * b + a * a) printf("right\n");
            else printf("wrong\n");
            return;
        }
    }
    else
    {
        if(b > c)
        {
            if(b * b == a * a + c * c) printf("right\n");
            else printf("wrong\n");
            return;
        }
        else
        {
            if(c * c == b * b + a * a) printf("right\n");
            else printf("wrong\n");
            return;
        }
    }
    
}