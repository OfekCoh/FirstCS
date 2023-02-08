double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int i=0,j=0,k=0;
    double mid;
    int n=nums1Size+nums2Size;
    int* arr=(int*)malloc(n*sizeof(int));
    while( i<nums1Size && j<nums2Size)
    {
        if(nums1[i]>nums2[j]) arr[k++]=nums2[j++];
        else arr[k++]=nums1[i++]; 
    }
    while(i<nums1Size) arr[k++]=nums1[i++];
    while(j<nums2Size) arr[k++]=nums2[j++];
    if(n%2==0)
    {
        k=(arr[n/2]+arr[(n/2)-1]);
        mid=(double)k/2;
        free(arr);
        return mid;
    }
    mid=arr[n/2];
    free(arr);
    return mid;
}