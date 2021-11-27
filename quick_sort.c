#include <stdio.h>

int partition(int A[], int low, int high);
void quick_sort(int A[], int low, int high);

int main(void)
{
    int i;
    int arr[] = {1, 5, 6, 3, 5, 8, 7, 2, 9};
    int size = (sizeof(arr)/sizeof(arr[0]));

    quick_sort(arr, 0, size);

    for(i = 0; i <= size; i++)
        printf("%d ", arr[i]);

    printf("\n\n");

    return 0;
}

// partition make
int partition(int A[], int low, int high)
{
    int pivot, i, j, temp;

    pivot = A[high];

    for(i = low-1, j = low; j < high; j++)
    {
        if(A[j] < pivot)
        {
            i+=1;
            temp = A[j];
            A[j] = A[i];
            A[i] = temp;
        }
    }

    // Swap A[i+1] and A[high]
    temp = A[high];
    A[high] = A[i+1];
    A[i+1] = temp;

    return i+1;
}

// quick sort
void quick_sort(int A[], int low, int high)
{
    if(low >= high)
        return;

    int pivot_index;

    pivot_index = partition(A, low, high);

    // array A, let's do sort low index to pivot index
    quick_sort(A, low, pivot_index-1);

    // array A, let's do sort pivot index to high index
    quick_sort(A, pivot_index+1, high);
}
