 
#include <stdio.h>  
#include <string.h>  
int map[9][9];  
bool row[9][10];  
bool col[9][10];  
bool black[3][3][10];  
int flag,i,j;  
void dfs(int x)  
{  
    int r,c,k;  
    r = x / 9;  
    c = x % 9;  
    if(flag)  
    {  
        return ;  
    }  
    if(x == 81)  
    {  
        for(i=0;i<9;i++)  
        {  
            for(j=0;j<9;j++)  
            {  
                printf("%d ",map[i][j]);  
            }  
            printf("\n");  
        }  
        flag = 1;  
        return ;  
    }  
    if(!map[r][c])  
    {  
        for(k=1;k<=9;k++)  
        {  
            if(!(row[r][k] || col[c][k] || black[r/3][c/3][k]))  
            {  
                map[r][c] = k;  
                row[r][k] = col[c][k] = black[r/3][c/3][k] = 1;  
                dfs(x + 1);  
                row[r][k] = col[c][k] = black[r/3][c/3][k] = 0;  
                map[r][c] = 0;  
            }  
        }  
    }  
    else  
        dfs(x + 1);  
}  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    while(t--)  
    {  
        flag = 0;  
        memset(row,0,sizeof(row));  
        memset(col,0,sizeof(col));  
        memset(black,0,sizeof(black));  
        for(i=0;i<9;i++)  
        {  
            for(j=0;j<9;j++)  
            {  
                scanf("%d",&map[i][j]);  
                if(map[i][j])  
                {  
                    row[i][map[i][j]] = 1;  
                    col[j][map[i][j]] = 1;  
                    black[i/3][j/3][map[i][j]] = 1;  
                }  
            }  
        }  
        dfs(0);  
    }  
    return 0;  
}                  