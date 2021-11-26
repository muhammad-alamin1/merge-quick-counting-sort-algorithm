#include <iostream>

using namespace std;

class Merge
{
public:
    void merge_sort(int A[], int left, int right);
    void merge(int A[], int left, int mid, int right);
};

int main(void)
{
    Merge merge_sort_algo;

    int A[] = {1, 5, 6, 3, 5, 8, 7, 2, 9};
    int size = (sizeof(A)/sizeof(A[0]));

    merge_sort_algo.merge_sort(A, 0, size);

    for(int i = 0; i <= size; i++)
    {
        cout << A[i] << " ";
    }
    cout << "\n\n";

    return 0;
}

// merge sort
void Merge::merge_sort(int A[], int left, int right)
{
    if(left >= right)
        return;

    int mid = left + (right - left) / 2;

    merge_sort(A, left, mid);
    merge_sort(A, mid+1, right);

    merge(A, left, mid, right);
}

// merge
void Merge::merge(int A[], int left, int mid, int right)
{
    int i, index_a, index_left, index_right;
    int size_left, size_right;

    size_left = mid - left + 1;
    size_right = right - mid;

    int left_array[size_left];
    int right_array[size_right];

    for(i = 0; i < size_left; i++)
        left_array[i] = A[left+i];

    for(i = 0; i < size_right; i++)
        right_array[i] = A[mid+1+i];

    index_left = 0;
    index_right = 0;

    for(index_a = left; index_left < size_left && index_right < size_right; index_a++)
    {
        if(left_array[index_left] < right_array[index_right])
        {
            A[index_a] = left_array[index_left];
            index_left++;
        }
        else
        {
            A[index_a] = right_array[index_right];
            index_right++;
        }
    }

    while(index_left < size_left)
    {
        A[index_a] = left_array[index_left];
        index_left++;
        index_a++;
    }

    while(index_right < size_right)
    {
        A[index_a] = right_array[index_right];
        index_right++;
        index_a++;
    }
}
