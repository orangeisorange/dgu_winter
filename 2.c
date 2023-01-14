#include <stdio.h>

int main()
{
    char a, b;
    int ten, one;
    int tmp_cal;
    int ans;
    int tmp = 100;
    int count = 0;

    a = getchar();
    b = getchar();

    if(b == '\n')
    {
        ten = 0;
        one = (int)a - 48;
        ans = one;

        while(ans != tmp)
        {
            tmp_cal = ten;
            ten = one;
            one = (tmp_cal + one) % 10;
            tmp = ten * 10 + one;
            count++;
        }
    }
    else
    {
        ten = (int)a - 48;
        one = (int)b - 48;
        ans = ten * 10 + one;

        while(ans != tmp)
        {
            tmp_cal = ten;
            ten = one;
            one = (tmp_cal + one) % 10;
            tmp = ten * 10 + one;
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
        
}