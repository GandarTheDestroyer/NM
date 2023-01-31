#include<stdio.h>
#include<conio.h>
#include<math.h>

#define f(x) 19*pow(x,4)-110*pow(x,3)-3300*pow(x,2)+12000

int main()
{
	 float x0, x1, x2, f0, f1, f2, e,calcE;
	 int iteration = 1;

	 /* Inputs */
	 up:
	 printf("\nEnter two initial guesses:\n");
	 scanf("%f%f", &x0, &x1);
	 printf("Enter tolerable error:\n");
	 scanf("%f", &e);

	 /* Calculating Functional Value */

	 f0 = f(x0);
	 f1 = f(x1);
	 /* Checking whether given guesses brackets the root or not. */
	 if( f0*f1 > 0.0)
	 {
		  printf("Incorrect Initial Guesses.\n");
		  goto up;
	 }


	 printf("\nIteration\t\tx0\t\tx1\t\tx2\t\tf(x2)\t\t\terror\n");
	 do
	 {
		  x2 = (x0 + x1)/2; //midpoint
		  f2 = f(x2);
		  calcE = (x1-x0)/x2;
		  printf("%d\t\t%0.4f\t\t%0.4f\t\t%0.4f\t\t%0.4f\t\t%0.4f\n",iteration, x0, x1, x2, f2,calcE);

		  if( f0 * f2 < 0)
		  {
			   x1 = x2;
			   f1 = f2;
		  }
		  else
		  {
			   x0 = x2;
			   f0 = f2;
		  }
		  iteration = iteration + 1;
	 }while(calcE>e);
	 printf("\nRoot is: %f", x2);
	 getch();
}
