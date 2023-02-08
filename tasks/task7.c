#include <stdio.h>
#include <stdlib.h>

typedef struct cellNode {
    int cell;
    struct cellNode* next;
} Node;

typedef struct {
    int numRows;
    int numColumns;
    Node** rows; /* pointer, will be used as a 1D array of size numRows.*/
} Matrix;

/* declarations */
int firstOccurence(int arr[], int n, int num); /* first func */
void MultiplyMatrices(Matrix* A, Matrix* B, Matrix* C); /* second func */
int fib_value(int n); /* third func */
void printmatrix(Matrix* A,int row, int col); /* print the matrix */
Matrix* createMatrix(int row, int col); /* create matrix */
void insert(Matrix* A, int row, int col); /* insert values to the matrix */
void freeAll(Matrix* A); /* free all memory */

int main()
{
    int num, temp ,n,i,*arr, m, k;
    Matrix *A, *B, *C;
    printf("Please choose function (1 or 2 or 3): ");
    if(scanf("%d", &num)!=1) return 0;
    if(num==1)
    {
        printf("Enter num: ");
        if(scanf("%d", &num)!=1) return 0;
        printf("Enter n: ");
        if(scanf("%d", &n)!=1) return 0;
        arr=(int*)malloc(n*sizeof(int));
        if(arr==NULL) return 0;
        for(i=0;i<n;i++)
        {
            if(scanf("%d", &temp)!=1) return 0;
            arr[i]=temp;
        }
        (firstOccurence(arr,n,num)!=-1) ? printf("Found at: %d.", firstOccurence(arr,n,num)) : printf("Does not exist."); 
        free(arr); /* free memory */
        return 0;
    }
    if(num==2)
    {
        printf("Please enter n: ");
        if(scanf("%d", &n)!=1) return 0;
        printf("Please enter m: ");
        if(scanf("%d", &m)!=1) return 0;
        printf("Please enter k: ");
        if(scanf("%d", &k)!=1) return 0;
        A=createMatrix(n,m);
        B=createMatrix(m,k);
        C=createMatrix(n,k);
        printf("Please insert values for matrix A:\n"); /* insert matrix A */
        insert(A,n,m);
        printf("Please insert values for matrix B:\n"); /* insert matrix B */
        insert(B,m,k);
        printf("Matrix A:\n"); /* print matrix A */
        printmatrix(A,n,m);
        printf("Matrix B:\n"); /* print matrix B */
        printmatrix(B,m,k);
        MultiplyMatrices(A,B,C);
        printf("Matrix C:\n"); /* print matrix C */
        printmatrix(C,n,k);
        freeAll(A);
        freeAll(B);
        freeAll(C);
    return 0;
    }
    if(num==3)
    {
        printf("Please enter fib index:\n");
        if(scanf("%d", &num)!=1) return 0;
        printf("The fib value is: %d",fib_value(num));
    }
    return 0;
}

int firstOccurence(int arr[], int n, int num) /* first func */
{
    int high=n-1, low=0, mid, temp=-1;
    while(low<=high)
    {
        mid=(high+low)/2;
        if(arr[mid]==num)
        {
            temp=mid;
            high=mid-1; 
        }
        else if(arr[mid]>num) high= mid-1;
        else low=mid+1;
    }
    return temp; 
}

void MultiplyMatrices(Matrix* A,Matrix* B,Matrix* C)
{
    int i,m,n,k,sum=0; 
    Node *tempA,*tempB,*tempC; /* help pointers */
    for(n=0;n<(A->numRows);n++) /* loop for A rows */
    {
        tempA=A->rows[n];
        for(k=0;k<(B->numColumns);k++) /* index loop to get to the right col */
        {
            for(m=0;m<(B->numRows);m++)   /* loop runs over B rows */
            {
                tempB=B->rows[m];
                for(i=0;i<k;i++) /* get to the right col*/
                {
                    tempB=tempB->next;
                }
                sum+=(tempA->cell)*(tempB->cell);
                tempA=tempA->next;   /* run over A col */
            }
            tempC=C->rows[n];  
            for(i=0;i<k;i++)  /* get to the right col */
            {
                tempC=tempC->next;
            }
            tempC->cell=sum;  /* insert sum to c */
            sum=0; /* reset the sum for next row */
            tempA=A->rows[n]; 
        }
    }
}

