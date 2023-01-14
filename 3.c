#include <stdio.h>

int main()
{
    int board[100][100] = {0};

    int height;
    int width;
    int paper_num;
    int area = 0;
    scanf("%d", &paper_num);
    while(paper_num != 0)
    {
        scanf("%d", &height);
        scanf("%d", &width);
        for(int i = 0; i < 10; i++)
            for(int j = 0; j < 10; j++)
                board[height+i][width+j] = 1;
        
        paper_num--;
    }

    for(int i = 0; i < 100; i++)
        for(int j = 0; j < 100; j++)
            if(board[i][j] == 1) area++;

    printf("%d\n", area);

    return 0;

}