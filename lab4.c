/* משחק בול פגיעה */
#include <stdio.h>
int main(){
    int a , b , c, d, win=0 , start=0, aa , bb , cc , dd , strike=0 , hit=0 , round=1;
/* get the code*/
    printf("Enter 4 different digits: ");
    while (start==0)
    {
        if(scanf("%d %d %d %d" ,&a,&b,&c,&d) != 4 ) return 0; 

        if((a>9 || a<0) || (b>9 || b<0) || (c>9 || c<0) || (d>9 || d<0))
        {
            printf("Invalid input. You must enter digits.\nEnter 4 different digits: ");  
        }
        else if (a==b || a==c || a==d || b==c || b==d || c==d ) 
        {
            printf("Invalid input. The digits must not be equal.\nEnter 4 different digits: ");
        }
        else
        {
            start++;
        }       
    }
/* start of the game- check the code*/
    printf("*********** Game Starts **************\n");  
    printf("Guess the code: ");
    while (win==0)
    {
        if(scanf("%d %d %d %d" ,&aa,&bb,&cc,&dd) != 4 ) return 0; 

        if((aa>9 || aa<0) || (bb>9 || bb<0) || (cc>9 || cc<0) || (dd>9 || dd<0))
        {
            printf("Invalid input. You must enter digits.\nGuess the code: ");  
        }
        else if (aa==bb || aa==cc || aa==dd || bb==cc || bb==dd || cc==dd ) 
        {
            printf("Invalid input. The digits must not be equal.\nGuess the code: ");
        }
        else if(aa==a && bb==b && cc==c && dd==d)
        { 
            win++;
            printf("Congratulations! You have guessed the code after %d rounds.", round);
        }
        else
        {   
            hit=0;
            strike=0;
            if(aa!=a && (aa==b || aa==c || aa==d)) strike +=1;
            if((bb==a || bb==d || bb==c) && bb!=b) strike +=1;
            if((cc==a || cc==b || cc==d) && cc!=c) strike +=1;
            if((dd==a || dd==b || dd==c) && dd!=d) strike +=1;
            if(aa==a) hit +=1;
            if(bb==b) hit +=1;
            if(cc==c) hit +=1;
            if(dd==d) hit +=1;
            round += 1;
            printf("You have %d hits and %d strikes\nGuess the code: ", hit , strike);        
        }
    }
    return 0;
}