int fib_value(int n) /* third func */
{
    int i;
    Matrix *A=createMatrix(2,2), *B=createMatrix(2,2),*C=createMatrix(2,2);;
    if(n==0) return 0; /* base cases */
    if(n==1 || n==2 ) return 1;
    A->rows[0]->cell = 2;  /* making A and B like the example */
    A->rows[0]->next->cell = 1;
    A->rows[1]->cell = 1;
    A->rows[1]->next->cell = 1;
    B->rows[0]->cell = 2;
    B->rows[0]->next->cell = 1;
    B->rows[1]->cell = 1;
    B->rows[1]->next->cell = 1;

    while(n>2) /* sizing down n */ 
    {
            MultiplyMatrices(A,B,C);
            A->rows[0]->cell=C->rows[0]->cell;  /* making A=C */
            A->rows[0]->next->cell=C->rows[0]->next->cell;
            A->rows[1]->cell=C->rows[1]->cell;
            A->rows[1]->next->cell=C->rows[1]->next->cell;
            B->rows[0]->cell=C->rows[0]->cell;  /* making B=C */
            B->rows[0]->next->cell=C->rows[0]->next->cell;
            B->rows[1]->cell=C->rows[1]->cell;
            B->rows[1]->next->cell=C->rows[1]->next->cell;
            n/=2;
    }
    i= C->rows[0]->next->cell;
    freeAll(A);
    freeAll(B);
    freeAll(C);
    return i;
}

Matrix* createMatrix(int row, int col) /* create matrix */
{
    int i,j;
    Node* p;
    Matrix* A=(Matrix*)malloc(sizeof(Matrix)); /* create matrix */
        if(A==NULL) 
        {
            printf("Memory error!");
            return NULL;
        }
        A->numRows=row;
        A->numColumns=col;
        if((A->rows=(Node**)malloc(row*sizeof(Node*)))==NULL)  /* memory for the rows*/
        {
            printf("Memory error!");
            free(A);
            return NULL;
        }          
        for(i=0;i<row;i++) /* memory for each cell in each row */
        {
            if((p=A->rows[i]=(Node*)malloc(sizeof(Node)))==NULL)
            {
                printf("Memory error!"); 
                freeAll(A); /* need to free all memory */
                return NULL;
            }
            for(j=0;j<col;j++)
            {
                if((p->next=(Node*)malloc(sizeof(Node)))==NULL)
                {
                    printf("Memory error!");
                    freeAll(A);  /* need to free all memory*/
                    return 0;  
                }
                p=p->next;   
            }
            p->next=NULL;     /* last node in the row points to null */  
        }
    return A;
}

void insert(Matrix* A, int row, int col) /* insert values to the matrix */
{
    int i,j,num;
    Node* p;
    for(i=0;i<row;i++)
        {
            p=A->rows[i];
            printf("Enter row %d data\n", i);
            for(j=0;j<col;j++)
            {
                if(scanf("%d", &num)!=1) return;
                p->cell=num;
                p=p->next;
            }
        }
}

void printmatrix(Matrix* A,int row, int col) /* print the matrix */
{
    int i,j;
    Node* p;
    for(i=0;i<row;i++)
    {
        p=A->rows[i];
        printf("[%d, ", p->cell);
        p=p->next;
        for(j=1;j<col;j++)
        {
            if(j==col-1) printf("%d", p->cell);   /* these if statments and "j=1" choice is only to print it like the tests show */
            else printf("%d, ",p->cell);
            p=p->next;
        }
        printf("]\n");
    }
}

void freeAll(Matrix* A) /* free all memory */
{
    int i;
    Node* current;
    Node* next;
    for (i=0; i<A->numRows; i++) 
    {
        current=A->rows[i];
        while(current != NULL) {
            next=current->next;
            free(current);
            current=next;
        }
    }
    free(A->rows);
    free(A);
}
