#include <stdio.h>
#define LENGTH 30

/* Declerations */
void get_num(int* num);
void play_game(char** players, int gift, int len);
int countStudent(int gift, int len); /* help func- counts which student selects a gift */
void move2end(char** arr, int len); /* help fun- moving the student to the end */

int main()
{
	int gift, i;
    char* players [LENGTH]= {"Alex", "Sami", "Nour", "Chen", "Elon", "Wilhelm", "Daniel", "Ariel", "Neta", "Maggie", "Rania", "Nancy", "Hadar", "Sandra",
                            "Adham", "Dominique", "Rami", "Dua", "Yarden", "Loulou", "Zohar", "Simon", "Gabi", "Tal", "Val", "Sara", "Rand", "Yossi", "Yara",
                            "Angel"
                            };
    get_num(&gift);
    if(gift==-1) return 1;
    play_game(players, gift, LENGTH);
	printf("The players order after playing the game is: \n");
    for(i=0; i<LENGTH-1; i++)
    {
        printf("%s, ",*(players+i));
    }
    printf("%s.\n",*(players+(LENGTH-1)));
    return 0;
}

void get_num(int* num)
{
    printf("Enter a positive number: ");
    if (scanf("%d", num)<1 || (*num)<=0)
    {
        printf("Input error\n");
        *num = -1;
    }
}

void play_game(char** players, int gift, int len)  
{
    int k;
    if(len==1) return; /* exit condition */
    for( k=0; k<=(countStudent(gift,len)) ; k++ ) move2end(players, len); /* the student that chose a gift moves to the end with all his buddies before him */
    play_game(players, gift, len-1); /* the recursive call */
}

void move2end(char** arr, int len) /* help fun- moving the student to the end */ 
{
    int i, j;
    char* temp;
    for(i=0, j=1; j<len; i++, j++)
    {
        temp=*(arr+i);
        *(arr+i)=*(arr+j);
        *(arr+j)=temp;
    }
}

int countStudent(int gift, int len) /* help func- counts which student selects a gift */
{
    return (gift%len==0) ? (len-1) : ((gift%len)-1); /* calculating the count */
}