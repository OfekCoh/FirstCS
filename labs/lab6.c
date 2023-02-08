#include <stdio.h>

int devides (int a, int b) /* האם בי מחלק את איי */
{
    return (a%b==0)? 1 : 0;
}

int is_prime (int x) /* האם איקס מספר ראשוני */
{
    int i=0;
    if(x<0) return 0;
    for ( i=x-1 ; i>1 ; i--)
    {
        if(devides(x,i)==1) return 0; 
    }
    return 1;
}

int main()
{
    int num= -1;
    printf("Enter a positive number\n");
    do
    {
        if (scanf("%d" , &num)!=1) return 0;
        if(num<0)
        {
            printf("Enter a POSITIVE number:\n");
        }
    }
    while (num<0);    
    
    if(is_prime(num)==1)
        printf("Your number is primary.\n");
    else
    {
        printf("Your number isnt primary.\n");
    } 
    return 0;
} 

