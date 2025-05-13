#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        if (minIdx != i)
        {
            swap(arr[i], arr[minIdx]);
        }
    }
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *left = new int[len1];
    int *right = new int[len2];

    int arrayIdx = s;
    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[arrayIdx];
        arrayIdx++;
    }
    arrayIdx = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[arrayIdx];
        arrayIdx++;
    }

    int leftIdx = 0, rightIdx = 0, mainArrIdx = s;
    while (leftIdx < len1 && rightIdx < len2)
    {
        if (left[leftIdx] < right[rightIdx])
        {
            arr[mainArrIdx++] = left[leftIdx++];
        }
        else
        {
            arr[mainArrIdx++] = right[rightIdx++];
        }
    }

    while (leftIdx < len1)
    {
        arr[mainArrIdx++] = left[leftIdx++];
    }

    while (rightIdx < len2)
    {
        arr[mainArrIdx++] = right[rightIdx++];
    }

    delete[] left;
    delete[] right;
}

void mergeSort(int arr[], int s, int e)
{
    if (s >= e)
        return;

    int mid = s + (e - s) / 2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    merge(arr, s, e);
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

bool binarySearch(int arr[], int n, int size)
{
    int s = 0, e = size - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (arr[mid] == n)
        {
            return true;
        }
        else if (arr[mid] > n)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }

    return false;
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int *arr = new int[n];
    int option = 0;

    while (true)
    {
        cout << "Enter option\n"
             << "1) Input array\n"
             << "2) Insertion Sort\n"
             << "3) Merge Sort\n"
             << "4) Selection Sort\n"
             << "5) Bubble Sort\n"
             << "6) Quick Sort\n"
             << "7) Binary Search\n"
             << "8) Exit\n";
        cin >> option;
        if (option == 1)
        {
            cout << "Enter array elements for array size " << n << endl;
            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }
        }
        else if (option == 2)
        {
            cout << "Performing Insertion Sort\n";
            insertionSort(arr, n);
            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else if (option == 3)
        {
            cout << "Performing Merge Sort\n";
            mergeSort(arr, 0, n - 1);
            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else if (option == 4)
        {
            cout << "Performing Selection Sort\n";
            selectionSort(arr, n);
            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else if (option == 5)
        {
            cout << "Performing Bubble Sort\n";
            bubbleSort(arr, n);
            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else if (option == 6)
        {
            cout << "Performing Quick Sort\n";
            quickSort(arr, 0, n - 1);
            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else if (option == 7)
        {
            mergeSort(arr, 0, n - 1);
            int ele;
            cout << "Enter element to search: ";
            cin >> ele;
            if (binarySearch(arr, ele, n))
                cout << "Found\n";
            else
                cout << "Not Found\n";
        }
        else if (option == 8)
        {
            cout << "Exiting...\n";
            break;
        }
        else
        {
            cout << "Invalid option!\n";
        }
    }

    delete[] arr;
    return 0;
}

/*
    Insertion Sort = TC - Best: O(n), Average: O(n^2), Worst: O(n^2)
                     SC - O(1)

    Selection Sort = TC - Best: O(n^2), Average: O(n^2), Worst: O(n^2)
                     SC - O(1)

    Bubble Sort = TC - Best: O(n), Average: O(n^2), Worst: O(n^2)
                  SC - O(1)

    Merge Sort = TC - Best: O(n log n), Average: O(n log n), Worst: O(n log n)
                 SC - O(n)

    Quick Sort = TC - Best: O(n log n), Average: O(n log n), Worst: O(n^2)
                 SC - O(log n) (due to recursion stack)

    Binary Search = TC - Best: O(1), Average: O(log n), Worst: O(log n)
                    SC - O(1)
*/

/*
    Sorting and Searching Examples:

    Example 1:
    Input:
    Enter size of array: 5
    Enter option: 1
    Enter array elements: 5 3 8 6 2
    Enter option: 2

    Output:
    Performing Insertion Sort
    2 3 5 6 8

    Example 2:
    Input:
    Enter size of array: 5
    Enter option: 1
    Enter array elements: 5 3 8 6 2
    Enter option: 7
    Enter element to search: 6

    Output:
    Found

    Example 3:
    Input:
    Enter size of array: 5
    Enter option: 1
    Enter array elements: 5 3 8 6 2
    Enter option: 6

    Output:
    Performing Quick Sort
    2 3 5 6 8
*/