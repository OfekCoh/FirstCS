int strStr(char * arr, char* a)
{
    int i=0,j=0,flag=0,next=0;
    if(strlen(a)==0) return 0;
    if(strlen(arr)<strlen(a)) return -1;
    while(arr[i])
    {
        if(arr[i]!=a[j])
        {
            if(flag==1)
            {
                flag=0;
                i=next-1;
            }
            else if(arr[i]==a[0] && j!=0) i--;
            j=0;
        }
        else
        {
            if(j!=0 && arr[i]==a[0] && flag==0)
            {
                next=i;
                flag=1;
            }
            if(a[j+1]=='\0') return i-j;
            j++;
        }
        i++;
    }
    return -1;
}