#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[1000];
int t = -1;

void push(char n)
{
    t++;
    stack[t] = n;
}

char pop()
{
    char m = stack[t];
    t--;
    return m;
}

void swap(char **str1_ptr, char **str2_ptr)
{
  char *temp = *str1_ptr;
  *str1_ptr = *str2_ptr;
  *str2_ptr = temp;
}  

void printBoard(int **dp,int m,int n,int x)
{
    for(int i = x;i<=n; i++ )
    {
        for(int j = x; j<=m; j++)
            printf("%d\t",dp[i][j]);
        printf("\n");
    }
}

void lcs(char *s1, char *s2, int p, int q)
{

    int m, n;

    if(p>=q)
    {
        m = p;
        n = q;
    }
    else if(p<q)
    {
        m = q;
        n = p;
        swap(&s1, &s2);
    }

    int **dp = (int **)malloc((m+1)*sizeof(int *));
    for(int i = 0; i<=n; i++)
        dp[i] = (int *)malloc((n+1)*sizeof(int));

    int **dir = (int **)malloc((m+1)*sizeof(int *));
    for(int i = 0; i<=n; i++)
        dir[i] = (int *)malloc((n+1)*sizeof(int));

    for(int i = 0;i<=m; i++){
        dp[0][i] = 0;
        dir[0][i] = 0;
    }

    for(int j = 0; j<=n; j++){
        dp[j][0] = 0;
        dir[j][0] = 0;
    }

    

    for(int i = 1;i<=n; i++ )
    {
        for(int j = 1; j<=m; j++)
        {
            if(s2[i-1]==s1[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                dir[i][j] = 1;
            }
            else
            {
                if(dp[i-1][j]>dp[i][j-1]){
                    dp[i][j] = dp[i-1][j];
                    dir[i][j] = 2;
                }
                else{
                    dp[i][j] = dp[i][j-1];
                    dir[i][j] = 3;
                }
            }
            
            
        }
    }

    printBoard(dp,m,n,0);
    printf("\n");
    printf("\n");
    printBoard(dir,m,n,1);
    printf("\n");
    printf("\n");

    int i = n;
    int j = m;

    while(1)
    {
        if(i==0 || j ==0)
            break;

        if(dir[i][j]==3) // left arrow
            j--;
        if(dir[i][j]==2) // up arrow
            i--;
        if(dir[i][j]==1) // diagonal arrow
        {
            push(s1[j-1]);
            i--;
            j--;
            
        }
    }

    int x = dp[n][m];
    while(x>=1)
    {
        printf("%c\t",pop());
        x--;
    }

    free(dp);

    
}

int main()
{
    char s1[] = "one";
    char s2[] = "longest";

    int m = strlen(s1);
    int n = strlen(s2);

    lcs(s1,s2,m,n);

    return 0;
}