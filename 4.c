#include <stdio.h>
#include <stdlib.h>

int size_div_3(int num)
{
	if(num == 1) return 0;
	else return size_div_3(num / 3) + 1;
}

int pow_3(int lev)
{
	if(lev == 1) return 3;
	else return pow_3(lev - 1) * 3;
}

int main()
{
	char ** sq;
	int num;
	int div_3_level;
	int remain[8] = {0,};
	
	scanf("%d", &num);
	div_3_level = size_div_3(num);
	sq = (char **) malloc(sizeof(char*) * num);
	for(int i = 0; i < num; i++)
		*(sq + i) = (char *) malloc(sizeof(char) * num);
	remain[0] = 1;

	for(int i = 1; i < 8; i++)
	{
		remain[i] = remain[i-1] + pow_3(i);
	}

	for(int i = 0; i < num; i++)
	{
		for(int j = 0; j < num; j++)
		{
			sq[i][j] = '*';
		}
	}
	for(int lev = 1; lev <= div_3_level ; lev++)
	{
		for(int i = 0; i < num ; i++)
		{
			for(int j = 0 ; j < num ; j++)
			{
				if( i % pow_3(lev) == remain[lev-1] && j % pow_3(lev) ==  remain[lev-1] ) 
				{
					if(lev== 1)
						{
						sq[i][j] = ' ';
						}
					else
						for(int k = -remain[lev -2]; k <= remain[lev -2]; k++)
						{
							for(int m = -remain[lev -2]; m <= remain[lev -2]; m++)
							{
								sq[i+k][j+m] = ' ';
							}
						}
				}
			}
		}
	}
	
	for(int i = 0; i < num; i++)
	{
		for(int j = 0; j < num; j++)
		{
			printf("%c", sq[i][j]);
		}
		printf("\n");
	}
	return 0;
}