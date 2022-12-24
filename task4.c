#include <stdio.h>
#include <stdlib.h>
int checkIfPalindrome(int k, char str[], int n);    /* mission 1- check if palindrome           */
void dividorsOf(int number);                        /* mission 2- print divdidors               */
void manyKReverses(int k, char str[], int n);       /* mission 3- reverse array                 */
int isZigZag(int arr[], int arrsize);               /* mission 4- check if zigzag               */
void printAsZigzag(int arr[], int arrsize);         /* mission 5- print as zigzag               */
void checkdiv(int number, int i);                   /* help func for mission 2- check dividors  */
void reverseAllStr(int k, char str[], int n);       /* help func for mission 3- run all strings */
void reverseString(char str[], int start, int end); /* help func for mission 3- reverse string  */
void makeZigzag(int arr[], int arrsize);            /* help func for mission 5- turn to zigzag  */
void swapMinMax(int arr[], int arrsize, int i);     /* help func for mission 5- swap elements   */
void printIntArr(int arr[], int arrsize, int i);    /* help func for mission 5- print int array */

int checkIfPalindrome(int k, char str[], int n) /* mission 1- check if palindrome */
{
    if(k==0) return (str[k]==str[n-1]);
    if (str[k-1]==str[n-k])
        return checkIfPalindrome(k-1, str , n);
    else
        return 0;
}

void dividorsOf(int number) /* mission 2- print dividers */
{
    int i=1;
    printf("Dividers of %d:", number); /* we need to seperate the printf so we use another func */
    checkdiv(number, i);
}

void checkdiv(int number, int i) /* help func for mission 2- check dividors */
{
    if(i==number) /* exit condition */
    {
        printf("%d.\n", i); /* we need '.' at the end */
        return;
    }
    if(number%i==0) /* check and print the dividers */
        printf("%d,", i);
    checkdiv(number, i+1);
}

void manyKReverses(int k, char str[], int n) /* mission 3- reverse array */
{
    reverseAllStr(k, str, n);
    printf("%s\n", str);
}

void reverseAllStr(int k, char str[], int n) /* help func for mission 3- run all strings */ 
{
    if(k>n) return; /* exit condition */
    else
        reverseString(str, 0, k-1); /* send to rveerseString with new start and end */
    reverseAllStr(k, str+1, n-1); 
}

void reverseString(char str[], int start, int end) /* help func for mission 3- reverse string */
{
    char temp;
    if(start>=end) return; /* exit condition */  
    temp=str[start];
    str[start]=str[end];
    str[end]=temp;
    reverseString(str,start+1, end-1);  
}

int isZigZag(int arr[], int arrsize) /* mission 4- check if zigzag */
{
    if(arrsize%2==0) /* arrsize is even */
    {
        /* arr size-2 == 1 */
        if( arrsize < 0 ) return 1; /* exit condition */
        if( arr[arrsize-2]<=arr[arrsize-1] && arr[arrsize-2]<=arr[arrsize-3]) return isZigZag(arr, arrsize-2);
        else return 0;
    }
    else /* arrzise is odd */
    {
        if( arrsize == 1) return 1; /* exit condition */
        if( arr[arrsize-2]>=arr[arrsize-1] && arr[arrsize-2]>=arr[arrsize-3]) return isZigZag(arr, arrsize-2);
        else return 0;        
    } 
}

void printAsZigzag(int arr[], int arrsize) /* mission 5- print as zigzag */
{
    makeZigzag(arr, arrsize);
    printIntArr(arr, arrsize, 0);
}

void makeZigzag(int arr[], int arrsize) /* help func for mission 5- turn to zigzag */
{
   if(arrsize<2) return;
   swapMinMax(arr, arrsize, 1);
   makeZigzag(arr+2, arrsize-2);
} 

void swapMinMax(int arr[], int arrsize, int i) /* help func for mission 5- make 1st % 2nd elements min & max */
{
    int temp;
    if(i==arrsize) return;
    if(arr[0] > arr[i]) /* making the first elemnt min */
    {
        temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
    }
    if(arr[1] < arr[i]) /* make the second element max*/
    {
        temp=arr[1];
        arr[1]=arr[i];
        arr[i]=temp;
    }
    swapMinMax(arr, arrsize, i+1);
}

void printIntArr(int arr[], int arrsize, int i) /* help func for mission 5- print int array */
{
    if(i==arrsize-1)
    {
        printf("%d\n", arr[i] );
        return;
    }
    printf("%d,", arr[i]);
    printIntArr(arr, arrsize, i+1);
}

int main()
{
    int res, iszig;
    int k=-1, n=-1, number=-1, arrsize=-1, i;
    char c;
    char* str;
    int* arr;
    int question;
    printf("Which function should I test for you? ");
    scanf("%d", &question);

    printf("Before proceeding to check the function, please enter the following information:\n");
    printf("[[Note: Only relevant information for the specific function you choose to test will be used]].\n");
    printf("[[For example, if you chose to test function 1, only parameters k, str and n will be checked. all other inputs will be ignored]].\n");
    printf("Enter k:\n");
    scanf("%d", &k);
    printf("Enter string size:\n");
    scanf("%d", &n);
    printf("Enter string:\n");
    str = (char*)malloc((n + 1) * sizeof(char));
    /* read string */
    c = '#';
    i = 0;
    do
    {
        scanf(" %c", &c);
        if (c == '#') c = '\0';
        str[i] = c;
        i++;
    } while(c != '\0');

    printf("Enter number:\n");
    scanf("%d", &number);
    printf("Enter zigzag array size:\n");
    scanf("%d", &arrsize);
    arr = (int*)malloc(arrsize * sizeof(int));
    for(i = 0; i < arrsize; i++)
    {
        scanf("%d", &arr[i]);
    }

    do
    {
        switch(question)
        {
        case 1:
            if (n < 2 || k < 0)
                printf("Skipping.\n");
            else
            {
                res = checkIfPalindrome(k, str, n);
                if (res == 1) printf("Yes, it is a palindrome.\n");
                else printf("No, it is not a palindrome.\n");
            }
            break;
        case 2:
            dividorsOf(number);
            break;
        case 3:
            if (n < 1)
                printf("Skipping.\n");
            manyKReverses(k, str, n);
            break;
        case 4:
            if (arrsize < 0 || arrsize > 1000)
            {
                printf("Skipping.\n");
                break;
            }
            iszig = isZigZag(arr, arrsize);
            if (iszig) printf("zigzag array!\n");
            else printf("NOT zigzag array!\n");
            break;
        case 5:
            if (arrsize < 0 || arrsize > 1000)
            {
                printf("Skipping.\n");
                break;
            }
            printAsZigzag(arr, arrsize);
            break;
        default:
            printf("No choice.\n");
        }
        printf("Which function to check next?");
        scanf("%d", &question);
    } while(question != -1);

    return 0;
}


