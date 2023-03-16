/***JAMES ALEXIS REALUYO
BS AEROSPACE ENGINEERING 3A
MODULE 5: Ordinary Differential Equations
FORMATIVE ASSESSMENT 05***/

#include <stdio.h>
#include <math.h>

/** Write a C program that will perform the classical fourth-order Runge-Kutta Method. It must be robust enough to solve the ordinary differential equation, dy/dx = 4e^(0.8x) - 0.5y */

int main() //main function
{
    int i, n; //declaring as integer
    double x0=0, y0=2, h=0.3; //initial values are set. declaring as decimal
    double x, y, slope; //declaring as decimal
    double k1, k2, k3, k4; //declaring as decimal

    printf("Runge-Kutta Method Fourth-Order\n"); //printing title of program

    printf("Solving for the Differential Equation dy/dx = 4e^(0.8x) - 0.5y given h=0.3 as our step-width and (0,2)\n"); //tells user what equation we are solving
    printf("Please input the desired number of iterations: "); //asks for number of iterations
    scanf("%d",&n); //scans for variable n declared as decimal

    printf("x0\t\ty0\t\tk1\t\tk2\t\tk3\t\tk4\t\tslope\n"); //printing the labels for the table
    printf("____________________________________________________________________________________________________________\n"); //line containing the table
        // Loop for the Runge Kutta Fourth Order method of our given equation
        for(i=1; i <= n; i++){ //loop for each RK iteration

            // Main formula: y0 = y0 + 1/6 (k1 + 2k2 + 2k3 + k4)h
            // Solving for k1, k2, k3, k4
            k1 = 4*(exp(0.8*x0)) - (0.5*y0);
                x = x0 + (h/2);
                y = y0 + (k1*(h/2));
            k2 = 4*(exp(0.8*x)) - (0.5*y);
                x = x0 + (h/2);
                y = y0 + (k2*(h/2));
            k3 = 4*(exp(0.8*x)) - (0.5*y);
                x = x0 + h;
                y = y0 + (k3*h);
            k4 = 4*(exp(0.8*x)) - (0.5*y);

            slope = (k1 + 2*k2 + 2*k3 + k4)/6;    // performing(k1 + 2*k2 + 2*k3 + k4)/6

            x0 = x0 + h; //each x is added with the step-width
            y0 = y0 + (slope*h); //solves for x0 and y0

    printf("%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",x0,y0,k1,k2,k3,k4,slope); //printing the values for each iteration
        }
         printf("____________________________________________________________________________________________________________\n"); //line containing the table it is placed outside the for loop otherwise it will generate a line for each iteration
    return 0; //program implementation is accomplished and that the processor can now be uploaded. Even if we can't complete the task, the uncertainty persists due to the fact that when the program's implementation is ended, the return void command would run immediately.
}
