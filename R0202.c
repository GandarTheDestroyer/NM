
//JAMES ALEXIS REALUYO
//BS AEROSPACE ENGINEERING 3A
//MODULE 2:
//FORMATIVE ASSESSMENT 02
//NUMBER 2

/*Write a C program that will perform the Newton-Rhapson Method that will solve the equation f(x) = 19x^(4) - 110x^(3) - 3300x^(2) + 12000.
The program should allow the user to input the initial guess arbitrarily.
Use an error criterion of 0.1%. Show the results of all iterations in tabular form on the screen. */

    #include<stdio.h>
    #include<conio.h>
    #include<math.h>
    #include<stdlib.h>

    #define f(x) 19*pow(x,4)-110*pow(x,3)-3300*pow(x,2)+12000 //we define the function
    #define df(x) 76*pow(x,3) - 330*pow(x,2)-6600*x //first derivative of the equation

    int main ()
    {
	double x0,x1, errorcrit,dfx0,f0,f1,Error;
	int step=1;
	printf("This program solves the equation f(x) = 19x^(4) - 110x^(3) - 3300x^(2) + 12000 using Newton-Raphson Method\n");
	printf("Please input approximation value:\n");
	scanf ("%lf",&x0);
	printf("Input preferred error criterion:\n");
	scanf ("%lf",&errorcrit);
	printf("\nStep\t\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");

	//using do while loop
	 do
	 {
    dfx0 = df(x0);
    f0 = f(x0);
    if(dfx0 == 0.0)

    {
    printf("Math Error");
    break; //stops the process
    }
    x1 = x0 - f0/dfx0;
    Error = 100*((x1-x0)/x1);
    printf("%d\t\t%.4lf\t\t%.4lf\t\t%.4lf\t\t%.4lf\t\t%.4lf\n",step,x0,f0,x1,f1,fabs(Error));
    x0 = x1;
    step = step+1;
    f1 = f(x1);
    }

    while(fabs(Error)>errorcrit);
    printf("\nRoot is: %lf", x1);
    getch();
    /*The getch in C is a non-standard function used to receive a character as input from the user.
    It is defined in the header file conio.h The character entered by the user is not visible on the
    output screen but is stored in the assigned variable which makes this the best method for receiving
    passwords from a user. */
}
