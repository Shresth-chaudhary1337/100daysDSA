/*Implement Heap Sort using a Max Heap to sort an array in ascending order. 
First build a max heap, then repeatedly extract the maximum element and place it at the end of the array.*/
#include <iostream>
using namespace std;

// This function fixes the heap if the root is not the largest
// It compares parent with its children and swaps if needed
void heapify(int arr[], int n, int i)
{
    int largest = i;        // assume current index is largest
    int left = 2*i + 1;     // left child index
    int right = 2*i + 2;    // right child index

    // check if left child is bigger than parent
    if(left < n && arr[left] > arr[largest])
        largest = left;

    // check if right child is bigger than the current largest
    if(right < n && arr[right] > arr[largest])
        largest = right;

    // if largest element is not the parent, swap them
    if(largest != i)
    {
        swap(arr[i], arr[largest]);

        // after swap we check the subtree again
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n)
{
    // Step 1: Build the max heap from the array
    // we start from the last non-leaf node
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Step 2: Take the largest element (root)
    // and move it to the end of the array
    for(int i = n-1; i > 0; i--)
    {
        swap(arr[0], arr[i]);   // put max element at correct position

        // reduce heap size and fix heap again
        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    // calling heap sort function
    heapSort(arr, n);

    cout << "Sorted array: ";

    // printing sorted array
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}