#include <stdio.h>
#include <stdlib.h>

int** ar(int* A, int n)
{
    if(n<1) return NULL;
    int i=0;
    int** list=(int**)malloc(n*sizeof(int*));
    int* cnt=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++) list[i]=NULL;
    for(i=0;i<n;i++) cnt[i]=0;
    for(i=0;i<n;i++) cnt[A[i]]++;
    for(i=0;i<n;i++)
    {    
        if(cnt[i]!=0)  list[i]=(int*)malloc(sizeof(int)*cnt[i]);
    }
    for(i=n-1;i>=0;i--)
    {
        list[A[i]][cnt[A[i]]-1]=i;
        cnt[A[i]]--;
    }
    free(cnt);
    return list;
}

int main()
{
    int arr[8]={2,3,5,5,2,2,1,3};
    int** list;
    list=ar(arr,8);
    printf("%d", list[1][0]);
    printf("\n");
    printf("%d", list[2][0]);
    printf("%d", list[2][1]);
    printf("%d", list[2][2]);
    printf("\n");
    printf("%d", list[3][0]);
    printf("%d", list[3][1]);
    printf("\n");
    printf("%d", list[5][0]);
    printf("%d", list[5][1]);
    return 0;
}
