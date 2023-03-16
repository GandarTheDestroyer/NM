
//JAMES ALEXIS REALUYO
//BS AEROSPACE ENGINEERING 3A
//MODULE 2:
//FORMATIVE ASSESSMENT 02
//NUMBER 1


    #include<stdio.h>
    #include<conio.h>
    #include<math.h>

    #define f(x) 19*pow(x,4)-110*pow(x,3)-3300*pow(x,2)+12000 //defning our equation


    int main()
    {
    float xSUB0, xSUB1, xSUB2, f0, f1, f2, tolError, error;
    int iteration = 1;

    up: //with this part I had to ask my classmate what code function could let me repeat the selection process should it register an invalid input
        //but i couldnt get to use it in the other exercises and ran out of time

    printf("Pls provide two guesses [first the left hand bracket and second the right hand bracket]\n");
    printf("of the values that bracket the root of the equation:\n");
    scanf("%f%f", &xSUB0, &xSUB1);
    printf("Enter tolerable error:\n");
    scanf("%f", &tolError);


	 f0 = f(xSUB0);
	 f1 = f(xSUB1);

	 if( f0*f1 > 0.0)
	 {
		  printf("Wrong Guesses!\n");
		  goto up;
	 }
	 printf("\nITERATION No. \t\txSUB0\t\txSUB1\t\txSUB2\t\tf(xSUB2)\t\t\tError\n");
	 do
	 {
        xSUB2 = (xSUB0 + xSUB1)/2;
    //here we calculate the midpoint
    f2 = f(xSUB2);
        error = (xSUB1-xSUB0)/xSUB2;
    //error calculation

    printf("%d\t\t%0.4f\t\t%0.4f\t\t%0.4f\t\t%0.4f\t\t%0.4f\n",iteration, xSUB0, xSUB1, xSUB2, f2,error);

        if( f0 * f2 < 0){ //if the numbers are lesser than zero then the following process proceeds
        xSUB1 = xSUB2;
        f1 = f2;
        }
        else
        {
        xSUB0 = xSUB2;
        f0 = f2;}
    iteration = iteration + 1;
	 }
	 while(error>tolError);
	 printf("\n Root= %f", xSUB2);
	 getch(); /*The getch in C is a non-standard function used to receive a character as input from the user.
    It is defined in the header file conio.h The character entered by the user is not visible on the
    output screen but is stored in the assigned variable which makes this the best method for receiving
    passwords from a user. */

}
