#include <stdio.h>
#include <stdlib.h>

char * intToRoman(int num){
    int i=num,n=0,count=1;
    char* arr;
    while(i>=1)
    {
        if(i%10==1 || i%10==5) n++;
        if(i%10==2 || i%10==4 || i%10==9 || i%10==6 ) n+=2;
        if(i%10==3 || i%10==7) n+=3;
        if(i%10==8) n+=4;
        i/=10;
    }
    arr=(char*)malloc(n+1);
    arr[n--]='\0';
    while(n>=0)
    {
        if(num%10==1)
        {
            if(count==1) arr[n]='I';
            if(count==2) arr[n]='X';
            if(count==3) arr[n]='C';
            if(count==4) arr[n]='M';
            n--;
        }
        if(num%10==2)
        {
            if(count==1){ arr[n]='I'; arr[n-1]='I'; }
            if(count==2){ arr[n]='X'; arr[n-1]='X'; }
            if(count==3){ arr[n]='C'; arr[n-1]='C'; }
            if(count==4){ arr[n]='M'; arr[n-1]='M'; }
            n-=2;
        }
        if(num%10==3)
        {
            if(count==1){ arr[n]='I'; arr[n-1]='I'; arr[n-2]='I';}
            if(count==2){ arr[n]='X'; arr[n-1]='X'; arr[n-2]='X';}
            if(count==3){ arr[n]='C'; arr[n-1]='C'; arr[n-2]='C';}
            if(count==4){ arr[n]='M'; arr[n-1]='M'; arr[n-2]='M';}
            n-=3;
        }
        if(num%10==4)
        {
            if(count==1){ arr[n]='V'; arr[n-1]='I'; }
            if(count==2){ arr[n]='L'; arr[n-1]='X'; }
            if(count==3){ arr[n]='D'; arr[n-1]='C'; }
            n-=2;
        }
        if(num%10==5)
        {
            if(count==1) arr[n]='V';
            if(count==2) arr[n]='L';
            if(count==3) arr[n]='D';
            n--;
        }
        if(num%10==6)
        {
            if(count==1){ arr[n]='I'; arr[n-1]='V';}
            if(count==2){ arr[n]='X'; arr[n-1]='L';}
            if(count==3){ arr[n]='C'; arr[n-1]='D';}
            n-=2;
        }
        if(num%10==7)
        {
            if(count==1){ arr[n]='I'; arr[n-1]='I'; arr[n-2]='V';}
            if(count==2){ arr[n]='X'; arr[n-1]='X'; arr[n-2]='L';}
            if(count==3){ arr[n]='C'; arr[n-1]='C'; arr[n-2]='D';}
            n-=3;
        }
        if(num%10==8)
        {
            if(count==1){ arr[n]='I'; arr[n-1]='I'; arr[n-2]='I'; arr[n-3]='V';}
            if(count==2){ arr[n]='X'; arr[n-1]='X'; arr[n-2]='X'; arr[n-3]='L';}
            if(count==3){ arr[n]='C'; arr[n-1]='C'; arr[n-2]='C'; arr[n-3]='D';}
            n-=4;
        }
        if(num%10==9)
        {
            if(count==1){ arr[n]='X'; arr[n-1]='I';}
            if(count==2){ arr[n]='C'; arr[n-1]='X';}
            if(count==3){ arr[n]='M'; arr[n-1]='C';}
            n-=2;
        }
        count++;
        num/=10;
    }
    return arr;
}

int main()
{
    int x=1997;
    printf("Roman num is: %s", intToRoman(x));
    return 0;
}