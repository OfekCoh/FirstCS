/* different assigments- read last printf in each */
#include <stdio.h>
int main(){
    int sum, n, N;
    char p, m;
    double i, Z, x, d, A, V, T ,D;
    float G; 

printf ("-------------------1-------------------\n");
printf("Please enter the velocity in km/h:\n");
if(scanf("%lf", &V) == 0) return 0;
printf("Please enter the time in minutes:\n");
if(scanf("%lf", &T) == 0) return 0;
D= V*(T/60);
printf("The distance is %f km.\n", D );

/* second assigment*/
printf("---------------------------------------\n");
printf("-------------------2-------------------\n");


printf("Please enter the current number of followers:\n");
if(scanf("%d" , &N) == 0) return 0;
printf("Please enter the growth rate:\n");
if(scanf("%f" , &G) == 0) return 0;
sum= N*((1+G)*(1+G)*(1+G)*(1+G));
printf("The number of followers after 4 months is %d.\n", sum);

/* third assigment*/
printf("---------------------------------------\n");
printf("-------------------3-------------------\n");

printf("Please enter the initial velocity in m/s:\n");
if (scanf("%lf", &Z)== 0) return 0;
printf("Please enter the distance in meters:\n");
if (scanf("%lf", &d)== 0) return 0;
printf("Please enter the time in seconds:\n");
if (scanf("%lf", &x)== 0) return 0;
A= (2*(d-(Z*x)))/(x*x);
printf("The acceleration is %f m/s^2.\n" ,A );

/* fourth assigment*/
printf("---------------------------------------\n");
printf("-------------------4-------------------\n");


printf("Please enter a real number:\n");
if (scanf("%lf", &i)==0) return 0;
if( (i-(int)i)>= 0.5 ){
    n= i+1;
    printf("The rounded number is %d.\n" , n);}
if( (i-(int)i)< 0.5 ){
    n= i;
    printf("The rounded number is %d.\n" , n);}

/* fifth assigment*/
printf("---------------------------------------\n");
printf("-------------------5-------------------\n");

printf("Please enter a small letter:\n");
if(scanf(" %c", &m)==0) return 0;
m= m - 'a' + 'A';
printf("The letter in the upper case is %c.\n", m); 

/* sixth assigment*/
printf("---------------------------------------\n");
printf("-------------------6-------------------\n");

printf("Please enter a capital letter:\n");
if(scanf(" %c", &p)==0) return 0;
p= p - 'A' + 'a';
printf("The letter in the lower case is %c.\n", p); 

printf("---------------------------------------\n");

return 0;
}