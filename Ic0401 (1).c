//Ryu Ichiro R. Malaque
//3rd Year Aerospace Engineering
//Formative Assessment 4

#include<stdio.h>
#include<math.h>


//function for Gaussian elimination
void gaussEliminationLS(int m, int n, double a[m][n], double x[n-1]){
    int i,j,k;
    //for loop to iterate through each row
    for(i=0;i<m-1;i++){
        //finding the row with the largest value and swapping rows if necessary
        for(k=i+1;k<m;k++){
            if(fabs(a[i][i])<fabs(a[k][i])){
                //Swap the rows
                for(j=0;j<n;j++){
                    double temp;
                    temp=a[i][j];
                    a[i][j]=a[k][j];
                    a[k][j]=temp;
                }
            }
        }
        //performing Gaussian elimination
        for(k=i+1;k<m;k++){
            double  term=a[k][i]/ a[i][i];
            for(j=0;j<n;j++){
                a[k][j]=a[k][j]-term*a[i][j];
            }
        }

    }
    //back-substitution to obtain the solution
    for(i=m-1;i>=0;i--){
        x[i]=a[i][n-1];
        for(j=i+1;j<n-1;j++){
            x[i]=x[i]-a[i][j]*x[j];
        }
        x[i]=x[i]/a[i][i];
    }

}

//function to calculate the coefficients for cubic spline interpolation
void cSCoeffCalc(int n, double h[n], double sig[n+1], double y[n+1], double a[n], double b[n], double c[n], double d[n]){
    int i;
    //for loop to calculate coefficients a, b, c, and d for each interval
    for(i=0;i<n;i++){
        d[i]=y[i];
        b[i]=sig[i]/2.0;
        a[i]=(sig[i+1]-sig[i])/(h[i]*6.0);
        c[i]=(y[i+1]-y[i])/h[i]-h[i]*(2*sig[i]+sig[i+1])/6.0;
    }
}

//function to generate the tridiagonal matrix and right-hand side for the cubic spline interpolation
void tridiagonalCubicSplineGen(int n, double h[n], double a[n-1][n], double y[n+1]){
    int i;
    //for loop to fill the diagonal and off-diagonal elements of the matrix
    for(i=0;i<n-1;i++){
        a[i][i]=2*(h[i]+h[i+1]);
    }
    for(i=0;i<n-2;i++){
        a[i][i+1]=h[i+1];
        a[i+1][i]=h[i+1];
    }
    //for loop to fill the right-hand side vector
    for(i=1;i<n;i++){
        a[i-1][n-1]=(y[i+1]-y[i])*6/(double)h[i]-(y[i]-y[i-1])*6/(double)h[i-1];
    }
}

//function to print the matrix
void printMatrix(int m, int n, double matrix[m][n]){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%lf\t", matrix[i][j]);
        }
        printf("\n");
    }
}

//This function copies elements from matrix1 to matrix2
void copyMatrix(int m, int n, double matrix1[m][n], double matrix2[m][n]){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            matrix2[i][j]=matrix1[i][j];
        }
    }
}

//Main function starts here
main(){
    int m,i;
    printf("Enter the no. of data-points:\n");
    scanf("%d",&m);
    int n=m-1;  //Now (n+1) is the total no. of data-points, following our convention
    double x[n+1]; //array to store the x-axis points
    double y[n+1]; //array to store the y-axis points
    double h[n];   //array to store the successive interval widths
    printf("Enter the x-axis values:\n");
    for(i=0;i<n+1;i++){
        scanf("%lf",&x[i]);
    }
    printf("Enter the y-axis values:\n");
    for(i=0;i<n+1;i++){
        scanf("%lf",&y[i]);
    }
    for(i=0;i<n;i++){
        h[i]=x[i+1]-x[i];
    }
    double a[n]; //array to store the a
    double b[n]; //array to store the b
    double c[n]; //array to store the c
    double d[n]; //array to store the d
    double sig[n+1]; //array to store S
    double sigTemp[n-1]; //array to store the S except S0 and Sn
    sig[0]=0;
    sig[n]=0;
    //matrix that store the tridiagonal system of equations that will solve for S
    double tri[n-1][n]; 
    //to initialize tri[n-1][n]
    tridiagonalCubicSplineGen(n,h,tri,y); 
    printf("The tridiagonal system for the Natural spline is:\n\n");
    printMatrix(n-1,n,tri);
    //Applying Gauss Elimination
    gaussEliminationLS(n-1,n,tri,sigTemp);
    for(i=1;i<n;i++){
        sig[i]=sigTemp[i-1];
    }
    //Print the values of Si's
    for(i=0;i<n+1;i++){
        printf("\nSig[%d] = %lf\n",i,sig[i]);
    }
    //calculate the values of a, b, c, and d
    cSCoeffCalc(n,h,sig,y,a,b,c,d);
    printf("The equations of cubic interpolation polynomials between the successive intervals are:\n\n");
    for(i=0;i<n;i++){
        printf("P%d(x) b/w [%lf,%lf] = %lf*(x-%lf)^3+%lf*(x-%lf)^2+%lf*(x-%lf)+%lf\n",i,x[i],x[i+1],a[i],x[i],b[i],x[i],c[i],x[i],d[i]);
    }

    //Evaluation of x at any point in the piece-wise
    double var, fx, fdx;

    printf("Enter the value of x: ");
    scanf("%lf", &var);

    //for loops in applying the lowest and highest digit then applying the var (the value of x)
    //using the if nest, apply the value of x and using the equation within the range of the piecewise function one can attain the value
    for(i=0;i<n+1;i++){
        if(var>x[i] && var<x[i+1]){

            //the general equation of the function in its original form and in its first derivative form
            fx = a[i]*pow((var-x[i]),3)+b[i]*pow((var-x[i]),2)+c[i]*pow((var-x[i]),1)+d[i];
            fdx = a[i]*3*pow((var-x[i]),2)+b[i]*2*pow((var-x[i]),1)+c[i];

            printf("\nf(x) = %lf", fx);
            printf("\nf'(x) = %lf", fdx);
        }
    }

return 0;
}
