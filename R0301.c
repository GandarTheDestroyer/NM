
/**JAMES ALEXIS REALUYO
BS AEROSPACE ENGINEERING 3A
MODULE 3:
FORMATIVE ASSESSMENT 03
NUMBER 1
**/

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <malloc.h>


void gaussjordan(int n, double **a, double *b, double *x)

//n defined as integer
//decimals for pointer a, b and x. double asterisk "prioritizes" the pointer
{
	int i, j, k;
	int pivot;
	double factor;
	double number, result;

	for(k = 1; k <= n; k++)
	{

		if(k < n)
		{
			pivot = k; // Partial pivoting for column
			//partial pivoting helps improve stability of the program


			number = fabs(a[k][k]);
			for(i = k+1; i <= n; i++)
			{
				if(number < fabs(a[i][k])) //float absolute value of the result
				{
					number = fabs(a[i][k]);

					pivot = i;
				}
			}

			if(pivot != k)
			{
				for(j = 1; j <= n; j++)
				{
					result = a[pivot][j];
					a[pivot][j] = a[k][j];
					a[k][j] = result;

				}

				result = b[pivot];
				b[pivot] = b[k];
				b[k] = result;

			}
		}


		factor = a[k][k]; // gauss jordan elimination process
		for(j = 1; j <= n; j++) a[k][j] /= factor;
		b[k] /= factor;
		for(i = 1; i <= n; i++)
		{
			if(i == k)	continue;

			factor = a[i][k];
			for(j = 1; j <= n; j++)	a[i][j] -= a[k][j]*factor;
			b[i] -= b[k]*factor;

		}
	}

	for(i = 1; i <= n; i++)	//for unknown values
	x[i] = b[i];
		printf("\n"); // new line for each printed value
	printf("Solution:\n");

	printf("x = ("); //prints out solution
	for(i = 1; i <= n-1; i++)	printf("%lf, ", x[i]);
	printf("%lf)\n", x[n]);
	return; //a return with no 0 or -1 ignores errors and continues execution of code
}

int main() //main function
{
	int i, j, n; //defined as integer
	double **a, *b, *x; //pointer



	printf("\nNumber of equations: "); //input number of equations in the problem
	scanf("%d", &n);
    printf("Variables marked 'A' are values on left hand side of the equations and\n'c' for the right hand side\n");

	x = (double *)malloc( (n+1)*sizeof(double) ); //malloc, or memory allocation, allocates the requested memory and returns a pointer to it.
	b = (double *)malloc( (n+1)*sizeof(double) ); // malloc alows us for the user to define any number of equations for the matrix size
	a = (double **)malloc( (n+1)*sizeof(double *) ); //point once to make a
	for(i = 1; i <= n; i++)
		a[i] = (double *)malloc( (n+1)*sizeof(double) );

	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
		{
			printf("A[%d][%d] = ", i, j);//input variables left hand side of the equations
			scanf("%lf", &a[i][j]);

		}
			printf("c[%d] = ", i);//right hand side of the equation
			scanf("%lf", &b[i]);
	}

	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
		{
		printf("%lf\t", a[i][j]);//displays the matrix

		}
		printf(" %lf \n", b[i]);

	}
	gaussjordan(n, a, b, x);//gauss jordan process is called


	return(0); //returns zero, the program will execute successfully and did what it was intended to do
}
