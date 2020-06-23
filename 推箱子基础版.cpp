/*--------------------------------------------------
      文件名称：推箱子
      文件描述：游戏
      编译环境：Code::Blocks 16.01
---------------------------------------------------*/
#include <stdio.h>
#include <conio.h>

int map[9][11] = {
    {0,1,1,1,1,1,1,1,1,1,0},
    {0,1,0,0,0,1,0,0,0,1,0},
    {0,1,0,4,0,4,4,4,0,1,0},
    {0,1,0,4,0,4,0,4,0,1,1},
    {0,1,0,0,0,0,5,0,4,0,1},
    {1,1,0,1,1,1,1,0,4,0,1},
    {1,0,3,3,3,3,1,1,0,0,1},
    {1,0,3,3,3,3,3,0,0,1,1},
    {1,1,1,1,1,1,1,1,1,1,0}};

void PlayGame();
void DrawMap();

int main()
{
    while (1)
    {
        system("cls");
        DrawMap();
        PlayGame();
    }
    return 0;
}

void DrawMap()
{
    int i,j;
    for (i=0; i < 9; i++)
    {
        for (j=0; j <11; j++)
        {
            switch (map[i][j])
            {
            case 0:
                printf("  ");//0空地
                break;
            case 1:
                printf("■");//1墙
                break;
            case 3:
                printf("☆");//3目的地
                break;
            case 4:
                printf("□");//4箱子
                break;
            case 5:
                printf("♀");//5人物
                break;
            case 7: //4+3 代表箱子+目的地
                printf("★");
                break;
            case 8: //5+3 人物+目的地
                printf("♀");
                break;
            }
        }
        printf("\n");
    }
    printf("欢迎来到推箱子游戏！\n您可以通过方向键控制人物推动箱子到达目的地。\n修改日期:2017年10月13日\n");
    return 0;
}//通过改变数组元素的排列顺序，来达到游戏的目的，并且进行重绘
//玩游戏的过程
void PlayGame()
{
    int i,j,r,c;//人的行和列
    for(i=0;i<9;i++)
    {
        for(j=0;j<11;j++)
        {
            if(map[i][j]==5||map[i][j]==8)
            {
                r=i;
                c=j;
            }
        }
    }
    printf("%d %d\n",r,c);
    int dir=getch();//getchar()接受字符，需要按下回车接收完成
    switch (dir)
    {
    case 72://上
        //1.人的前面是空地，2.人的前面是目的地
        if(map[r-1][c]==0||map[r-1][c]==3)
        {
            map[r-1][c] += 5;
            map[r][c] -= 5;
        }
        //3人的前面是箱子
        else if(map[r-1][c]==4||map[r-1][c]==7)
        {
           if(map[r-2][c]==0||map[r-2][c]==3)
           {
               map[r-2][c] +=4;
               map[r-1][c] +=1;
               map[r][c] -=5;
           }
        }
        break;
    case 80://下
        if(map[r+1][c]==0||map[r+1][c]==3)
        {
            map[r+1][c] += 5;
            map[r][c] -= 5;
        }
        else if(map[r+1][c]==4||map[r+1][c]==7)
        {
           if(map[r+2][c]==0||map[r+2][c]==3)
           {
               map[r+2][c] +=4;
               map[r+1][c] +=1;
               map[r][c] -=5;
           }
        }
        break;
    case 75://左
        if(map[r][c-1]==0||map[r][c-1]==3)
        {
            map[r][c-1] += 5;
            map[r][c] -= 5;
        }
        else if(map[r][c-1]==4||map[r][c-1]==7)
        {
           if(map[r][c-2]==0||map[r][c-2]==3)
           {
               map[r][c-2] +=4;
               map[r][c-1] +=1;
               map[r][c] -=5;
           }
        }
        break;
    case 77://右
        if(map[r][c+1]==0||map[r][c+1]==3)
        {
            map[r][c+1] += 5;
            map[r][c] -= 5;
        }
        else if(map[r][c+1]==4||map[r][c+1]==7)
        {
           if(map[r][c+2]==0||map[r][c+2]==3)
           {
               map[r][c+2] +=4;
               map[r][c+1] +=1;
               map[r][c] -=5;
           }
        }
        break;
        }
}












