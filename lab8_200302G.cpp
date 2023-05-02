#include <iostream>
#include <chrono>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int count, int root)
{
    // set the maximum as the root
    int Maximum = root;
    int left_node = 2 * root + 1;
    int right_node = 2 * root + 2;

    // check left child < maximum
    if (left_node < count && arr[left_node] > arr[Maximum])
        Maximum = left_node;

    // check right child < maximum
    if (right_node < count && arr[right_node] > arr[Maximum])
        Maximum = right_node;

    // check if largest not equal to root
    if (Maximum != root) {
        swap(arr[root], arr[Maximum]);

        heapify(arr, count, Maximum);
    }
}

// algorithm of the heap sort
void heapSort(int arr[], int n)
{
    // Build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extracting elements from heap one by one
    for (int i = n - 1; i > 0; i--) {

        swap(arr[0], arr[i]); // swaping

        heapify(arr, i, 0);
    }
}

/* print contents of array */
void displayArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// main program
int main()
{
    int num; // code to get elements from the user
    cout << "Array size: ";
    cin >> num;

    int heap_arr[num];
    cout << "Enter elements: ";
    for (int i = 0; i < num; i++) {
        cin >> heap_arr[i];
    }
    int n = sizeof(heap_arr)/sizeof(heap_arr[0]);

    auto start = chrono::high_resolution_clock::now(); // get the start time

    heapSort(heap_arr, n);

    auto end = chrono::high_resolution_clock::now(); // get the end time
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start); // calculate the duration in microseconds

    cout << "Sorted array: ";
    displayArray(heap_arr, n);

    cout << duration.count() << " microseconds" << endl; // print the execution time
}