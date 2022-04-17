#include <stdio.h>
#include <stdlib.h>

void printBoard(int **board,int n)
{
    printf("\n\n");
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
            printf("%d\t",board[i][j]);
        
        printf("\n\n");
    }
}


int isSafe(int row, int col, int *queen, int n,int **board)
{
    int lr,rl;
    for(int i = 0; i<n; i++)
    {
        if(queen[i]==col)
            return 0;
    }


    //l to r diagonal
    lr = row - col;
    rl = row + col;

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if((i-j)==lr)
            {
                if(board[i][j])
                    return 0;
            }

            if((i+j)==rl)
            {
                if(board[i][j])
                    return 0;
            }
        }
    }

    return 1; 
}

void nQueen(int **board,int n)
{
    int q,i,c;

    int *queen = (int *)malloc(n*sizeof(int));
    for(i = 0; i<n; i++)
        queen[i] = -1;

    for(q = 0; q<n; q++)
    {
        c = 0;
        for(i = queen[q]+1; i<n; i++)
        {
            if(isSafe(q,i,queen,n,board))
            {
                c = 1;
                board[q][i] = 1;
                queen[q] = i;
                
                break;
            }
        }
        
        if(c!=1)
        {
            queen[q] = -1;
            q--;
            board[q][queen[q]] = 0;
            q--;
        }
        printBoard(board,n);
    }
    free(queen);
}


int main()
{
    int n =5 ,i,j;

    int ** board = (int **)malloc(n*sizeof(int*));
    for(i = 0; i<n; i++)
        board[i] = (int *)malloc(n*sizeof(int));

    for(i = 0; i<n; i++)
    {
        for(j = 0; j<n; j++)
            board[i][j] = 0;
    }

    nQueen(board,n);
    

    free(board);
    return 0;

}