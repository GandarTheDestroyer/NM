//Franz Joseph D. Tinapay BS-ASE 3A

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Quadratic Spline interpolation
 main()

 {
    int rows;
    printf("Enter the number of rows for your table: "); //asks for the value of rows.
    scanf("%d", &rows);
    float table[rows][2];

    // Get values for each row in the table
    for (int i = 0; i < rows; i++) {
        printf("Enter the value for X%d: ", i+1); //a simple array with two columns.
        scanf("%f", &table[i][0]);
        printf("Enter the value for Y%d: ", i+1);
        scanf("%f", &table[i][1]);
    }

    // Prints the table
    printf("\nYour table:\n");

    for (int i = 0; i < rows; i++)
    {
        printf("%.4f\t%.4f\n", table[i][0], table[i][1]);
    }

    printf("\n\n");

    //The start of the algorithm used. Please refer to the PDF attachment for the explaination.
    float z0 = 0; //the value of Z0 can be given or assumed. For this case, it was assumed as zero.
    float ztable[rows-1]; //a new array with one column was deemed necessary to store the values of the Z to call on later

    for (int ctr = 0; ctr <= (rows-1); ctr++) //loop for computaion and storage of values
    {

        float z = (z0*-1) + 2.0 *( ((table[ctr + 1][1]) - (table[ctr][1])) / ((table[ctr + 1][0]) - (table[ctr][0]))); //formula of Z
        z0 = z;

        ztable[0] = 0; //was assumed zero
        ztable[ctr+1] = z; //stores the z values here

        //printf("\n");
        //printf(" %.4f", ztable[ctr]);
        //printf("\n");

    }
    //arrays for storage of values.
    float huh11[rows-1];
    float t[rows-1];
    float ze[rows-1];
    float huh22[rows-1];

    //still part of the solving based on the algorithm

    for (int ctr = 0; ctr < (rows-1); ctr++ )

   {
        //q = (((ztable[ctr+1]) - (ztable[ctr])) / 2 * ((table[ctr+1][0])-(table[ctr][0]))) * (x - table[ctr][0])^2 + (ztable[ctr](x - table[ctr][0])) + (table[ctr][1])
       float huh1 = ((ztable[ctr+1]) - (ztable[ctr])) / ( 2 * (table[ctr+1][0] - table[ctr][0])); // first chunk of equation.
       float huh2 = (table[ctr][1]); // last chunk
       huh11[ctr] = huh1; //stores the values. I guess i found this more practical to do since i can just summon them knowing their locations to perform the necessary mathematical operations during the evaluation
       t[ctr] = table[ctr][0]; //same here
       ze[ctr] = ztable[ctr];//and here and below
       huh22[ctr]= huh2;



        printf("For ranges %.4f to %.4f, use this equation: ",table[ctr][0],table[ctr+1][0]); //prints the ranges
       printf("f(x)=(%.4f)(x - %.4f)^2 + %.4f(x - %.4f) + %.4f \n",huh1,table[ctr][0],ztable[ctr],table[ctr][0],huh2); //prints the equation


   }

   //evaluation
   float num;
   float y;
   float dy;
   printf("\n\n\n\n");
   printf("Enter a number of x that you want to evaluate: ");scanf(" %f", &num); //asks for the number or value of x to be evaluated

   for (int ctr = 0; ctr <= rows; ctr++ ) //loop for the summoning of values from their stored location.

   {
       if(  (table[ctr][0]<= num)&& (table[ctr+1][0]>= num) )//determines the range and equation to be used based on the given condition
       {
           y =  ((huh11[ctr]) * (num - t[ctr])*(num - t[ctr])) + ( ze[ctr] * (num - t[ctr])) + ( huh22[ctr]); // operation for evaluation
         dy =  ((huh11[ctr]) * 2 * (num - t[ctr])) + (ze[ctr]); //the derivative of y
           break; //necessary to break the loop when the if statement is already satisfied
       }

   }

   printf("\n\n"); // prints the values of y and y'
   printf("When X = %.4f, Y = %.4f \n",num,y);
    printf("When X = %.4f, Y'= %.4f",num,dy);





    return 0;
}
