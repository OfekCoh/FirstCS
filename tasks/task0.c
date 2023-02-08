/* count characters */
#include <stdio.h>
int main()
{
    long counter=0;
    char c;
    while( scanf(" %c", &c)!=EOF ) /* press ctrl Z to stop */
    {
        counter++;
    }
    printf("The number of charachters is: %ld",counter);
    return 0;
}