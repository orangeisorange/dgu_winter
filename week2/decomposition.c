#include <stdio.h>

int digit_cal(int num);
int dec_check(int test, int ans);

int main()
{
    int num;
    int digit;
    int decom;
    scanf("%d", &num);
    digit = digit_cal(num);
    decom = num - digit * 10;
    if(decom < 0) decom = 0;
    for(; decom < num; decom++)
    {
        if(dec_check(decom, num) == 1) break;
    }
    if(decom == num) printf("0");
    else printf("%d", decom);

    
    return 0;

}


int digit_cal(int num)
{
    int tmp;
    tmp = num / 10;
    if(tmp == 0)    return 1;
    else  return digit_cal(tmp) + 1;
}

int dec_check(int test, int ans)
{
    int tmp = test;
    int tmp_ans = test;
    while (tmp != 0)
    {
        tmp_ans += tmp % 10;
        tmp = tmp / 10;
    }
    if(ans == tmp_ans) return 1;
    else return 0;
}