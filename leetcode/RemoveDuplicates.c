int removeDuplicates(int* nums, int numsSize){
    int index = 0;
    for(int i = 1; i < numsSize; i++)
    {
        if(nums[index] != nums[i])
        {
            index++;
            nums[index] = nums[i];
        }
    }
    return index + 1;
}



int removeElement(int* arr, int size, int x){
    int i=0,j=0,temp,k=0;
    for(j=0;j<size;j++)
    {
        if(arr[j]!=x)
        {
            k++;
            if(j==i) i++;
            else arr[i++]=arr[j];
        }    
    }
    return k;
}