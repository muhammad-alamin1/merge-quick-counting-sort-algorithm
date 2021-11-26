#include <stdio.h>

void merge_sort(int A[], int left, int right);
void merge(int A[], int left, int mid, int right);

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
void merge_sort(int A[], int left, int right)
{
    if(left >= right)
        return;

    int mid = left + (right - left) / 2;

    merge_sort(A, left, mid);
    merge_sort(A, mid+1, right);

    merge(A, left, mid, right);
}

// merge
void merge(int A[], int left, int mid, int right)
{
    int i, index_a, index_left, index_right;
    int left_size, right_size;

    left_size = mid - left + 1;
    right_size = right - mid;

    int left_array[left_size];
    int right_array[right_size];

    // copy left array
    for(i = 0; i < left_size; i++)
        left_array[i] = A[left+i];

    // copy right array
    for(i = 0; i < right_size; i++)
        right_array[i] = A[mid+1+i];

    index_left = 0;
    index_right = 0;

    for(index_a = left; index_left < left_size && index_right < right_size; index_a++)
    {
        if(left_array[index_left] < right_array[index_right])
        {
            A[index_a] = left_array[index_left];
            index_left +=1;
        }
        else
        {
            A[index_a] = right_array[index_right];
            index_right +=1;
        }
    }

    // if, left array not marge
    while(index_left < left_size)
    {
        A[index_a] = left_array[index_left];
        index_left += 1;
        index_a += 1;
    }

    // if, right array not marge
    while(index_right < right_size)
    {
        A[index_a] = right_array[index_right];
        index_right += 1;
        index_a += 1;
    }
}
