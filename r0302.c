/**
JAMES ALEXIS REALUYO
BS AEROSPACE ENGINEERING 3A
MODULE 3:
FORMATIVE ASSESSMENT 03
NUMBER 2
**/




#include<stdio.h>
#define size 80 //defined size of array

//main function
int main()
{
    float a[size][size], b[size], x[size], y[size]; //variables defined as float


    int n = 0, m = 0, i = 0, j = 0; //defined as integer
    printf("size of matrix: "); //input matrix size
    scanf("%d",&n);


    for (i = 0; i < n; i++) // left side values input
    {
        for (j = 0; j < n; j++)
        {
           printf("Enter A%d%d :",i,j);
            scanf("%d",&a[i][j]);
        }
    }

    printf("\nInput values found on the right side of equation\n"); //input values at right side of equation
    for (i = 0; i < n; i++)
    {
        printf("Enter A%d%d ",i,j);
        scanf("%d",&b[i]);
    }

    printf("Input nitial values of x:\n"); //input values of ex
    for (i = 0; i < n; i++)
    {
        printf("Enter value for x[%d]: ",i); //x values indicated just less than the indicated matrix size n
        scanf("%d",&x[i]);
    }

    printf("\nNumber of iterations: "); //input number of iterations
    scanf("%d",&m);

    while (m > 0)
    {
        for (i = 0; i < n; i++)
        {
            y[i] = (b[i] / a[i][i]);
            for (j = 0; j < n; j++)
            {
                if (j == i)
                    continue;
                y[i] = y[i] - ((a[i][j] / a[i][i]) * x[j]);
                x[i] = y[i];
            }
            printf("x%d = %f    ", i + 1, y[i]); //printing solution
        }
        printf("\n"); //each loop is then proceeded with a new line
        m--;
    }
    return 0;//returns zero, the program will execute successfully and did what it was intended to do
}
