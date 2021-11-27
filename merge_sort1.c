#include <stdio.h>

void merge_sort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

int main(void)
{
    int A[] = {1, 5, 6, 3, 5, 8, 7, 2, 9};
    int size = (sizeof(A)/sizeof(A[0]));

    merge_sort(A, 0, size);

    for(int i = 0; i <= size; i++)
        printf("%d ", A[i]);

    printf("\n\n");

    return 0;
}

// merge sort
void merge_sort(int arr[], int left, int right)
{
    if(left >= right)
        return;

    int mid = left + (right - left) / 2;

    merge_sort(arr, left, mid);
    merge_sort(arr, mid+1, right);

    merge(arr, left, mid, right);
}

// merge
void merge(int arr[], int left, int mid, int right)
{
    int i, index_a, index_left, index_right;
    int left_size, right_size;

    left_size = mid - left +1;
    right_size = right - mid;

    int left_array[left_size];
    int right_array[right_size];

    for(i = 0; i < left_size; i++)
        left_array[i] = arr[left+i];

    for(i = 0; i < right_size; i++)
        right_array[i] = arr[mid+1+i];

    index_left = 0;
    index_right = 0;

    for(index_a = left; index_left < left_size && index_right < right_size; index_a++)
    {
        if(left_array[index_left] < right_array[index_right])
        {
            arr[index_a] = left_array[index_left];
            index_left++;
        }
        else
        {
            arr[index_a] = right_array[index_right];
            index_right++;
        }
    }


    while(index_left < left_size)
    {
        arr[index_a] = left_array[index_left];
        index_left++;
        index_a++;
    }

    while(index_right < right_size)
    {
        arr[index_a] = right_array[index_right];
        index_right++;
        index_a++;
    }
}
