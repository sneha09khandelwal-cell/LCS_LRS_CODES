#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>




struct cell{
    char dir;
    int val;
   
};

int max(int a, int b) {
    return (a > b) ? a : b;
}






void LCS(struct cell cost[100][100],int m, int n, char A[m], char B[n])
{
    int i,j;
   
   
   
        for(int i=0;i<m;i++)
        {
            cost[i][0].val=0;
            cost[i][0].dir='H';
        }
        for(int j=0;j<n;j++)
        {
            cost[0][j].val=0;
            cost[0][j].dir='H';
        }
   
   
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(A[i-1]!=B[j-1])
                {
                    cost[i][j].val=max(cost[i][j-1].val,cost[i-1][j].val);
                    if(cost[i-1][j].val>=cost[i][j-1].val)
                    {
                        cost[i][j].dir='U';
                    }
                    else
                    {
                        cost[i][j].dir='S';
                    }
                }


                else
                {
                    cost[i][j].val=cost[i-1][j-1].val +1;
                    cost[i][j].dir='D';
           
                }


            }


        }
   
}


//yet to correct


void print_LCS(struct cell cost[100][100],char A[], char B[], int i, int j)
{
    if(i==0 || j==0)
    {
        return;
    }
    else
    {
        if(cost[i][j].dir=='D')
        {
        print_LCS(cost,A,B,i-1,j-1);
        printf("%c", A[i-1]);

        }


        else if (cost[i][j].dir == 'U')

        {
            print_LCS(cost,A,B,i-1,j);
        }
        else
        {
            print_LCS(cost, A, B, i, j-1);

        }
    }
   
}




int main()
{
    struct cell cost[100][100];

    int m,n;
    char x[50],y[50];
    printf("Enter String X: ");
    scanf("%s",x);
    printf("Enter String Y: ");
    scanf("%s",y);
    m=strlen(x)+1;
    n=strlen(y)+1;
    
    //creating cost matrix via LCS algo
    LCS(cost,m,n,x,y);


    //print cost matrix
    printf("\nCost matrix: \n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d/%c  ",cost[i][j].val,cost[i][j].dir);
            
        }
        printf("\n");
    }

    //print LCS 
    printf("LCS:\n");
    print_LCS(cost,x,y,m-1,n-1);

    //print LCS value:
    printf("\nLength of LCS: %d",cost[m-1][n-1].val);
   


}
