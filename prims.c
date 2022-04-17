#include <stdio.h>

int checkVis(int n,int visted[n])
{
    for(int i = 0; i<n; i++)
    {
        if(visted[i]==0)
            return 1;
    }
    return 0;
}

void minEdge(int n,int visited[n], int parent[n],int graph[n][n],int *minVal,int *minInd,int *x)
{
    *minVal = 99999;
    for(int i = 0; i<n; i++)
    {
        if(visited[i]==1)
        {
            for(int j = 0; j<n; j++)
            {
                if(graph[i][j]!=0 && *minVal>graph[i][j] && visited[j]==0)
                {
                    *minVal = graph[i][j];
                    *minInd = j;
                    *x = i;
                }
            }
            
        }
    }
    parent[*minInd] = *x;
}

void prims(int n,int graph[n][n])
{
    int parent[n];
    for(int i = 0; i<n; i++)
        parent[i] = -1;

    int visited[n];
    for(int i = 0; i<n; i++)
        visited[i] = 0;

    int v = 3;
    visited[v] = 1;


    int minVal,minInd,x;
    
    while(checkVis(n,visited))
    {
       minEdge(n,visited,parent,graph,&minVal,&minInd,&x);
       visited[minInd] = 1; 
    }


    for(int m = 0; m<n; m++){
        if(parent[m]!=-1)
            printf("%d - %d\t %d\n",parent[m],m,graph[parent[m]][m]);
    }



}

int main()
{

     

    int graph[5][5] = 
        { { 0, 4, 8, 0, 0 },
        { 4, 0, 2, 6, 0 },
        { 8, 2, 0, 5, 9 },
        { 0, 6, 3, 0, 5 },
        { 0, 0, 9, 5, 0 } };


    prims(5,graph);
}