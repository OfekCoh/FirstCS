#include <stdio.h>
int main()
{
    /*declaring variables for assignment 1*/
    int num=0,last1,last2,cnt=0;
    /*declaring variables for assignment 2*/    
    int i, pointr=0 , pointl=0 , rounds;
    char left, right;
    
    /*Assignment 1*/    
    /*checking user's input*/
    printf("Please enter the last two values in the sequence: \n");
    if (scanf("%d%d" ,&last1,&last2)!=2)
    { 
        printf("ERROR \n");
    }
    else if (last1<=0 || last2<=0) 
    {
        printf("You have entered a negative/zero value \n");
    }
    else 
    {
    /*making sure last2 is always bigger*/
        if (last1>last2)
        {
            num= last1;
            last1=last2;
            last2= num;
        }
    /*loop to find previous values until finding the last 2 values*/
        while ((last2-last1)>0 && (last2-last1)<=last1 )
        {
            num = last2;
            last2=last1;
            last1=num-last2;
            cnt++;
        }
        if(((last2-last1)>=last1) && (cnt!=0)) cnt++; /* making sure the contradiction counts as a step */
        /*print first two values in the sequence*/
        printf ("first in sequence is %d second is %d and number of steps is %d \n",last1, last2,cnt);
    }
    printf("--------------------------------------------------------------\n");
    /*Assignment 2- ROCK PAPER SCISSORS */
    printf("Part two of the homework\n");
    printf("--------------------------------------------------------------\n");
    /*check number of rounds*/
    printf("enter number of rounds and hands after all in a row:\n");
    if(scanf("%d", &rounds)!=1)
    {
        printf("ERROR\n");
        return 0;
    }
    if(rounds<=0)
    {
        printf("You have entered a negative/zero value\n");
        return 0;
    }
        
    /* check their hands */
    for( i=0 ; i<rounds ; i++)
    {
        if(scanf(" %c %c" , &left, &right)!=2) /* making sure input is valid*/
        {
            printf("ERROR\n");
            return 0;
        }
        if(((left!='R')&&(left!='S')&&(left!='P'))||((right!='R')&&(right!='S')&&(right!='P'))) /*making sure its R/S/P*/
        {
            printf("ERROR\n");
            return 0;
        }
        if(left==right)
        {
            pointr++;
            pointl++;
        }
        else if ((left=='R' && right=='S') || (left=='P' && right=='R') || (left=='S' && right=='P'))
        {
            pointl++;
        } 
        else
        {
            pointr++;
        }            
    }
    if(pointr>pointl) /* calculating whos the winner */
    {
        printf("winner is R\n");
    }
    else if(pointr==pointl)
    {
        printf("No winner\n");
    }
    else
    {
        printf("winner is L\n");
    }
        
    return 0;
}