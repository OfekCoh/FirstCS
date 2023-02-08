#include <stdio.h>
#include <stdlib.h>

void printWorld(char** array, int worldDim, int i, int j); /* print the matrix */
void freeMemory(char** array, int worldDim, int i, int j); /* free memory */
void nextGen(char** array, char direction, int worldDim, int i, int j); /* changes world to next generation */

int main()
{
    char** array;
    char direction;
    int genNum, worldDim, i,j;
    
    printf("Enter number of generations: \n"); 
    if(scanf("%d", &genNum)!=1)                       /* 1/4 scan genNum */
    {
        printf("Input error!");
        return 0;
    }
    printf("Enter world dimension: \n");
    if(scanf("%d", &worldDim)!=1)                     /* 2/4 scan worldDim */
    {
        printf("Input error!");
        return 0;
    }
    printf("Enter effect direction: \n");
    getchar(); /* absorb the Enter */
    if(scanf("%c", &direction)!=1)                    /* 3/4 scan direction */
    {
        printf("Input error!");
        return 0;
    }
    printf("Enter first generation: \n");
    array=(char**)malloc(worldDim*(sizeof(char*)));
    if(array==NULL)
    {
        printf("Memory error!");
        return 0;
    }
    for(i=0; i<worldDim; i++) /* make 2d array */
    {
        array[i]= (char*)malloc(worldDim);
        if(array[i]==NULL)
        {
            printf("Memory error!");
            return 0;
        }
    }
    for(i=0;i<worldDim;i++) /* scanf the matrix */
    {
        for(j=0;j<worldDim;j++)
        {
            if(scanf(" %c", &array[i][j])!=1)         /* 4/4 scan matrix input  */
            {
                printf("Input error!");
                return 0;
            }
        }
    } 
    printWorld(array,worldDim,i,j); /* print the matrix for the first time */
    for( i=0 ; i<genNum-1 ; i++ ) /* change world to next gennerations and print it */
    { 
        nextGen(array, direction, worldDim, i, j); 
        printWorld(array,worldDim,i,j); 
    }
    freeMemory(array,worldDim,i,j); /* free memory */
    return 0;
} 

void freeMemory(char** array, int worldDim, int i, int j) /* free memory */
{
    for(i=0;i<worldDim;i++) 
    {
        free(array[i]);
    }
    free(array);
}

void printWorld(char** array, int worldDim, int i, int j) /* print the matrix */
{
    printf("\n");
    for(i=0;i<worldDim;i++) 
    {
        for(j=0;j<worldDim;j++)
        {
            printf("%c", array[i][j]);
        }
        printf("\n");
    }
}

void nextGen(char** array, char direction, int worldDim, int i, int j) /* changes world to next generation */
{
    int count, i2, j2; /* indexes for loops */
    char** originalWorld;
    originalWorld=(char**)malloc(worldDim*sizeof(char*)); /* make a new copy matrix */
    if(originalWorld==NULL) printf("Memory error!");
    for(i=0; i<worldDim; i++) /* make 2d array */
    {
        originalWorld[i]= (char*)malloc(worldDim);
        if(originalWorld[i]==NULL) printf("Memory Error");
    }
    for(i=0; i<worldDim; i++) /* copy the original matrix */
    {
        for(j=0;j<worldDim; j++)
        {
            originalWorld[i][j]= array[i][j];
        }
    }
    for(i=0; i<worldDim; i++) /* change N to B if needed */
    {
        for(j=0;j<worldDim; j++)
        {
            if(originalWorld[i][j]=='N')
            {
                if(direction=='U')
                {
                    for(i=1; i<worldDim; i++) /* no need for first row */
                    {
                        for(j=0;j<worldDim; j++)
                        {
                            if(originalWorld[i][j]=='B') array[i-1][j]='B'; /* up is changed */
                        }
                    }
                }
                if(direction=='D')
                {
                    for(i=0; i<worldDim-1; i++) /* no need for last row */
                    {
                        for(j=0;j<worldDim; j++)
                        {
                            if(originalWorld[i][j]=='B') array[i+1][j]='B'; /* down is changed */
                        }
                    }
                }
                if(direction=='L')
                {
                    for(i=0; i<worldDim; i++) 
                    {
                        for(j=1;j<worldDim; j++) /* no need for first col */
                        {
                            if(originalWorld[i][j]=='B') array[i][j-1]='B'; /* left is changed */
                        }
                    }
                }
                if(direction=='R')
                {
                    for(i=0; i<worldDim; i++) 
                    {
                        for(j=0;j<worldDim-1; j++) /* no need for last col */
                        {
                            if(originalWorld[i][j]=='B') array[i][j+1]='B'; /* right is changed */
                        }
                    }
                }
            }
        }
    }
    for(i=0; i<worldDim; i++) /* change B to D if needed */
    {
        for(j=0;j<worldDim; j++)
        {
            if(originalWorld[i][j]=='B')
            {
                if( (i==0 && j==0) || (i==0 && j==worldDim-1) || (i==worldDim-1 && j==0) || (i==worldDim-1 && j==worldDim-1)) ; /* dont need to check corners*/
                else
                {
                    if(i==0) /* check first row */
                    {
                        count=0;
                        for(i2=i;i2<=1;i2++)
                        {
                            for(j2=j-1; j2<=j+1 ;j2++)
                            {
                                if(originalWorld[i2][j2]=='B') count++ ;
                            }
                        }
                        if(count>4) array[i][j]='D';
                    }
                    else if(i==worldDim-1) /* check last row */
                    {
                        count=0;
                        for(i2=i-1;i2<=i;i2++)
                        {
                            for(j2=j-1; j2<=j+1 ;j2++)
                            {
                                if(originalWorld[i2][j2]=='B') count++ ;
                            }
                        }
                        if(count>4) array[i][j]='D';
                    }
                    else if(j==0) /* check first col */
                    {
                        count=0;
                        for(i2=i-1;i2<=i+1;i2++)
                        {
                            for(j2=j; j2<=j+1 ;j2++)
                            {
                                if(originalWorld[i2][j2]=='B') count++ ;
                            }
                        }
                        if(count>4) array[i][j]='D';
                    }
                    else if(j==worldDim-1) /* check last col */
                    {
                        count=0;
                        for(i2=i-1;i2<=i+1;i2++)
                        {
                            for(j2=j-1; j2<=j ;j2++)
                            {
                                if(originalWorld[i2][j2]=='B') count++ ;
                            }
                        }
                        if(count>4) array[i][j]='D';
                    }
                    else /* check the middle */
                    {
                        count=0;
                        for(i2=i-1 ;i2<=i+1 ;i2++)
                        {
                            for(j2=j-1; j2<=j+1 ;j2++)
                            {
                                if(originalWorld[i2][j2]=='B') count++ ;
                            }
                        }
                        if(count>4) array[i][j]='D';
                    }
                }
            }
        }
    }
    for(i=0; i<worldDim; i++) /* change D to N */
    {
        for(j=0;j<worldDim; j++)
        {
            if(originalWorld[i][j]=='D') array[i][j]='N';
        }
    }
    freeMemory(originalWorld,worldDim,i,j); /* free memory */
}