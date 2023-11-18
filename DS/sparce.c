#include <stdio.h>
#define MAX_ROWS 100
#define MAX_COLS 100
int r,c;

void sparse(int num , int a[MAX_ROWS][MAX_COLS])
{
    int s[num+1][3];
    int i,j,k=1;
    for (i = 0; i <r ; i++)
    {
        for ( j = 0; j < c; j++)
        {
            if (a[i][j]!=0)
            {
                s[k][0]=i;
                s[k][1]=j;
                s[k][2]=a[i][j];
                k++;
            }
            
        }
        
    }
    s[0][0]=r;
    s[0][1]=c;
    s[0][2]=num;
    printf("The sparse matrix in three coloumn representation is ,\n");
    for (i = 0; i < num+1 ; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            printf("%d ",s[i][j]);
        }
            printf("\n");
    }
    
}

int main()
{
    int i,j,count=0;
    printf("Enter the no of rows: ");
    scanf("%d",&r);
    printf("Enter the no of coloumns: ");
    scanf("%d",&c);
    int mat[MAX_ROWS][MAX_COLS];
    for (i = 0; i < r ; i++)
    {
        for ( j = 0; j < c; j++)
        {
            printf("Enter the element[%d][%d]: ",i,j);
            scanf("%d",&mat[i][j]);
            if (mat[i][j]!=0)
            {
                count++;
            }
        }
    }
    sparse(count,mat);
    return 0;
}