
//JAMES ALEXIS REALUYO
//BS AEROSPACE ENGINEERING 3A
//MODULE 2:
//FORMATIVE ASSESSMENT 02
//NUMBER 3

    #include<stdio.h>
    #include<math.h>
    #define g 9.81

    double f(double m, double c, double t, double v)
    {

    return ((g*m)/c) *(1-exp((-c/m)*t)) - v;
    }

    void secantm (double x0, double x1, double c, double t, double v )
    {
//return type function

/*the data type of the values are return_type.
Some functions perform the desired operations without returning a value.
In this case, the return_type is the keyword void */

    double xSUB1;
    double xSUBNegative1 = x0;
    double xIN = x1;
    int iteration = 1;
    double error;
    double input,input2;

    do
    {

    xSUB1 = (xIN - ((f(xIN,c,t,v)*(xIN - xSUBNegative1)) /(f(xIN,c,t,v) - f(xSUBNegative1,c,t,v))));
    printf("Iteration No. \txSUBNegative1\txSUB1\tError\n");
    input = xIN;
    xSUBNegative1 = xIN;
    xIN = xSUB1;
    input2 = xSUB1;

    error = 100 * ((input2 - input) / input) ;

     printf(" %d\t\t%lf\t%lf\t%lf\n",iteration,xSUBNegative1,xSUB1,fabs(error));
     iteration++;

    }

    while (fabs(error) > 0.01);
    printf("Mass of the object is: %lf \n\n", xSUB1);

    }
//using secant method. initally tried the newton raphson but the derivative made the solution a bit
//complicated for me
    void secantc (double x0, double x1, double m, double t, double v )
    {
    double xSUB1;
    double xSUBNegative1 = x0;
    double xIN = x1;
    int iteration = 1;
    double error;
    double input,input2;

    do
    {
    xSUB1 = (xIN -  ( (f(m,xIN,t,v)*(xIN - xSUBNegative1)) /(f(m,xIN,t,v) - f(m,xSUBNegative1,t,v)) ));
    printf("Iteration No. \txSUBNegative1\txSUB1\tError\n");
    input = xIN;
    xSUBNegative1 = xIN;
    xIN = xSUB1;
    input2 = xSUB1;
    error = 100 * ((input2 - input) / input);
    printf(" %d\t\t%lf\t%lf\t%lf\n",iteration,xSUBNegative1,xSUB1,fabs(error));
    iteration++;

    }
    while (fabs(error) > 0.01); //made it absolute because it kept on showing negative sign
    printf("The drag coefficient is: %lf \n\n", xSUB1);

    }

    int main()
    {

    char select; //designated select as char

    printf("In the previous module we are given a problem involving a free-falling object.\nThis program lets the user choose whether to solve for the\nmass or drag coefficient. ");
    printf("Select 'a' for mass [kg] and 'b' for drag coefficient\n");
    scanf("%c", &select);  //initially tried to use switch but opted for if else


    if (select == 'a')

    {
    double x0, x1, c,t,v;
    printf("Input the values for the drag coefficient, time [seconds], and velocity [m/s] in order:\n");
    scanf(" %lf", &c);
    scanf(" %lf", &t);
    scanf(" %lf", &v);

    printf("Pls provide two guesses [first the left hand bracket and second the right hand bracket]\n");
    printf("of the values that bracket the root of the equation:\n");
    scanf(" %lf", &x0); scanf(" %lf", &x1);
    secantm(x0, x1, c,t,v);

    }
    else if(select == 'b')
    {

    double x0, x1, m,t,v;

    printf("Input the values for the mass [kg] , time [s], and velocity [m/s] in order:\n");
    scanf(" %lf", &m);
    scanf(" %lf", &t);
    scanf(" %lf", &v);

    printf("Pls provide two guesses [ first the left hand bracket and second the right hand bracket]\n");
    printf("of the values that bracket the root of the equation:\n");
    scanf(" %lf", &x0); scanf(" %lf", &x1);

    secantc(x0, x1, m,t,v);

    }

    return 0;
    }
