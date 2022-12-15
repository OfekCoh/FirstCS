#include <stdio.h>
#define MAX 100

/* Function declerations here */
int getArray(int arr[], int len); /* mission 1- getArray */
void polynomialCalc(int p,  int d, int polr[], int coeff[]); /* mission 2- polynomialCalc */
void minPlusConv(int p, int len, int a[], int b[], int c[]); /* mission 3- minPlusconv */
int power(int base, int power); /* func that calculates the power of */
int modolo(int num, int p); /* func that calculates modolo*/
int max(int num1, int num2); /* func that calculates max of 2 numbers */
int min(int num1, int num2); /* func that calculates min of 2 numbers */

/** print functions **/
void printPoly(int a[], int s, char name[]);
void printArr(int a[], int s, char name[]);


int main()
{
    int coeff [MAX]= {0};
    int polr [MAX]= {0};
    int c [MAX]= {0};
    int d,p;

    /*Get Input (polynomial coefficients)*/
    printf("Please enter degree of the polynomial:\n");
    if(scanf("%d", &d)<1) return 1;
    printf("Please enter p:\n");
    if(scanf("%d", &p)<1) return 1;
    printf("Please enter the coefficients of your polynomial:\n");
    if(!getArray(coeff, d+1)) return 1;
    printf("\nThe given polynomial is:\n");
    printPoly(coeff,d+1,"Poly");

    /*Calculate Polynomial*/
    polynomialCalc( p, d, polr, coeff);
    printf("\nThe result of Poly(x) on all 0<=x<p=%d is:\n",p);
    printArr(polr,p,"Polynomial result");

    /*Calculate Min Plus Convolution between the arrays: a=coeff and b=polr and put result in c*/
    minPlusConv(p, d+1, coeff, polr, c);
    printf("\nThe Minimum Plus Convolution of a and b is:\n");
    printArr(c,((d+1>p)?d+1:p),"c");

    return 0;
}


/* mission 1- getArray */
int getArray(int arr[MAX], int len)
{
    int i; /* for the loop */
    for (i=0 ; i<len ; i++) /* loop to scanf the array */
    {
        if(scanf("%d", arr+i) !=1) return 0; /* scan failed */ /* can also do &arr[i] "*/
    }
    return 1; /* scan was succesful*/
}

/* mission 2- polynomialCalc */
void polynomialCalc(int p,  int d, int polr[MAX], int coeff[MAX])
{
    int i, j, sum; /* for the loops */
    for(i=0; i<p ; i++)
    {
        sum=0; /* restarting sum to 0 for each i */
        for(j=0; j<=d; j++) 
        {
            sum += coeff[j]*power(i, j); /* calculating the result into sum */
        }
        polr[i]= modolo(sum, p); /* inserting modolo the result into the array */
    }
}

/* mission 3- minPlusconv */
void minPlusConv(int p, int len, int a[MAX], int b[MAX], int c[MAX])
{
    int i, j, k; /*  indexs for the loops*/
    int r= max(p,len); /* as the mission stated for r */
    for( i=0 ; i<r ; i++ )
    {
        if(i==0) c[i]= modolo( (a[i]+b[i]) , p ); /* if i==0 theres only one option */
        else
        {
        c[i]= p+1; /* making sure the undefined value wont be smaller than the res */
            for( j=0 ; j<len ; j++ ) /* checking all indexs in array a (a[j]) */
            {
                for( k=0 ; k<p ; k++ ) /* checking the same a[j] for all indexs in array b (b[k]) */
                {
                    if((j+k)==i) /* j+k must be equale to i */
                        c[i]= min( c[i] , (modolo((a[j]+b[k]),p)) ); /* switching c[i] only if the result is smaller than the current c[i] */ 
                }
            }
        }
    }
}

/* func that calculates the power of */
int power(int base, int power)
{
    int i, sum=base;
    if(power==0) return 1; /* anything to the power of 0 is 1 */
    for (i=1; i<power; i++)
    {
        sum*= base;
    }
    return sum;
}

/* func that calculates modolo*/
int modolo(int num, int p)
{
    return (num<0)? num%p+p : num%p; /* modolo is always positive */
}

/* func that calculates max of 2 numbers */
int max(int num1, int num2)
{
    return (num1<num2)? num2 : num1;
}

/* func that calculates min of 2 numbers */
int min(int num1, int num2)
{
    return (num1<num2)? num1 : num2;
}

/** print functions **/
void printArr(int a[], int s, char name[])
{
    int i;
    printf("%s=[", name);
    for(i=0; i<s-1; i++)
    {

        printf("%d,", a[i]);
    }
    printf("%d]\n", a[i]);
}

void printPoly(int a[], int s, char name[])
{
    int i=0;
    if(s<1) return;
    printf("%s(x)=", name);
    printf("%d", a[i]);
    for(i=1; i<s; i++)
    {
        if(a[i]<0)
            printf("+(%d)x^%d", a[i], i);
        else
            printf("+%dx^%d", a[i], i);
    }
    printf("\n");
}