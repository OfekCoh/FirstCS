#include <stdio.h>
#define N 3
void vector_operations (double* a, double* b, double* sum, double* product) 
{
    int i=0;
    for (i=0; i<N; i++)
    {
        sum[i] = a[i]+b[i] ;
        *product+=a[i]*b[i];    
    }
    

}

int checkSuffix (char a[], char b[], int sizea , int sizeb) 
{
    int i=2;
    while(i<=3)
    {
        if((b[sizeb-i])==(a[sizea-i])) i++;
        else return 0;
    }
    return 1;
}

int main()
{
    char a[]= "abc" ,b[]="bc";   
    printf("%d", checkSuffix(a,b, 4, 3) );
    return 0;
}