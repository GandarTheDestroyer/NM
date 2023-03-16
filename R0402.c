
/**JAMES ALEXIS REALUYO
BS AEROSPACE ENGINEERING 3A
MODULE 4:
FORMATIVE ASSESSMENT 04
EXERCISE 2
**/
#include<stdio.h>
#include<math.h>

void gaussElimination(int m, int n, double a[m][n], double x[n-1]){ //x and a defined as double
    int i,j,k; //we define i j k as integers
    for(i=0;i<m-1;i++){
        //Partial Pivoting
        for(k=i+1;k<m;k++){
            //If diagonal element(absolute vallue) is smaller than any of the terms below it
            if(fabs(a[i][i])<fabs(a[k][i])){
                //Swap the rows
                for(j=0;j<n;j++){
                    double temp; // defining temp (temporary) double
                    temp=a[i][j];
                    a[i][j]=a[k][j];
                    a[k][j]=temp;
                }
            }
        }
        //Begin Gauss Elimination
        for(k=i+1;k<m;k++){
            double  term=a[k][i]/ a[i][i]; // for each element its defined double
            for(j=0;j<n;j++){
                a[k][j]=a[k][j]-term*a[i][j];
            }
        }

    }

    for(i=m-1;i>=0;i--){ //this section starts the substitution
        x[i]=a[i][n-1];
        for(j=i+1;j<n-1;j++){
            x[i]=x[i]-a[i][j]*x[j];
        }
        x[i]=x[i]/a[i][i];
    }

}

void cSCoeffCalc(int n, double h, double sig[n+1], double y[n+1], double a[n], double b[n], double c[n], double d[n]){ //this section computes the coefficients
    int i;
    for(i=0;i<n;i++){
        d[i]=y[i];
        b[i]=sig[i]/2.0; //sig is the signal number to which  a handling function is set
        a[i]=(sig[i+1]-sig[i])/(h*6.0);
        c[i]=(y[i+1]-y[i])/h-h*(2*sig[i]+sig[i+1])/6.0;
    }
}



void tridiagonalCubicSplineGen(int n, double h, double a[n-1][n], double y[n+1]){ //this function to generate the tridiagonal augmented matrix for cubic spline for equidistant data-points
    int i;
    for(i=0;i<n-1;i++){
        a[i][i]=4;
    }
    for(i=0;i<n-2;i++){
        a[i][i+1]=1;
        a[i+1][i]=1;
    }
    for(i=0;i<n-1;i++){
        a[i][n-1]=(y[i+2]-2*y[i+1]+y[i])*6/h/h;
    }
}


void printMatrix(int m, int n, double matrix[m][n]){ //this function prints the elements of a matrix
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%lf\t",matrix[i][j]);
        }
        printf("\n");
    }
}


void copyMatrix(int m, int n, double matrix1[m][n], double matrix2[m][n]){ /*Function that copies the elements of a matrix to another matrix*/
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            matrix2[i][j]=matrix1[i][j];
        }
    }
}
 int main(){//main function
    int m,i; //define m i as double
    printf("Input the no. of data-points:\n"); //prompts user to input how many data points is given
    scanf("%d",&m);
    int n=m-1;  //n+1 total no. of data-points
    double x[n+1];
    double y[n+1];
    printf("x-axis values. Please make sure to separate each number with a space:\n");
    for(i=0;i<n+1;i++){
        scanf("%lf",&x[i]);
    }
    printf("y-axis values. Please make sure to separate each number with a space:\n");
    for(i=0;i<n+1;i++){
        scanf("%lf",&y[i]);
    }
    double h=x[1]-x[0]; //space interval
    double a[n];
    double b[n];
    double c[n];
    double d[n];
    double sig[n+1];
    double sigTemp[n-1];
    sig[0]=0;
    sig[n]=0;
    double tri[n-1][n];

    //Here we perform Gauss Elimination
    gaussElimination(n-1,n,tri,sigTemp);
    for(i=1;i<n;i++){
        sig[i]=sigTemp[i-1];
    }
    for(i=0;i<n+1;i++){
        printf("\na[%d] = %lf\n",i,sig[i]);
    }
    cSCoeffCalc(n,h,sig,y,a,b,c,d);
    printf("Equations between the successive intervals are:\n\n");
    for(i=0;i<n;i++){
        printf("P%d(x) b/w [%lf,%lf] = %lf*(x-%lf)^3+%lf*(x-%lf)^2+%lf*(x-%lf)+%lf\n",i,x[i],x[i+1],a[i],x[i],b[i],x[i],c[i],x[i],d[i]);
    }


}
