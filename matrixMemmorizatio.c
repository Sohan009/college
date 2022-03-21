#include <stdio.h>
#include <stdlib.h>

void matrixChain(int n,int *d,int **c,int **k)
{
    int i,p,q,con,minValue,minIndex,cost;
    int max = 99999;

    for(i=1; i<=n; i++)
        c[i][i] = 0;


    con = 1;
    for(i = 1; i<n ; i++)
    {   p=1;
        q=1;
        while(q<n)
        {
           q = p+con;

            c[p][q] = max;
            for(int x = p; x<q; x++)
            {
                
                cost = c[p][x] + c[(x+1)][q] + (d[p-1]*d[x]*d[q]);
                if(cost<c[p][q])
                {
                    c[p][q] = cost;
                    k[p][q] = x;
                }
                
            }
           p++; 
        }
        con++;
    }


}

void printCost(int **c, int n)
{
    for(int i = 1; i<=n; i++)
    {
        for(int j = i; j<=n; j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
}

void printIndex(int **k,int n)
{
    for(int i = 1; i<n; i++)
    {
        for(int j = i+1; j<=n; j++)
        {
            printf("%d ",k[i][j]);
        }
        printf("\n");
    }
}


void printParen(int **k,int i, int j)
{
    if (i ==j)
    {
        printf("A%d",i);
    }
    else
    {
        printf("(");
        printParen(k,i,k[i][j]);
        printParen(k,k[i][j]+1,j);
        printf(")");
    }
}




int main()
{
    int n,i;
    scanf("%d",&n);


    int* d = (int*)malloc((n+1)*sizeof(int));

    for(int i = 0;i<=n;i++)
        scanf("%d",&d[i]);
    

    int** c = (int**)malloc((n+1)*sizeof(int)); 
    for(i=0;i<=n;i++)
        c[i] = (int*)malloc((n+1)*sizeof(int));

    int** k = (int**)malloc((n+1)*sizeof(int)); 
    for(i=0;i<=n;i++)
        k[i] = (int*)malloc((n+1)*sizeof(int));


    matrixChain(n,d,c,k);

    printf("\n");

    printCost(c,n);

    printf("\n");

    printIndex(k,n);

    printf("\n");

    printParen(k,1,n);

    printf("\n\n");

    printf("%d",c[1][n]);

    free(d);
    free(c);
    free(k);

    return 0;

}