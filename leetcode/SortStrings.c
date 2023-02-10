#include <stdio.h>
#define MAX 50

int strlen1(char* arr)
{
    int i=0,count=0;
    while(arr[i])
    {
        count++;
        i++;
    }
    return count;
}

void counting_sort(char** arr, int n) 
{
    int i=0,j=0,k=0;
    char* temp;
    int cnt[MAX]={0};
    for(i=0;i<n;i++) cnt[strlen1(arr[i])]++;  /* o(n) */
    for(i=0;i<MAX;i++)   /* o(1) - max is defined */
    {
        while(cnt[i]!=0)  /* ? */
        {
            if(strlen1(arr[j])==i)
            {
                cnt[i]--;
                j++;
            }
            else
            {
                temp=arr[j];
                for(k=j+1;k<n;k++)  /* ? */
                {
                    if(strlen1(arr[k])==i)
                    {
                        arr[j]=arr[k];
                        arr[k]=temp;
                        j++;
                        cnt[i]--;
                    }
                }
            }
        }
    }
}

int main() {
    char* arr[6] = {"so", "many", "books,", "so", "little", "time."};
    counting_sort(arr, 6);
    for (int i = 0; i < 6; i++)
    printf("%s\n", arr[i]);
    return 0;
}





